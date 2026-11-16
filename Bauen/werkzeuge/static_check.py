import collections
import json
from pathlib import Path
import re
import omf
import omf_extra
import r3_reloc
from object_meta import prune
from data_bind import bind as bind_data
from omf_comdat import LIB as lib

MAP = {}
LE = r3_reloc.Fixups()
IMAGE = bytearray()
MAP_MODULE = {}
ORIGINAL_PUBLICS = set()
ANCHORS = []
FUNKTIONEN_STARTS = set()
TEILE_ALLE_LINES = []
ORIG_EXE_BYTES = bytearray()


def init_context(meta_dir, orig_exe_path):
    meta_dir = Path(meta_dir)
    mp, le, img, _ = r3_reloc.load_context(meta_dir, orig_exe_path)
    MAP.clear()
    MAP.update(mp)
    LE.clear()
    LE.update(le)
    LE.freeze()
    IMAGE[:] = img
    ORIG_EXE_BYTES[:] = Path(orig_exe_path).read_bytes()

    mm = json.loads((meta_dir / "map_module.json").read_text(encoding="utf-8"))
    MAP_MODULE.clear()
    MAP_MODULE.update(mm)

    ORIGINAL_PUBLICS.clear()
    ORIGINAL_PUBLICS.update(
        address
        for module in MAP_MODULE.values()
        for actual, address in module["pub"]
        if actual == address
    )

    ANCHORS.clear()
    for line in (meta_dir / "asm_verbucht.tsv").read_text(encoding="latin1").splitlines():
        t = line.split("\t")
        if len(t) >= 3 and re.fullmatch("[0-9A-Fa-f]{6}", t[0]):
            ANCHORS.append((int(t[0], 16), int(t[1], 16)))

    FUNKTIONEN_STARTS.clear()
    for l in (meta_dir / "funktionen.tsv").read_text(encoding="latin1").splitlines():
        if re.match(r"^[0-9a-fA-F]{6}\t", l):
            FUNKTIONEN_STARTS.add(int(l[:6], 16))

    TEILE_ALLE_LINES.clear()
    TEILE_ALLE_LINES.extend((meta_dir / "teile_alle.tsv").read_text(encoding="utf-8").splitlines())


def explicit(name):
    patterns = [
        r"^L([0-9A-Fa-f]{6})$",
        r"^W\?[fdv]_([0-9a-fA-F]{6})(?:_k\d+|[A-Za-z][A-Za-z0-9_]*)?(?=\$|$)",
        r"^_?[fdv]_([0-9a-fA-F]{6})(?:[A-Za-z][A-Za-z0-9]*)?_?$",
        r"^W\?\$(?:ct|dt):[fdv]_([0-9a-fA-F]{6})\$",
    ]
    for pattern in patterns:
        m = re.match(pattern, name)
        if m:
            return int(m[1], 16)
    return None


