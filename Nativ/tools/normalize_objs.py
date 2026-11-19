#!/usr/bin/env python3
"""
normalize_objs.py - Normalisiert die COFF-Symboltabellen aller uebersetzten Einheiten (.o),
sodass C++-gemangelte Funktions- und Datensymbole (__Z...f_xxxxxx..., __Z...d_xxxxxx...),
Watcom-#pragma-aux-Aliase sowie Konstruktor-/Methoden-Rekonstruktionsnamen (aus extra.map,
EXTRA_MAP_NEU.txt und lokalen Hilfsklassen) auf die kanonischen C-Symbole (_f_xxxxxx, _d_xxxxxx)
abgebildet werden. Erzeugt ausserdem Port/build/generated/dtor_wrappers.inc fuer C++-Destruktoren
und noch nicht rekonstruierte Assembler-Stubs (Smacker/BRender-3D).
"""

import json
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
PORT_DIR = HERE.parent

# Explizite Konstruktor-/Methoden-/Helfer-Zuordnungen fuer lokale Rekonstruktionsklassen
EXPLICIT_GCC_TO_TARGET = {
    # Globale Operatoren & Markierung
    "__Z4markPKci": "_f_014b10",
    "__Z7f_14b10PKci": "_f_014b10",
    "__ZnwjPv": "_f_014ab0",
    "__ZnajPv": "_f_014ac0",
    "__Z7f_14ac0ii": "_f_014ac0",
    "__Znwj": "_f_014ad0",
    "__Znaj": "_f_014ad0",
    "__ZdlPv": "_f_014710",
    "__ZdaPv": "_f_014710",
    "__ZdlPvj": "_f_014710",
    "__ZdaPvj": "_f_014710",
    # Gemeinsame Header-Klassen (RIVAIMG.H, RIVACTX.H, RIVAITEM.H)
    "__ZN15RivaRasterImageC1Ev": "_f_0fabf0",
    "__ZN15RivaRasterImageC1Ess": "_f_0fac80",
    "__ZN15RivaRasterImageC2Ess": "_f_0fac80",
    "__ZN15RivaRasterImageC1EssPv": "_f_0fac10",
    "__ZN12ContextAMap415RivaRasterImageC1EssPh": "_f_0fac10",
    "__ZN15RivaTextContextC1EPKvS1_S1_": "_f_125400",
    "__ZN18RivaItemDefinitionC1Ev": "_f_01e100",
    # Lokale Rekonstruktions-Konstruktoren und -Methoden
    "__Z10aux_0bf820Piz": "_f_0bf820",
    "__Z2msPvij": "_f_145300",
    "__Z9f_0432e0cia": "_f_0432e0",
    "__Z8g_147323Pviiiiii": "_f_147323",
    "__Z8h_147323Pviiiiii": "_f_147323",
    "__Z9f_147323biiiiiii": "_f_147323",
    "__Z9f_147323ePviiiiii": "_f_147323",
    "__ZN10Palette943C1Ev": "_f_01e100",
    "__ZN11Palette1111C1Ev": "_f_01e100",
    "__ZN13PaletteGrok17C1Ev": "_f_01e100",
    "__ZN16PaletteDialog492C1Ev": "_f_01e100",
    "__ZN4RGB3C1Ev": "_f_01e100",
    "__ZN6LocPalC1Ev": "_f_01e100",
    "__ZN3PalC1Ev": "_f_01e100",
    "__ZN3TrkC1Ev": "_f_01e100",
    "__ZN4ItemC1Ev": "_f_01e100",
    "__ZN11CmaskObj909C1Ev": "_f_04a890",
    "__ZN11CmaskS20909C1Eiiiii": "_f_134840",
    "__ZN12ContextAMap42LkC1Ev": "_f_0ce7c0",
    "__ZN12ContextAMap43PakC1Ev": "_f_1459b0",
    "__ZN12ContextAMap44GridC1Etti": "_f_04fc60",
    "__ZN12ContextAMap44IterC1El": "_f_01b860",
    "__ZN12ContextGz02611MsgC_026b50C1Eiii": "_f_125400",
    "__ZN12ContextMine25Dlg0cC1Ei": "_f_046d10",
    "__ZN12RivaE4640LK4C1Ev": "_f_0ce7c0",
    "__ZN12ScrBase_e440C2EiiiPv": "_f_03f270",
    "__ZN14RivaE4640LK720C1Ev": "_f_0ce7c0",
    "__ZN15RivaE4640WindowC1Eiiiii": "_f_0d6710",
    "__ZN1TC1Ev": "_f_059d50",
    "__ZN1YC1EPvi": "_f_06a6e0",
    "__ZN2FAC1EPPv": "_f_148570",
    "__ZN2FRC1EPcS0_S0_": "_f_0da460",
    "__ZN2GrC1Esii": "_f_112df0",
    "__ZN2HSC1Eiii": "_f_0fac10",
    "__ZN2HTC1Eiiiiiiiii": "_f_1461f4",
    "__ZN2HZC1Ei": "_f_15c640",
    "__ZN2LkC1Ev": "_f_0ce7c0",
    "__ZN2MGC1Ev": "_f_0ce7c0",
    "__ZN2PkC1Eii": "_f_05f190",
    "__ZN2PtC1Etttt": "_f_01e100",
    "__ZN2R2C1Ei": "_f_04fe30",
    "__ZN2SOC1EPKcS1_S1_": "_f_125400",
    "__ZN2SOC1EiiPv": "_f_0fac10",
    "__ZN2SVC1Ev": "_f_0ce7c0",
    "__ZN2SpC1EP3Ent": "_f_10cba0",
    "__ZN2StC1Ev": "_f_147cd0",
    "__ZN2T1C1Ei": "_f_046d10",
    "__ZN2T3C1Eiiiiii": "_f_134870",
    "__ZN2T3C1Ev": "_f_01e100",
    "__ZN2T5C1Eii": "_f_05f190",
    "__ZN2T9C1Eii": "_f_0fac80",
    "__ZN2TTC1Ev": "_f_059d50",
    "__ZN2TwC1Eii": "_f_05f190",
    "__ZN2TxC1Eiii": "_f_112df0",
    "__ZN2TyC1Ei": "_f_046d10",
    "__ZN2X9C1Eii": "_f_0fac80",
    "__ZN2ZtC1EPiS0_i": "_f_125400",
    "__ZN3A46C1Es": "_f_046d10",
    "__ZN3BigC1EPcS0_S0_": "_f_125400",
    "__ZN3CtxC1EPvS0_S0_": "_f_125400",
    "__ZN3DlgC1Eii": "_f_05f190",
    "__ZN3DlgC1EiiiiP15RivaRasterImageii": "_f_061b10",
    "__ZN3EffC1EP3EntS1_iii": "_f_134840",
    "__ZN3EffC1EP3Entiiiii": "_f_134870",
    "__ZN3GfxC1Elllii": "_f_0bd910",
    "__ZN3GfxC1EshPv": "_f_0fac10",
    "__ZN3MsgC1EPiS0_S0_": "_f_125400",
    "__ZN3OBCC1Eiii": "_f_125400",
    "__ZN3ObjC1EP3Reci": "_f_11c0f0",
    "__ZN3ObjC1EPKcS1_S1_": "_f_125400",
    "__ZN3ObjC1EPvS0_S0_": "_f_125400",
    "__ZN3ObjC1Ev": "_f_10a940",
    "__ZN3PakC1Ev": "_f_1459b0",
    "__ZN3RegC1Ei": "_f_04fe30",
    "__ZN3ScrC1Ev": "_f_059d50",
    "__ZN3SprC1Eii": "_f_0fac80",
    "__ZN3T14C1Eiii": "_f_112df0",
    "__ZN3TmpC1Ei": "_f_046d10",
    "__ZN3WinC1EP3ScrPv": "_f_045a90",
    "__ZN3WndC1EP3WinPv": "_f_0e92e0",
    "__ZN3WndC1Eiiiiis": "_f_0da910",
    "__ZN4Dlg2C1Eiii": "_f_112df0",
    "__ZN4GridC1Etti": "_f_04fc60",
    "__ZN4IconC1Eis": "_f_0a22e0",
    "__ZN4IterC1El": "_f_01b860",
    "__ZN4LockC1Ev": "_f_0ce7c0",
    "__ZN4MsgCC1EPKcS1_S1_": "_f_125400",
    "__ZN4MsgCC1EPiS0_S0_": "_f_125400",
    "__ZN4MsgCC1EPvS0_S0_": "_f_125400",
    "__ZN4MsgCC1Eiii": "_f_125400",
    "__ZN4MsgXC1EPvS0_S0_": "_f_125400",
    "__ZN4Obj2C1EP3Obji": "_f_0a8830",
    "__ZN4PartC1Ev": "_f_0fabf0",
    "__ZN4RectC1ERKS_": "_f_01e100",
    "__ZN4ShopC1Ellllss": "_f_0da910",
    "__ZN4StrmC1Em": "_f_01afa0",
    "__ZN4T13eC1Eiii": "_f_0104b0",
    "__ZN5Entry5ClearEv": "_f_0a2500",
    "__ZN5GraphC1Eiii": "_f_112df0",
    "__ZN5Obj5fC1Eii": "_f_05f190",
    "__ZN5SO_t2C1EPKcS1_S1_": "_f_125400",
    "__ZN5StockC1EP4Itemi": "_f_11c0f0",
    "__ZN6Obj112C1Eiii": "_f_112df0",
    "__ZN7B05ff60C2Ei": "_f_05ff60",
    "__ZN7B0fb5f0C2Ei": "_f_0fb5f0",
    "__ZN7B115630C2Ei": "_f_115630",
    "__ZN7LevelUpC1Ev": "_f_04a890",
    "__ZN1D2v2Ev": "_f_01ec10",
    "__ZN2B12v4Ev": "_f_01ec10",
    "__ZN2B12v5Ev": "_f_01ec10",
    "__ZN2B12v6Ev": "_f_01ec10",
    "_boron1_file": "_d_1a0690",
    "_ch_item_file": "_d_1a080c",
    "_charset_file": "_d_1a0e44",
    "_exposami_file": "_d_1a1aa8",
    "_healer_file": "_d_1a3514",
    "_item_file": "_d_1a3eb0",
    "_ep710": "_f_070e41",
    "_plog_d_1c2148": "_d_1c2148",
    "_plog_f_144fbf": "_f_144fbf",
    "_plog_f_145279": "_f_145279",
    "_plog_f_144cb6": "_f_144cb6",
    "_plog_f_145259": "_f_145259",
    "__Z13plog_f_144fbfPKciz": "_f_144fbf",
    "__Z13plog_f_145279ili": "_f_145279",
    "__Z13plog_f_144cb6iPKvj": "_f_144cb6",
    "__Z13plog_f_145259i": "_f_145259",
}

