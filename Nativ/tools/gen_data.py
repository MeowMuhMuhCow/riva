#!/usr/bin/env python3
"""
gen_data.py - Erzeugt zur Bauzeit das DGROUP-Datenmodul (riva_dgroup.S) direkt aus der
eigenen RIVA.EXE des Nutzers (ohne Originaldaten im Repository abzulegen).

Das erzeugte Assembler-Modul enthaelt:
  1. Den initialisierten Datenbereich DGROUP (0x1A0000..0x1BC5EF, 116.208 Bytes)
     und den Null-initialisierten BSS-Bereich (0x1BC5F0..0x1F7D40, 243.536 Bytes).
  2. Exakte globale Labels _d_xxxxxx an ihren Original-Offsets innerhalb von DGROUP,
     sodass struktur- und arrayuebergreifende Adressrechnungen 1:1 funktionieren.
  3. Alle 2.413 LE-Relokationen innerhalb von DGROUP aufgeloest auf echte Symbolreferenzen
     (_f_xxxxxx fuer Code-Zeiger/Vtables, _riva_dgroup_base + Offset fuer Daten-Zeiger).
  4. Den konstanten Datenblock fz_1788d0 (0x1788D0..0x178B20) aus dem Original-Abbild.
"""

import argparse
import hashlib
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
PORT_DIR = HERE.parent
REPO_ROOT = PORT_DIR.parent

SOLL_GROESSE = 2_477_899
SOLL_MD5 = "fb8f5fc3ba5454c7344c17aaf362de35"
DOS4GW_PREFIX_LEN = 0x38D64

DGROUP_BASE = 0x1A0000
DGROUP_INIT_END = 0x1BC5F0
DGROUP_TOTAL_END = 0x1F8000


def wsl_path_from_win(win_path: str) -> Path | None:
    if not win_path:
        return None
    m = re.match(r"^([A-Za-z]):[\\/](.*)$", win_path.strip())
    if m:
        drive = m.group(1).lower()
        rest = m.group(2).replace("\\", "/")
        return Path(f"/mnt/{drive}/{rest}")
    return Path(win_path.strip())


def locate_original_exe(explicit_path: str | None = None) -> Path:
    candidates = []
    if explicit_path:
        candidates.append(Path(explicit_path))
        wp = wsl_path_from_win(explicit_path)
        if wp:
            candidates.append(wp)

    candidates.extend([
        REPO_ROOT / "Original" / "RIVA.EXE",
        REPO_ROOT / "Original" / "riva.exe",
        REPO_ROOT / "Build" / "RIVA.EXE",
    ])

    sp_file = REPO_ROOT / "SPIELPFAD.txt"
    if sp_file.is_file():
        raw = sp_file.read_text(encoding="utf-8", errors="ignore").strip()
        for d in (Path(raw), wsl_path_from_win(raw)):
            if d:
                candidates.append(d / "RIVA.EXE")
                candidates.append(d / "riva.exe")

    default_gog = [
        r"C:\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania 3\RIVA.EXE",
        r"C:\Program Files\GOG Galaxy\Games\Realms of Arkania 3\RIVA.EXE",
        r"C:\GOG Games\Realms of Arkania 3\RIVA.EXE",
    ]
    for g in default_gog:
        candidates.append(Path(g))
        wp = wsl_path_from_win(g)
        if wp:
            candidates.append(wp)

    for c in candidates:
        try:
            if c and c.is_file() and c.stat().st_size == SOLL_GROESSE:
                return c.resolve()
        except Exception:
            pass

    raise FileNotFoundError(
        "Original RIVA.EXE (2.477.899 Bytes) wurde nicht gefunden. "
        "Bitte nach Original/RIVA.EXE kopieren, in SPIELPFAD.txt eintragen oder --exe PFAD angeben."
    )