def analyse(row):
    if row.get("error"):
        return row
    work = Path(row["work"])
    raw = work / "raw.OBJ"
    clean = work / "clean.OBJ"
    lo, hi = row["lo"], row["hi"]
    ren = {k: "L%06X" % v for k, v in MAP.items()}
    lib["clean_comdats"](raw, clean, ren)
    info = lib["scan"](clean)
    model = omf.modules(str(clean))[0]
    code, data, dropped = lib["comdat_selection"](info, ren)
    row["code_comdat"] = sorted(code)
    row["data_comdat"] = sorted(data)
    row["data_segments"] = [
        (i, s["name"], len(s["data"]))
        for i, s in model["segs"].items()
        if s["cls"] != "CODE" and len(s["data"])
    ]
    owners = {}
    segments = {}
    active = [(i, s) for i, s in model["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
    if len(active) > 1:
        row["error"] = "Mehrere aktive Codesegmente"
        return row
    if code:
        _, blocks = lib["layout"](clean, lo)
        for b in blocks:
            if b["kind"] == "TEXT":
                key = (
                    "seg",
                    next(
                        i
                        for i, s in model["segs"].items()
                        if s["cls"] == "CODE" and s["name"] == b["name"]
                    ),
                )
            elif b["kind"] == "COMDAT":
                key = ("comdat", b["name"])
            else:
                continue
            owners[key] = (b["address"], b)
        end = blocks[-1]["address"] + len(blocks[-1]["data"])
    elif active:
        i, s = active[0]
        owners[("seg", i)] = (lo, s)
        end = lo + len(s["data"])
    else:
        row["error"] = "Kein Code"
        return row
    for key, (base, body) in owners.items():
        if key[0] == "seg":
            segments[body["name"]] = base
    row["code_end"] = end
    if end > hi:
        row["error"] = "Code laenger als heutige Einheit: %06X > %06X" % (end, hi)
        return row
    byte_errors = []
    for key, (base, body) in owners.items():
        for i, value in enumerate(body["data"]):
            if not body["mask"][i] and IMAGE[base - 0x10000 + i] != value:
                byte_errors.append((base + i, IMAGE[base - 0x10000 + i], value))
    row["unmasked_count"] = len(byte_errors)
    row["unmasked_first"] = byte_errors[:20]
    if byte_errors:
        row["error"] = "Unmaskierte Modulbytes abweichend: %d, zuerst %06X" % (
            len(byte_errors),
            byte_errors[0][0],
        )
        return row
    fx = omf_extra.fixups(clean.read_bytes())
    inferred = collections.defaultdict(set)
    expected = []
    unresolved = []
    for f in fx:
        owner = tuple(f["owner"])
        if owner not in owners:
            continue
        base, body = owners[owner]
        at = base + f["offset"]
        size = f["width"]
        if size != 4 or f["location"] not in (9, 13):
            unresolved.append("Fixuptyp %s bei %06X" % (f["location"], at))
            continue
        add = (
            int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little")
            + f["displacement"]
        ) & 0xFFFFFFFF
        if f["relative"]:
            want = (
                at
                + 4
                + int.from_bytes(IMAGE[at - 0x10000 : at - 0x10000 + 4], "little", signed=True)
            ) & 0xFFFFFFFF
        elif at in LE:
            typ, want = LE[at]
            if typ != 7:
                unresolved.append("Originalfixuptyp %d bei %06X" % (typ, at))
        else:
            unresolved.append("Absoluter Fixup ohne Originalrelokation bei %06X" % at)
            continue
        target = f["target"]
        if target[0] == "external":
            inferred[target[1]].add((want - add) & 0xFFFFFFFF)
        expected.append((at, f, add, want))
    errors = []
    for name, values in inferred.items():
        known = explicit(name)
        if len(values) != 1:
            errors.append(
                "Symbol %s hat verschiedene Originalziele %s"
                % (name, ",".join("%06X" % v for v in sorted(values)))
            )
        elif known is not None and known not in values:
            errors.append(
                "Symbol %s: deklarierte/zugeordnete Adresse %06X, Original %06X"
                % (name, known, next(iter(values)))
            )
        else:
            if known is None and name in MAP and MAP[name] not in values:
                row.setdefault("context_map_overrides", {})[name] = dict(
                    old=MAP[name], new=next(iter(values))
                )
            ren[name] = "L%06X" % next(iter(values))
    meta = r3_reloc.parse(clean)
    for name in (
        set(meta["ext"][1:])
        | {p[2] for p in meta["pubs"]}
        | {c["name"] for c in info["comdats"]}
    ):
        address = explicit(name)
        if address is not None:
            ren[name] = "L%06X" % address
    for owner, (address, body) in owners.items():
        if owner[0] != "comdat":
            continue
        name = owner[1]
        known = explicit(name)
        if known is not None and known != address:
            errors.append("Code-COMDAT %s steht bei %06X statt %06X" % (name, address, known))
        elif name not in ren and address in ORIGINAL_PUBLICS:
            ren[name] = "L%06X" % address
            row.setdefault("original_comdat_names", {})[name] = address
    for sid, off, name in meta["pubs"]:
        address = explicit(name)
        if address is not None and ("seg", sid) in owners and owners[("seg", sid)][0] + off != address:
            errors.append(
                "Public %s steht bei %06X statt %06X" % (name, owners[("seg", sid)][0] + off, address)
            )
    checks = []
    for at, f, add, want in expected:
        target = f["target"]
        got = None
        if target[0] == "external" and target[1] in ren:
            got = (int(ren[target[1]][1:], 16) + add) & 0xFFFFFFFF
        elif target[0] == "segment" and target[1][0] in segments:
            got = (segments[target[1][0]] + add) & 0xFFFFFFFF
        if got is None:
            unresolved.append("Unaufgeloestes Ziel %s bei %06X" % (target, at))
        elif got != want:
            errors.append("Relokation %06X: %06X statt %06X (%s)" % (at, got, want, target))
        checks.append(
            dict(
                address=at,
                target=target,
                addend=add,
                original=want,
                new=got,
                relative=f["relative"],
            )
        )
    row["inferred_names"] = {
        k: sorted(v) for k, v in inferred.items() if explicit(k) is None and k not in MAP
    }
    row["relocation_errors"] = errors
    row["unresolved"] = unresolved
    (work / "relocations.json").write_text(json.dumps(checks, indent=2))
    (work / "names.json").write_text(json.dumps(ren, indent=2))
    (work / "names.map").write_text(
        "".join(k + "=" + v + "\n" for k, v in sorted(ren.items())), encoding="latin1"
    )
    if errors:
        row["error"] = errors[0]
        return row
    if row["data_segments"]:
        try:
            bound = work / "data_bound.OBJ"
            row["data_binding"] = bind_data(clean, bound, ren, IMAGE, LE, lib)
            clean = bound
        except ValueError as exc:
            row["error"] = "Daten/DGROUP: " + str(exc)
            return row
    if unresolved:
        row["error"] = unresolved[0]
        return row
    out = work / "link.OBJ"
    lib["prepare"](clean, out, ren)
    row["unused_external_names_removed"] = prune(out, out)
    if lo % 16 or any(
        s["name"] in ("_TEXT1", "_TEXT2", "_TEXT3")
        for s in model["segs"].values()
        if s["cls"] == "CODE"
    ):
        lib["align1"](out)
    row["prepared"] = str(out)
    return row