# Destruktor-Ziele (D1Ev / D2Ev -> werden ueber 1-Zeilen-Wrapper mit flags=0 aufgerufen)
DTOR_CLASS_TO_TARGET = {
    "RivaRasterImage": "_f_0fad20",
    "RivaTextContext": "_f_1254a0",
    "RivaItemDefinition": "_f_01e100",
    "CmaskObj909": "_f_04ad40",
    "CmaskS20909": "_f_1348d0",
    "Cur": "_f_0da990",
    "Pak": "_f_1459d0",
    "Grid": "_f_04fce0",
    "Iter": "_f_01b880",
    "Strm": "_f_01afd0",
    "MsgC_026b50": "_f_1254a0",
    "RivaE4640LK4": "_f_0ce7e0",
    "RivaE4640LK720": "_f_0ce7e0",
    "RivaE4640Window": "_f_0d6ab0",
    "Q": "_f_0fad20",
    "U": "_f_0fad20",
    "Y": "_f_06a710",
    "B1": "_f_0b8520",
    "Gr": "_f_112e70",
    "HS": "_f_15c6d0",
    "HZ": "_f_0fad20",
    "Lk": "_f_0ce7e0",
    "MG": "_f_0ce7e0",
    "Pk": "_f_05f220",
    "R2": "_f_04fe60",
    "SVC": "_f_0ce7e0",
    "SV": "_f_0ce7e0",
    "Sp": "_f_10cbc0",
    "T1": "_f_046d90",
    "T3": "_f_1348d0",
    "T5": "_f_05f220",
    "T9": "_f_0fad20",
    "TT": "_f_059d60",
    "X9": "_f_0fad20",
    "Zt": "_f_1254a0",
    "A46": "_f_046d90",
    "Big": "_f_1254a0",
    "Ctx": "_f_1254a0",
    "EdC": "_f_061cd0",
    "Eff": "_f_1348d0",
    "Gfx": "_f_0bda30",
    "IMG": "_f_0fad20",
    "ImC": "_f_0fad20",
    "Msg": "_f_1254a0",
    "OBC": "_f_1254a0",
    "Rec": "_f_1254a0",
    "Reg": "_f_04fe60",
    "Scr": "_f_059d50",
    "Spr": "_f_0fad20",
    "Sub": "_f_010430",
    "T14": "_f_112e70",
    "Tmp": "_f_046d90",
    "Wnd": "_f_0da990",
    "DelC": "_f_15c6d0",
    "DelD": "_f_0fad20",
    "Dlg2": "_f_112e70",
    "IcoD": "_f_0a2400",
    "Item": "_f_0fad20",
    "Lock": "_f_0ce7e0",
    "MsgC": "_f_1254a0",
    "MsgX": "_f_1254a0",
    "Obj2": "_f_0a8b40",
    "Part": "_f_0fad20",
    "Shop": "_f_0da990",
    "T13e": "_f_010590",
    "Frame": "_f_01e100",
    "Graph": "_f_112e70",
    "Obj5f": "_f_05f220",
    "SO_t2": "_f_1254a0",
    "Stock": "_f_11c120",
    "Obj112": "_f_112e70",
    "B05ff60": "_f_060080",
    "B0fb5f0": "_f_0fb630",
    "B115630": "_f_115640",
    "LevelUp": "_f_04ad40",
    "TdmInit2A": "_f_0da990",
    "TdmInit2B": "_f_0fad20",
}