def parse_le_and_fixups(exe_bytes: bytes):
    start = exe_bytes.find(b"LE\0\0", 0x30000)
    if start < 0:
        raise ValueError("LE-Header fehlt in RIVA.EXE")
    u = lambda off: struct.unpack_from("<I", exe_bytes, start + off)[0]
    objects = [struct.unpack_from("<6I", exe_bytes, start + u(0x40) + 24 * i) for i in range(u(0x44))]
    table, base = start + u(0x68), start + u(0x6C)
    fixups = {}
    for page in range(u(0x14)):
        first, end = struct.unpack_from("<II", exe_bytes, table + 4 * page)
        owner = next(o for o in objects if o[3] - 1 <= page < o[3] - 1 + o[4])
        address = owner[1] + (page - (owner[3] - 1)) * 4096
        pos = base + first
        while pos < base + end:
            typ, flags = exe_bytes[pos], exe_bytes[pos + 1]
            pos += 2
            if typ & 0x20:
                count = exe_bytes[pos]
                pos += 1
            else:
                offset = struct.unpack_from("<h", exe_bytes, pos)[0]
                pos += 2
            width = 2 if flags & 0x40 else 1
            target_obj = int.from_bytes(exe_bytes[pos : pos + width], "little")
            pos += width
            target = 0
            if typ & 15 != 2:
                width = 4 if flags & 0x10 else 2
                target = int.from_bytes(exe_bytes[pos : pos + width], "little")
                pos += width
            dest = objects[target_obj - 1][1] + target
            if typ & 0x20:
                for _ in range(count):
                    offset = struct.unpack_from("<h", exe_bytes, pos)[0]
                    pos += 2
                    fixups[address + offset] = (typ & 15, dest)
            else:
                fixups[address + offset] = (typ & 15, dest)

    le = exe_bytes[DOS4GW_PREFIX_LEN:]
    hdr = struct.unpack_from("<I", le, 0x3C)[0]
    data_off = struct.unpack_from("<I", le, hdr + 0x80)[0]
    code_bytes = bytearray(le[data_off : data_off + 0x18D630])
    obj2_data_off = data_off + 398 * 4096
    obj2_len = len(le) - obj2_data_off
    dgroup_init = bytearray(DGROUP_INIT_END - DGROUP_BASE)
    dgroup_init[:obj2_len] = le[obj2_data_off : obj2_data_off + obj2_len]
    return code_bytes, dgroup_init, fixups


def collect_referenced_d_symbols(src_dir: Path) -> tuple[set[int], set[str]]:
    addrs = {0x1A0690, 0x1A080C, 0x1A0E44, 0x1A1AA8, 0x1A3514, 0x1A3EB0, 0x1BC140}
    special_names = set()
    sources = (list((src_dir / "cpp").glob("*.[cC]*"))
               + list((src_dir / "inc").glob("*.[hH]*"))
               + list((PORT_DIR / "platform").glob("*.[cChH]*")))
    for p in sources:
        txt = p.read_text(encoding="latin1", errors="ignore")
        for m in re.finditer(r"\bd_([0-9a-fA-F]{6})(_[a-zA-Z0-9]+)?\b", txt):
            va = int(m.group(1), 16)
            addrs.add(va)
            if m.group(2):
                special_names.add(f"d_{m.group(1).lower()}{m.group(2)}")
        for m in re.finditer(r"\bd_v([0-9a-fA-F]{6})\b", txt):
            va = int(m.group(1), 16)
            addrs.add(va)
            special_names.add(f"d_v{m.group(1).lower()}")
    return addrs, special_names


