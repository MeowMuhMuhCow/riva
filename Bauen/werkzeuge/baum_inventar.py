import hashlib
from pathlib import Path
from group_inventory import groups, fragments
from order_audit import layout as compute_layout
from static_check import ANCHORS, FUNKTIONEN_STARTS, IMAGE, ORIG_EXE_BYTES, TEILE_ALLE_LINES
from x86_disasm import padding

GOOD = "fb8f5fc3ba5454c7344c17aaf362de35"


def inventory(m):
    m = Path(m).resolve()
    files = [l[5:-4] for l in (m / "RIVA.LNK").read_text().splitlines() if l.startswith("file ")]
    lay = compute_layout(m)
    provenance = {}
    for n in lay:
        raw = (m / (n + ".OBJ")).read_bytes()
        source = raw[4 : 4 + raw[3]].decode("latin1")
        cpp = not (m / (n + ".ASM")).exists() and source.upper().endswith((".CPP", ".C"))
        provenance[n] = dict(source=source, cpp=cpp, pad=False)
    grouped = groups(m)
    native = fragments(m)
    for n, p in provenance.items():
        if p["cpp"] and n.startswith("N") and len(n) == 7 and n not in native:
            raise ValueError("Nativer Fragmentnachweis fehlt: " + n)
    for n, g in native.items():
        if lay.get(n) != (g["lo"], g["hi"]):
            raise ValueError("Fragmentlage stimmt nicht: " + n)
    for n, g in grouped.items():
        if lay.get(n) != (g["lo"], g["hi"]):
            raise ValueError("Gruppenlage stimmt nicht: " + n)
    rows = []
    for line in TEILE_ALLE_LINES:
        t = line.split("\t")
        if len(t) < 4:
            continue
        unit, lo, hi = t[1], int(t[2], 16), int(t[3], 16)
        spans = []
        cursor = lo
        for name, (a, b) in sorted(lay.items(), key=lambda r: r[1][0]):
            if a >= hi or b <= lo or a == b:
                continue
            a, b = max(lo, a), min(hi, b)
            if a > cursor:
                spans.append(dict(module="Linkerausrichtung", lo=cursor, hi=a, cpp=False))
            spans.append(dict(module=name, lo=a, hi=b, **provenance[name]))
            cursor = max(cursor, b)
        if cursor < hi:
            spans.append(dict(module="Nicht abgedeckt", lo=cursor, hi=hi, cpp=False))
        detailed = []
        for span in spans:
            parts = grouped.get(span["module"], {}).get("spans", [span])
            for part in parts:
                a, b = max(part["lo"], span["lo"]), min(part["hi"], span["hi"])
                if a >= b:
                    continue
                cuts = sorted({a, b} | {v for pair in ANCHORS for v in pair if a < v < b})
                for x, y in zip(cuts, cuts[1:]):
                    detailed.append(
                        dict(part, lo=x, hi=y, anchor_piece=any(aa <= x < y <= bb for aa, bb in ANCHORS))
                    )
        spans = detailed
        for s in spans:
            s["padding"] = (
                not s["cpp"]
                and not any(s["lo"] <= a < s["hi"] for a in FUNKTIONEN_STARTS)
                and padding(bytes(IMAGE[s["lo"] - 0x10000 : s["hi"] - 0x10000]))
            )
        i = 0
        while i < len(spans):
            if spans[i]["cpp"]:
                i += 1
                continue
            j = i + 1
            while (
                j < len(spans)
                and not spans[j]["cpp"]
                and spans[j - 1]["hi"] == spans[j]["lo"]
                and spans[j]["anchor_piece"] == spans[i]["anchor_piece"]
            ):
                j += 1
            a, b = spans[i]["lo"], spans[j - 1]["hi"]
            if not any(a <= x < b for x in FUNKTIONEN_STARTS) and padding(
                bytes(IMAGE[a - 0x10000 : b - 0x10000])
            ):
                for s in spans[i:j]:
                    s["padding"] = True
            i = j
        cpp = sorted({s["module"] for s in spans if s["cpp"]})
        rest = [s for s in spans if not s["cpp"] and not s["padding"] and not s.get("anchor_piece")]
        anchor = sum(max(0, min(b, hi) - max(a, lo)) for a, b in ANCHORS) / max(1, hi - lo) >= 0.9
        rows.append(
            dict(
                unit=unit,
                lo=lo,
                hi=hi,
                anchor=anchor,
                covered_without_fill=bool(cpp) and not rest,
                cpp_modules=cpp,
                pad_modules=[n for n in cpp if provenance[n]["pad"]],
                noncpp_without_fill=[s["module"] for s in rest],
                spans=spans,
            )
        )
    md5 = hashlib.md5(bytes(ORIG_EXE_BYTES[:0x38D64]) + (m / "RIVA.EXE").read_bytes()).hexdigest()
    return dict(
        md5=md5,
        good=(md5 == GOOD),
        modules=len(files),
        cpp_objects=sum(v["cpp"] for v in provenance.values()),
        mixed_objects=len(grouped),
        fragment_objects=len(native),
        coverage_rule="Original-HandASM-Intervalle und reine Endfuellung ausgenommen; CPP-Herkunft pro Bereich verifiziert",
        units=rows,
    )