# Funktionen, die explizit in riva_crt_and_stubs.cpp implementiert sind
IMPLEMENTED_IN_CRT_CPP = {
    "_f_01ebd0", "_f_0ce0b0", "_f_0d3c75", "_f_0d3df6",
    "_f_144bf0", "_f_144cb6", "_f_144e8b", "_f_144fbf",
    "_f_145234", "_f_145254", "_f_145259", "_f_145279",
    "_f_1452bc", "_f_1452d0", "_f_145300", "_f_145318",
    "_f_145530", "_f_145547", "_f_145590", "_f_1455a4",
    "_f_1455b5", "_f_145702", "_f_14572e", "_f_147c84",
    "_f_148120", "_f_148143", "_f_148160", "_f_148170",
    "_f_148180", "_f_148420", "_f_148429", "_f_148450",
    "_f_148469", "_f_148518", "_f_148534", "_f_149292",
    "_f_1492b4", "_f_1492d1", "_f_1492ed", "_f_1492fd",
    "_f_149336", "_f_149caa", "_f_149cd2", "_f_149cf0",
    "_f_149cf5", "_f_149d20", "_f_149d38", "_f_149d50",
    "_f_149d80", "_f_149d9b", "_f_149dbe", "_f_149dea",
    "_f_149dfe", "_f_149e0f", "_f_149e2e", "_f_149e58",
    "_f_149e89", "_f_149eb4", "_f_14d075", "_f_14d0d7",
    "_f_14d0e4", "_f_14d17f", "_f_14d1c1", "_f_14d1c9",
    "_f_14d27d", "_f_14d50b", "_f_14d546", "_f_14d652",
    "_f_14d667", "_f_14d6b1", "_f_14d6c4", "_f_14d6ef",
    "_f_14d717", "_f_14d7dc", "_f_155f70", "_f_1567af",
    "_f_156870", "_f_15dc3f", "_f_15dc98", "_f_15e0e7",
    "_f_15e114", "_f_15e181", "_f_15e1be", "_f_15e469",
    "_f_15e55f", "_f_15e5f7", "_f_15e65b", "_f_15e6d8",
    "_f_15e836", "_f_15e97a", "_f_15ea0f", "_f_15ea53",
    "_f_15ea62", "_f_15ea70", "_f_15ead2", "_f_15eaf3",
    "_f_15eb02", "_f_15eb47", "_f_15eb9d", "_f_15ebd6",
    "_f_15ec58", "_f_15f1b4", "_f_15f1c8", "_f_15f1dc", "_f_15f1e1",
    "_f_15f269", "_f_15f282", "_f_15f2b5", "_f_15f2d6",
    "_f_15f307", "_f_15f3e5", "_f_15f3fc", "_f_15fdd5",
    "_f_165460", "_f_165520", "_f_165570", "_f_165620",
    "_f_165700", "_f_165730", "_f_1657a0", "_f_1657d0",
    "_f_165820", "_f_1658a0", "_f_165920", "_f_165960",
    "_f_165990", "_f_1659d0", "_f_165a10", "_f_165a50",
    "_f_165a90", "_f_165ac0", "_f_165b30", "_f_165b60",
    "_f_165b90", "_f_165bd0", "_f_165c40", "_f_165c50",
    "_f_165d00", "_f_165d40", "_f_165d60", "_f_165d73",
    "_f_165db0", "_f_165de2", "_f_165e06", "_f_165e20",
    "_f_16657c", "_f_16886d", "_f_168944", "_f_16897e",
    "_f_168cd4", "_f_168faf", "_f_169412", "_f_16991e",
    "_f_16997a", "_f_169a29", "_f_169a33", "_f_169c34",
    "_f_169c3a", "_f_16a9da", "_f_16fc19",
    "_f_18e187", "_f_091b50", "_f_0faba0", "_f_107280",
    "_f_11a880", "_f_12ea30", "_f_140aea", "_f_0f939a",
    "_f_070e41", "_f_138250", "_f_169c99", "_f_16aafb",
    "_f_02fcb7", "_f_0d3f25", "_f_0d4070", "_f_0d40b6",
    "_f_0d40dd", "_f_0d4103", "_f_0d412a", "_f_0d4163",
    "_f_0d4248", "_f_0d4394", "_f_0d448c",
    "_f_149f90", "_f_14a0b0", "_f_14a1d0", "_f_14a450",
    "_f_14a940", "_f_14b100", "_f_14b3d0", "_f_14b7b0",
    "_f_14bb10", "_f_14bb30", "_f_14bb40", "_f_14d040",
    "_f_15c4e0", "_f_15c500", "_f_15f4a0",
    "_f_169845", "_f_17c709",
}