def generate_dgroup_asm(exe_path: Path, src_dir: Path, out_asm: Path):
    exe_bytes = exe_path.read_bytes()
    md5 = hashlib.md5(exe_bytes).hexdigest()
    if md5 != SOLL_MD5:
        print(f"[gen_data] Warnung: RIVA.EXE MD5={md5} (erwartet {SOLL_MD5})", file=sys.stderr)

    code_bytes, dgroup_init, fixups = parse_le_and_fixups(exe_bytes)
    d_addrs, special_names = collect_referenced_d_symbols(src_dir)

    # Die HTML-Attributnamen liegen im Original im CODE-Segment, sind aber Daten.
    # DGROUPs Zeigertabelle darf hier niemals auf einen Funktions-Stub zeigen.
    code_data_start, code_data_end = 0x1788D0, 0x178B20
    d_addrs.update(dest for addr, (typ, dest) in fixups.items()
                   if DGROUP_BASE <= addr < DGROUP_INIT_END and typ in (6, 7)
                   and code_data_start <= dest < code_data_end)

    # Tote Watcom-Switch-Tabelle bei 0x1A9BA8..0x1A9BB4 ignorieren (zeigt in Mitte von f_1568d1)
    dead_switch_addrs = {0x1A9BA8, 0x1A9BAC, 0x1A9BB0, 0x1A9BB4}

    dgroup_relocs = {}
    code_ref_syms = set()
    for addr, (typ, dest) in sorted(fixups.items()):
        if DGROUP_BASE <= addr < DGROUP_INIT_END and typ in (6, 7):
            if addr in dead_switch_addrs:
                continue
            off = addr - DGROUP_BASE
            if dest >= DGROUP_BASE:
                dgroup_relocs[off] = f"_riva_dgroup_base + {dest - DGROUP_BASE}"
            elif code_data_start <= dest < code_data_end:
                dgroup_relocs[off] = f"_d_{dest:06x}"
            else:
                sym = f"_f_{dest:06x}"
                dgroup_relocs[off] = sym
                code_ref_syms.add(sym)

    # Alle Offset-Marken innerhalb von DGROUP sammeln
    labels_at_offset = {}
    for va in sorted(d_addrs):
        if DGROUP_BASE <= va < DGROUP_TOTAL_END:
            off = va - DGROUP_BASE
            labels_at_offset.setdefault(off, []).append(f"_d_{va:06x}")

    for sname in sorted(special_names):
        m = re.match(r"^d_v?([0-9a-f]{6})", sname)
        if m:
            va = int(m.group(1), 16)
            if DGROUP_BASE <= va < DGROUP_TOTAL_END:
                off = va - DGROUP_BASE
                labels_at_offset.setdefault(off, []).append(f"_{sname}")

    lines = [
        "# Automatisch erzeugt von Port/tools/gen_data.py.",
        "# Enthaelt KEINE Originalbytes aus RIVA.EXE (DGROUP liegt in .bss und wird zur Laufzeit geladen).",
        ".bss",
        ".balign 16",
        ".globl _riva_dgroup_base",
        "_riva_dgroup_base:",
    ]

    init_len = DGROUP_INIT_END - DGROUP_BASE
    total_len = DGROUP_TOTAL_END - DGROUP_BASE

    # 1. Gesamter DGROUP-Bereich (0x1A0000..0x1F8000, 360.448 Bytes) uninitialisiert in .bss
    lines.append(f"    .space {total_len}")

    # 2. Alle DGROUP-Symbolmarken per .set relativ zu _riva_dgroup_base definieren
    for off, lbls in sorted(labels_at_offset.items()):
        for lbl in lbls:
            lines.append(f".globl {lbl}")
            lines.append(f".set {lbl}, _riva_dgroup_base + {off}")

    # 3. Code-Segment-Datenblock fz_1788d0 (0x1788D0..0x178B20, 592 Bytes) ebenfalls in .bss (wird zur Laufzeit geladen)
    lines.append(".balign 16")
    lines.append(".globl _riva_code_data_1788d0")
    lines.append("_riva_code_data_1788d0:")
    lines.append(f"    .space {code_data_end - code_data_start}")
    for va in sorted(d_addrs):
        if 0x167F60 <= va < 0x199700:
            if code_data_start <= va < code_data_end:
                lines.append(f".globl _d_{va:06x}")
                lines.append(f".set _d_{va:06x}, _riva_code_data_1788d0 + {va - code_data_start}")
            else:
                lines.append(f".globl _d_{va:06x}")
                lines.append(f"_d_{va:06x}:")
                lines.append("    .space 4")

    # Niedrige Dummy-Datenmarken (z. B. d_000417, d_010002, d_0101db fuer DPMI-Lock) in .bss
    for va in (0x000417, 0x010002, 0x0101DB):
        lines.append(f".globl _d_{va:06x}")
        lines.append(f"_d_{va:06x}:")
        lines.append("    .space 4")

    # 4. Relokationstabelle fuer das Laufzeit-Laden von DGROUP
    lines.append(".section .rdata,\"dr\"")
    lines.append(".balign 4")
    lines.append(".globl _g_riva_dgroup_reloc_count")
    lines.append("_g_riva_dgroup_reloc_count:")
    lines.append(f"    .long {len(dgroup_relocs)}")
    lines.append(".globl _g_riva_dgroup_relocs")
    lines.append("_g_riva_dgroup_relocs:")
    for off, target_expr in sorted(dgroup_relocs.items()):
        lines.append(f"    .long {off}, {target_expr}")

    out_asm.parent.mkdir(parents=True, exist_ok=True)
    out_asm.write_text("\n".join(lines) + "\n", encoding="ascii")
    print(
        f"[gen_data] Generated runtime-BSS {out_asm} "
        f"({len(labels_at_offset)} DGROUP labels, {len(dgroup_relocs)} relocations, 0 embedded original bytes)."
    )


def main():
    parser = argparse.ArgumentParser(description="Erzeugt riva_dgroup.S aus RIVA.EXE")
    parser.add_argument("--exe", default=None, help="Pfad zur Original-RIVA.EXE")
    parser.add_argument("--src", default=str(PORT_DIR / "src"), help="Pfad zu Port/src")
    parser.add_argument("--out", default=str(PORT_DIR / "build" / "generated" / "riva_dgroup.S"), help="Ausgabedatei")
    args = parser.parse_args()

    exe_path = locate_original_exe(args.exe)
    generate_dgroup_asm(exe_path, Path(args.src), Path(args.out))


if __name__ == "__main__":
    main()
