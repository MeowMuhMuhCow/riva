import hashlib
import json
from pathlib import Path
import omf


def verified_objects(m, manifest):
    m = Path(m)
    path = m / manifest
    if not path.exists():
        return {}
    result = {}
    cache = {}
    sources = {}
    for proof in json.loads(path.read_text()):
        name = proof["name"]
        raw = (m / (name + ".OBJ")).read_bytes()
        if hashlib.sha256(raw).hexdigest() != proof["sha256"]:
            raise ValueError("Gruppenobjekt ungeprueft: " + name)
        module = omf.modules(str(m / (name + ".OBJ")))[0]
        bodies = [s for s in module["segs"].values() if s["cls"] == "CODE" and len(s["data"])]
        if len(bodies) != 1:
            raise ValueError("Gruppenobjekt ohne eindeutigen CODE")
        body = bodies[0]
        lo, hi = proof["lo"], proof["hi"]
        if len(body["data"]) != hi - lo:
            raise ValueError("Gruppenlaenge geaendert")
        spans = []
        cursor = lo
        for s in proof["spans"]:
            a, b = s["address"], s["hi"]
            data = bytes(body["data"][a - lo : b - lo])
            if a != cursor or b <= a:
                raise ValueError("Gruppenherkunft mit Luecke/Overlap")
            cursor = b
            if hashlib.sha256(data).hexdigest() != s["payload_sha256"]:
                raise ValueError("Gruppen-Nutzbytes geaendert")
            if s["cpp"]:
                source = Path(s.get("saved_source", s["source"]))
                source = source if source.is_absolute() else m / source
                if source not in sources:
                    sources[source] = hashlib.sha256(source.read_bytes()).hexdigest()
                if sources[source] != s["source_sha256"]:
                    raise ValueError("C++-Quellbeleg geaendert: " + str(source))
                obj = Path(s.get("saved_raw", s["raw"]))
                obj = obj if obj.is_absolute() else m / obj
                if obj not in cache:
                    raw_native = obj.read_bytes()
                    native_source = raw_native[4 : 4 + raw_native[3]].decode("latin1")
                    if not native_source.upper().endswith((".CPP", ".C")):
                        raise ValueError("Compilerbeleg hat keine C/C++-Herkunft")
                    cache[obj] = (hashlib.sha256(raw_native).hexdigest(), omf.modules(str(obj))[0])
                digest, native = cache[obj]
                if digest != s["raw_sha256"]:
                    raise ValueError("Compilerobjekt-Beleg geaendert")
                part = s["part"]
                owner = part["owner"]
                original = (
                    native["segs"][owner[1]]
                    if owner[0] == "seg"
                    else next(c for c in native["comdats"] if c["name"] == owner[1])
                )
                if data != bytes(original["data"][part["offset"] : part["end"]]):
                    raise ValueError("Nutzbytes stammen nicht unveraendert aus Compilerbeitrag")
            elif s.get("saved_asm_raw"):
                obj = m / s["saved_asm_raw"]
                if obj not in cache:
                    cache[obj] = (hashlib.sha256(obj.read_bytes()).hexdigest(), omf.modules(str(obj))[0])
                digest, native = cache[obj]
                if digest != s["raw_sha256"]:
                    raise ValueError("Erhaltenes ASM-Objekt geaendert")
                original = native["segs"][s["asm_segment"]]
                off = s["asm_offset"]
                if data != bytes(original["data"][off : off + b - a]):
                    raise ValueError("Erhaltener ASM-Beitrag nicht aus dem belegten WASM-Objekt")
            spans.append(
                dict(
                    module=name,
                    lo=a,
                    hi=b,
                    cpp=s["cpp"],
                    source=s["source"],
                    pad=False,
                    partial_link=True,
                )
            )
        if cursor != hi:
            raise ValueError("Gruppenherkunft unvollstaendig")
        result[name] = dict(lo=lo, hi=hi, spans=spans)
    return result


def groups(m):
    return verified_objects(m, "D22_GROUPS.json")


def fragments(m):
    result = verified_objects(m, "D22_FRAGMENTS.json")
    if any(not s["cpp"] for p in result.values() for s in p["spans"]):
        raise ValueError("C++-Fragment enthaelt unbelegte ASM-Anteile")
    return result