_brender_cpp = PORT_DIR / "platform" / "riva_3d_brender.cpp"
if _brender_cpp.is_file():
    _brender_txt = _brender_cpp.read_text(encoding="utf-8", errors="ignore")
    for _m in re.finditer(r"\b(f_[0-9a-f]{6})\s*\([^;]*\)\s*\{", _brender_txt):
        IMPLEMENTED_IN_CRT_CPP.add("_" + _m.group(1))



def resolve_dtor_target(sym: str, units: list[str]) -> str | None:
    if not (sym.startswith("__ZN") and re.search(r"D[012]Ev$", sym)):
        return None
    # Zerlege Itanium-Nested-Name nach Laengenpraefixen ab Index 4 ("__ZN")
    pos = 4
    n = len(sym)
    parts = []
    while pos < n:
        m_num = re.match(r"^(\d+)", sym[pos:])
        if not m_num:
            break
        ln = int(m_num.group(1))
        pos += len(m_num.group(1))
        parts.append(sym[pos : pos + ln])
        pos += ln
    if not parts:
        return None
    cls = parts[-1]
    if cls == "T":
        return "_f_059d60" if "cache" in units and len(units) == 1 else "_f_010430"
    if cls == "SO":
        return "_f_0fad20" if units == ["gfx_t3"] else "_f_1254a0"
    if cls == "Dlg":
        return "_f_061cd0" if units == ["amap_t345"] else "_f_05f220"
    if cls == "Obj":
        return "_f_11c120" if units == ["fi_end"] else "_f_1254a0"
    return DTOR_CLASS_TO_TARGET.get(cls)


def normalize_coff_file(obj_path: Path, aliases: dict[str, str], unit: str) -> tuple[int, list[str], list[str]]:
    data = bytearray(obj_path.read_bytes())
    if len(data) < 20:
        return 0, [], []

    machine, nsects, timedate, symptr, nsyms, opthdr, flags = struct.unpack("<HHIIIHH", data[:20])
    if symptr == 0 or nsyms == 0:
        return 0, [], []

    str_off = symptr + nsyms * 18
    if str_off + 4 <= len(data):
        str_size = struct.unpack("<I", data[str_off : str_off + 4])[0]
        str_tab = bytearray(data[str_off : str_off + str_size])
    else:
        str_tab = bytearray(b"\x04\x00\x00\x00")

    added_strs: dict[str, int] = {}

    def get_or_add_str(s: str) -> int:
        if s in added_strs:
            return added_strs[s]
        off = len(str_tab)
        str_tab.extend(s.encode("ascii") + b"\x00")
        added_strs[s] = off
        return off

    alias_items = sorted(aliases.items(), key=lambda kv: -len(kv[0]))

    changed = 0
    defined_syms = []
    undef_syms = []
    defined_set = set()

    idx = 0
    while idx < nsyms:
        pos = symptr + idx * 18
        sym = data[pos : pos + 18]
        name_raw = sym[:8]
        val, sec, typ, sclass, numaux = struct.unpack("<IhHBB", sym[8:18])
        if sclass == 2 and (sec > 0 or val > 0):
            if name_raw[:4] == b"\x00\x00\x00\x00":
                soff = struct.unpack("<I", name_raw[4:8])[0]
                end = data.find(b"\x00", str_off + soff)
                nm = data[str_off + soff : end].decode("latin1")
            else:
                nm = name_raw.rstrip(b"\x00").decode("latin1")
            defined_set.add(nm)
        idx += 1 + numaux

    idx = 0
    while idx < nsyms:
        pos = symptr + idx * 18
        sym = data[pos : pos + 18]
        name_raw = sym[:8]
        val, sec, typ, sclass, numaux = struct.unpack("<IhHBB", sym[8:18])

        if sclass == 2:  # IMAGE_SYM_CLASS_EXTERNAL
            if name_raw[:4] == b"\x00\x00\x00\x00":
                soff = struct.unpack("<I", name_raw[4:8])[0]
                end = data.find(b"\x00", str_off + soff)
                name = data[str_off + soff : end].decode("latin1")
            else:
                name = name_raw.rstrip(b"\x00").decode("latin1")

            new_name = None
            if not name.startswith(("__ZTV", "__ZTI", "__ZTS")):
                if name in EXPLICIT_GCC_TO_TARGET:
                    new_name = EXPLICIT_GCC_TO_TARGET[name]
                if unit == "cache" and name == "__ZN1TD1Ev":
                    new_name = "_f_059d60"
                elif unit == "gfx_t3" and name == "__ZN2SOD1Ev":
                    new_name = "_f_0fad20"
                elif unit == "amap_t345" and name == "__ZN3DlgD1Ev":
                    new_name = "_f_061cd0"
                elif unit == "fi_end" and name == "__ZN3ObjD1Ev":
                    new_name = "_f_11c120"

                if new_name is None:
                    for ident, target in alias_items:
                        if name == "_" + ident or name == ident:
                            new_name = target
                            break
                        if f"{len(ident)}{ident}" in name and name.startswith("__Z"):
                            new_name = target
                            break

                if new_name is None and name.startswith("__Z"):
                    if (sec > 0 or val > 0) and any(tag in name for tag in ("_dummy", "_halt", "f_01c840x")):
                        pass
                    else:
                        head_part = name.split("E")[0] if name.startswith("__ZN") else name
                        m_cpp_all = re.findall(r"(?:[89]|\d{2})([fd]_[0-9a-fA-F]{6})", head_part)
                        if not m_cpp_all and name.startswith("__ZN"):
                            m_cpp_all = re.findall(r"(?:[89]|\d{2})([fd]_[0-9a-fA-F]{6})", name)
                        if m_cpp_all:
                            chosen = m_cpp_all[-1] if name.startswith("__ZN") else m_cpp_all[0]
                            new_name = "_" + chosen.lower()
                        else:
                            m_x = re.search(r"7X([0-9a-fA-F]{6})C[12]", name)
                            if m_x:
                                new_name = "_f_" + m_x.group(1).lower()

                if new_name is None:
                    if (sec > 0 or val > 0) and any(tag in name for tag in ("_dummy", "_halt", "f_01c840x")):
                        pass
                    else:
                        m = re.search(r"(?:^|_)([fd]_[0-9a-fA-F]{6})(?:[^0-9a-fA-F]|$)", name)
                        if m:
                            cand = "_" + m.group(1).lower()
                            if name != cand:
                                new_name = cand

            if new_name and new_name.startswith("_d_") and len(new_name) == 9:
                try:
                    va = int(new_name[3:], 16)
                    if 0x010400 <= va < 0x167F60:
                        new_name = f"_f_{va:06x}"
                except ValueError:
                    pass

            if new_name is None and name.startswith("_d_") and len(name) == 9:
                try:
                    va = int(name[3:], 16)
                    if 0x010400 <= va < 0x167F60:
                        new_name = f"_f_{va:06x}"
                except ValueError:
                    pass

            if new_name and new_name != name:
                if (sec > 0 or val > 0) and new_name in defined_set:
                    new_name = None
                else:
                    soff = get_or_add_str(new_name)
                    data[pos : pos + 8] = b"\x00\x00\x00\x00" + struct.pack("<I", soff)
                    name = new_name
                    if sec > 0 or val > 0:
                        defined_set.add(name)
                    changed += 1

            if sec > 0 or val > 0:
                defined_syms.append(name)
            elif sec == 0:
                undef_syms.append(name)

        idx += 1 + numaux

    if changed > 0:
        struct.pack_into("<I", str_tab, 0, len(str_tab))
        out_data = data[:str_off] + str_tab
        obj_path.write_bytes(out_data)

    return changed, defined_syms, undef_syms


def main():
    manifest_path = PORT_DIR / "src" / "manifest.json"
    obj_dir = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("/mnt/c/Windows/Temp/riva_port_build/obj")

    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    units = manifest["units"]
    unit_aliases = manifest.get("aliases", {})

    total_changed = 0
    all_defined = set()
    all_undef = {}

    for u in units:
        unit = u["unit"]
        obj_path = obj_dir / f"{unit}.o"
        if not obj_path.exists():
            continue
        aliases = unit_aliases.get(unit, {})
        c, defs, undefs = normalize_coff_file(obj_path, aliases, unit)
        total_changed += c
        all_defined.update(defs)
        for us in undefs:
            all_undef.setdefault(us, []).append(unit)

    dgroup_obj = obj_dir.parent / "riva_dgroup.o"
    if dgroup_obj.exists():
        _, defs, undefs = normalize_coff_file(dgroup_obj, {}, "riva_dgroup")
        all_defined.update(defs)
        for us in undefs:
            all_undef.setdefault(us, []).append("riva_dgroup")

    brender_obj = obj_dir.parent / "riva_3d_brender.o"
    if brender_obj.exists():
        _, defs, undefs = normalize_coff_file(brender_obj, {}, "riva_3d_brender")
        all_defined.update(defs)

    # Scanne zusaetzlich Port/platform/riva_3d_brender.cpp und riva_crt_and_stubs.cpp nach definierten f_xxxxxx
    for plat_src in [
        PORT_DIR / "platform" / "riva_3d_brender.cpp",
        PORT_DIR / "platform" / "riva_crt_and_stubs.cpp",
    ]:
        if plat_src.exists():
            src_txt = plat_src.read_text(encoding="utf-8", errors="ignore")
            for m_fn in re.finditer(r"\b(f_[0-9a-fA-F]{6})\s*\([^;{}]*\)\s*\{", src_txt, re.S):
                all_defined.add(f"_{m_fn.group(1).lower()}")

    src_cpp = PORT_DIR / "src" / "cpp"
    def_line = re.compile(
        r"^[ \t]*(?:extern\s+\"C\"\s+)?(?:static\s+)?(?:inline\s+)?"
        r"(?:unsigned\s+|signed\s+)?(?:int|void|short|long|char|struct\s+\w+)\s+"
        r"(f_[0-9a-fA-F]{6})\s*\([^;{}]*\)\s*(\{)?\s*$"
    )
    if src_cpp.is_dir():
        for cpp_path in src_cpp.glob("*.CPP"):
            cpp_lines = cpp_path.read_text(encoding="utf-8", errors="ignore").splitlines()
            for idx, cpp_line in enumerate(cpp_lines):
                m_fn = def_line.match(cpp_line)
                if not m_fn:
                    continue
                has_body = bool(m_fn.group(2)) or (
                    idx + 1 < len(cpp_lines) and cpp_lines[idx + 1].strip() == "{"
                )
                if has_body:
                    all_defined.add(f"_{m_fn.group(1).lower()}")

    crt_decl_sigs = {}
    crt_src = PORT_DIR / "platform" / "riva_crt_and_stubs.cpp"
    if crt_src.exists():
        for _line in crt_src.read_text(encoding="utf-8", errors="ignore").splitlines():
            _dm = re.match(
                r"\s*(?:extern\s+\"C\"\s+)?[\w\s\*]+\s+(f_[0-9a-fA-F]{6})\s*\(([^)]*)\)\s*;\s*$",
                _line,
            )
            if _dm:
                crt_decl_sigs[_dm.group(1)] = _dm.group(2).strip() or "void"

    missing = {k: v for k, v in sorted(all_undef.items()) if k not in all_defined}

    # Erzeuge dtor_wrappers.inc fuer C++-Destruktoren und noch nicht uebersetzte ASM-Stubs (mit Stub-Waechter)
    dtor_lines = [
        "/* Automatisch erzeugt von normalize_objs.py */",
        'extern "C" void riva_log_stub(const char *fn_name);',
    ]
    wrapped_dtors = 0
    stubbed_funcs = 0

    for sym, us in list(missing.items()):
        target = resolve_dtor_target(sym, us)
        if target:
            asm_sym = sym
            c_target = target[1:] if target.startswith("_") else target
            dtor_lines.append(f'extern "C" void *{c_target}(void *, int);')
            dtor_lines.append(f'extern "C" void *__dtor_wrap_{wrapped_dtors}(void *self) __asm__("{asm_sym}");')
            dtor_lines.append(f'extern "C" void *__dtor_wrap_{wrapped_dtors}(void *self) {{ return {c_target}(self, 0); }}')
            wrapped_dtors += 1
            del missing[sym]
        elif sym.startswith("_f_") and len(sym) == 9 and sym not in IMPLEMENTED_IN_CRT_CPP:
            c_name = sym[1:]
            sig = crt_decl_sigs.get(c_name, "void")
            dtor_lines.append(
                f'extern "C" int {c_name}({sig}) {{ static int s_logged = 0; if (!s_logged) {{ s_logged = 1; riva_log_stub("{c_name}"); }} return 0; }}'
            )
            stubbed_funcs += 1
            del missing[sym]

    # fz_145760_t2 referenziert __ZN2HTD1Ev -> HM-Soundkanal-Destruktor f_1462d3.
    if not any("__ZN2HTD1Ev" in line for line in dtor_lines):
        dtor_lines.append('extern "C" void *f_1462d3(void *, int);')
        dtor_lines.append('extern "C" void *__dtor_wrap_ht(void *self) __asm__("__ZN2HTD1Ev");')
        dtor_lines.append('extern "C" void *__dtor_wrap_ht(void *self) { return f_1462d3(self, 0); }')

    out_text = "\n".join(dtor_lines) + "\n"
    out_inc = PORT_DIR / "build" / "generated" / "dtor_wrappers.inc"
    out_inc.parent.mkdir(parents=True, exist_ok=True)
    out_inc.write_text(out_text, encoding="utf-8")

    win_inc = obj_dir.parent / "build" / "generated" / "dtor_wrappers.inc"
    if obj_dir.parent.exists():
        win_inc.parent.mkdir(parents=True, exist_ok=True)
        win_inc.write_text(out_text, encoding="utf-8")

    print(
        f"Normalized {total_changed} symbols across {len(units)} objects; "
        f"generated {wrapped_dtors} dtor wrappers and {stubbed_funcs} ASM stubs."
    )
    print(f"Total defined symbols: {len(all_defined)}, Remaining undefined symbols (CRT/Platform): {len(missing)}")
    return missing


if __name__ == "__main__":
    main()
