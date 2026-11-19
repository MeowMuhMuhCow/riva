#!/usr/bin/env python3
"""
bauen_port.py - Gesamtbau-Skript fuer den nativen 32-Bit-Windows-Port (Etappe 1)
von DSA 3: Schatten ueber Riva.

Ablauf:
1. Fuehrt Port/tools/prepare_sources.py aus (kopiert und transformiert die 576 Einheiten
   aus Quelle/cpp/p3 + p1 nach Port/src/cpp/).
2. Fuehrt Port/tools/gen_data.py aus (extrahiert DGROUP mit allen 6.495 d_xxxxxx-Symbolen
   und 2.409 Relokationen zur Bauzeit aus der eigenen Original/RIVA.EXE des Nutzers).
3. Kompiliert geaenderte oder fehlende .CPP-Einheiten parallel mit 32-Bit-MinGW-GCC
   (-m32 -mabi=sysv -fpack-struct=1) mit vorzeichenlosem char in Port/arbeit/build.
4. Normalisiert alle COFF-Symboltabellen ueber Port/tools/normalize_objs.py und erzeugt
   Port/build/generated/dtor_wrappers.inc.
5. Kompiliert die SDL2-Plattformschicht (Port/platform/) und linkt Port/build/RIVA_PORT.EXE.
"""

from __future__ import annotations

import json
import hashlib
import uuid
import re
import os
import shutil
import subprocess
import sys
from pathlib import Path

PORT_DIR = Path(__file__).resolve().parent
ROOT_DIR = PORT_DIR.parent
WIN_BUILD_DIR = PORT_DIR / "arbeit" / "build"
MINGW_BIN_WSL = "/mnt/c/Program Files (x86)/Embarcadero/Dev-Cpp/TDM-GCC-64/bin"


def win_path(path: Path) -> str:
    return subprocess.check_output(["wslpath", "-w", str(path.resolve())]).decode().strip()


def run_cmd_win(cmd_str: str, cwd: Path | None = None) -> None:
    """Begrenzter Lauf ohne Konsolenfenster; eigene Befehlsdatei je Parallelauftrag."""
    cwd = cwd or WIN_BUILD_DIR
    cmd_file = cwd / ("_win_cmd_" + uuid.uuid4().hex + ".txt")
    cmd_file.write_text(cmd_str.replace("\r\n", "\n"), encoding="utf-8")
    ps_bin = shutil.which("powershell.exe") or "/mnt/c/Windows/System32/WindowsPowerShell/v1.0/powershell.exe"
    res = subprocess.run(
        [ps_bin, "-NoProfile", "-NonInteractive", "-ExecutionPolicy", "Bypass",
         "-File", win_path(PORT_DIR / "tools" / "win_cmd.ps1"),
         "-CmdFile", win_path(cmd_file), "-WorkDir", win_path(cwd), "-Seconds", "180"],
        cwd=str(cwd), stdin=subprocess.DEVNULL, timeout=195,
    )
    if res.returncode != 0:
        raise RuntimeError(f"Windows command failed ({res.returncode}): {cmd_str}")


def main() -> int:
    global WIN_BUILD_DIR
    import argparse
    from concurrent.futures import ThreadPoolExecutor

    ap = argparse.ArgumentParser(description="Baut RIVA_PORT_ORIG.EXE, RIVA_PORT_WICHTIG.EXE und RIVA_PORT_ALLES.EXE")
    ap.add_argument("--fix", default="alle", choices=["0", "1", "2", "alle"], help="Welche Fix-Stufe(n) gebaut werden sollen (Standard: alle)")
    ap.add_argument("--extra-defs", default="", help="Zusaetzliche -D-Schalter (z. B. '-DFIX_R001=0 -DFIX_EXPLOITS=0')")
    ap.add_argument("--no-prepare", action="store_true", help="Ueberspringt prepare_sources.py (wenn Port/src/cpp bereits aktuell ist)")
    ap.add_argument("--build-dir", type=Path, default=WIN_BUILD_DIR)
    ap.add_argument("--out-dir", type=Path, default=PORT_DIR / "build")
    args = ap.parse_args()
    WIN_BUILD_DIR = args.build_dir.resolve()
    out_dir = args.out_dir.resolve()
    for directory in [WIN_BUILD_DIR, out_dir]:
        if not directory.is_relative_to(PORT_DIR):
            ap.error("Bau- und Ausgabeordner muessen unter Port liegen.")
        directory.mkdir(parents=True, exist_ok=True)

    WIN_BUILD_DIR.mkdir(parents=True, exist_ok=True)
    for d in ["obj", "obj_fix1", "obj_fix2", "cpp", "inc", "platform"]:
        (WIN_BUILD_DIR / d).mkdir(parents=True, exist_ok=True)
    (PORT_DIR / "build" / "generated").mkdir(parents=True, exist_ok=True)

    if not args.no_prepare:
        print("[1/5] Bereite Port-Quellen vor (prepare_sources.py)...", flush=True)
        subprocess.run([sys.executable, str(PORT_DIR / "tools" / "prepare_sources.py")], check=True)
    else:
        print("[1/5] Ueberspringe prepare_sources.py (--no-prepare aktiv)...", flush=True)

    print("[2/5] Erzeuge DGROUP-Assembler aus Original/RIVA.EXE (gen_data.py)...", flush=True)
    dgroup_s = WIN_BUILD_DIR / "riva_dgroup.S"
    dgroup_o = WIN_BUILD_DIR / "riva_dgroup.o"
    # Auch Generator-, Original- und Symbolaenderungen muessen den Datenbau erneuern.
    data_config = {"generator": hashlib.sha256((PORT_DIR / "tools/gen_data.py").read_bytes()).hexdigest(),
                   "original": hashlib.sha256((ROOT_DIR / "Original/RIVA.EXE").read_bytes()).hexdigest(),
                   "sources": hashlib.sha256(b"".join(p.read_bytes() for folder in [PORT_DIR / "src/cpp", PORT_DIR / "src/inc", PORT_DIR / "platform"]
                       for p in sorted(folder.glob("*")) if p.is_file())).hexdigest()}
    data_config_file = WIN_BUILD_DIR / "data_config.json"
    if (not dgroup_o.exists() or not data_config_file.exists()
            or json.loads(data_config_file.read_text()) != data_config):
        subprocess.run(
            [
                sys.executable,
                str(PORT_DIR / "tools" / "gen_data.py"),
                "--exe",
                str(ROOT_DIR / "Original" / "RIVA.EXE"),
                "--out",
                str(dgroup_s),
            ],
            check=True,
        )
        run_cmd_win("gcc.exe -m32 -c riva_dgroup.S -o riva_dgroup.o")
        data_config_file.write_text(json.dumps(data_config, indent=2))

    print("[3/5] Synchronisiere Header und geaenderte Einheiten...")
    for h in (PORT_DIR / "src" / "inc").glob("*"):
        if h.is_file():
            shutil.copy2(h, WIN_BUILD_DIR / "inc" / h.name)

    manifest = json.loads((PORT_DIR / "src" / "manifest.json").read_text(encoding="utf-8"))
    units = manifest["units"]

    config = {"flags": "-m32 -mabi=sysv -std=gnu++98 -fpermissive -funsigned-char -O1",
              "extra_defs": args.extra_defs,
              "headers": {p.name: hashlib.sha256(p.read_bytes()).hexdigest()
                          for p in sorted((PORT_DIR / "src/inc").glob("*")) if p.is_file()}}
    config_file = WIN_BUILD_DIR / "compile_config.json"
    force = not config_file.exists() or json.loads(config_file.read_text()) != config
    to_compile_0: list[str] = []
    fix_sensitive_units: set[str] = set()
    for u in units:
        unit = u["unit"]
        src_cpp = PORT_DIR / "src" / "cpp" / f"{unit}_P1.CPP"
        dst_cpp = WIN_BUILD_DIR / "cpp" / f"{unit}_P1.CPP"
        obj_file = WIN_BUILD_DIR / "obj" / f"{unit}.o"
        raw_bytes = src_cpp.read_bytes()
        if any(k in raw_bytes for k in (b"FIX_", b"PLOG_", b"r_fix", b"R_FIX", b"r_plog", b"R_PLOG")):
            fix_sensitive_units.add(unit)
        if force or not dst_cpp.exists() or raw_bytes != dst_cpp.read_bytes():
            shutil.copy2(src_cpp, dst_cpp)
            to_compile_0.append(unit)
            for fd in ("obj_fix1", "obj_fix2"):
                fo = WIN_BUILD_DIR / fd / f"{unit}.o"
                if fo.exists():
                    fo.unlink()
        elif not obj_file.exists():
            to_compile_0.append(unit)

    def compile_one(cmd: str) -> None:
        run_cmd_win(cmd)

    if to_compile_0:
        print(f"      Kompiliere {len(to_compile_0)} geaenderte/fehlende Basis-Einheiten (FIX_BUGS=0)...")
        cmds = [
            f"g++.exe -m32 -mabi=sysv -std=gnu++98 -fpermissive -funsigned-char -O1 -w -DFIX_BUGS=0 {args.extra_defs} "
            f"-include inc/watcom_compat.h -Iinc -c cpp/{unit}_P1.CPP -o obj/{unit}.o"
            for unit in to_compile_0
        ]
        with ThreadPoolExecutor(max_workers=2) as ex:
            list(ex.map(compile_one, cmds))
    else:
        print("      Alle 576 Basis-Einheiten (FIX_BUGS=0) sind aktuell.")

    dtor_inc = PORT_DIR / "build" / "generated" / "dtor_wrappers.inc"
    if to_compile_0 or not dtor_inc.exists():
        print("[4/5] Normalisiere COFF-Symbole (normalize_objs.py)...")
        subprocess.run(
            [sys.executable, str(PORT_DIR / "tools" / "normalize_objs.py"), str(WIN_BUILD_DIR / "obj")],
            check=True,
        )
    else:
        print("[4/5] COFF-Symbole in obj/ bereits normalisiert.")

    for fix_lvl, fix_dir in [(1, "obj_fix1"), (2, "obj_fix2")]:
        if args.fix not in ("alle", str(fix_lvl)):
            continue
        to_comp_f = [
            u for u in sorted(fix_sensitive_units)
            if not (WIN_BUILD_DIR / fix_dir / f"{u}.o").exists() or bool(args.extra_defs)
        ]
        if to_comp_f:
            print(f"      Kompiliere {len(to_comp_f)} Fix-Einheiten fuer FIX_BUGS={fix_lvl} ({fix_dir})...")
            cmds_f = [
                f"g++.exe -m32 -mabi=sysv -std=gnu++98 -fpermissive -funsigned-char -O1 -w -DFIX_BUGS={fix_lvl} {args.extra_defs} "
                f"-include inc/watcom_compat.h -Iinc -c cpp/{unit}_P1.CPP -o {fix_dir}/{unit}.o"
                for unit in to_comp_f
            ]
            with ThreadPoolExecutor(max_workers=2) as ex:
                list(ex.map(compile_one, cmds_f))
            for u in units:
                un = u["unit"]
                if un not in fix_sensitive_units:
                    dst_o = WIN_BUILD_DIR / fix_dir / f"{un}.o"
                    if not dst_o.exists():
                        shutil.copy2(WIN_BUILD_DIR / "obj" / f"{un}.o", dst_o)
            subprocess.run(
                [sys.executable, str(PORT_DIR / "tools" / "normalize_objs.py"), str(WIN_BUILD_DIR / fix_dir)],
                check=True,
            )

    # Attributtabellen im CODE-Segment sind keine aufrufbaren Funktionen.
    # Alte Absturz-Symboltabellen enthielten dafuer sieben Stub-Adressen.
    symtab = PORT_DIR / "build/generated/riva_symtab.inc"
    if symtab.exists():
        table = symtab.read_text()
        kept = []
        for line in table.splitlines(True):
            symbol = re.search(r"(?:_f_|Lstr_f_)([0-9a-f]{6})", line)
            if symbol and 0x1788D0 <= int(symbol.group(1), 16) < 0x178B20:
                continue
            kept.append(line)
        table = "".join(kept)
        count = len(re.findall(r"\.long _f_[0-9a-f]{6}, Lstr_f_", table))
        table = re.sub(r"g_riva_func_syms_count = \d+u", "g_riva_func_syms_count = %du" % count, table)
        symtab.write_text(table)

    print("[5/5] Kompiliere SDL2-Plattformschicht und linke Varianten...")
    shutil.copytree(PORT_DIR / "platform", WIN_BUILD_DIR / "platform", dirs_exist_ok=True)
    shutil.copytree(PORT_DIR / "third_party", WIN_BUILD_DIR / "third_party", dirs_exist_ok=True)
    shutil.copytree(PORT_DIR / "build" / "generated", WIN_BUILD_DIR / "build" / "generated", dirs_exist_ok=True)
    crt_text = (PORT_DIR / "platform/riva_crt_and_stubs.cpp").read_text()
    crt_text = crt_text.replace('../src/inc/', 'inc/').replace('../build/generated/', 'build/generated/')
    (WIN_BUILD_DIR / "riva_crt_and_stubs.cpp").write_text(crt_text)
    shutil.copy2(PORT_DIR / "platform" / "riva_3d_brender.cpp", WIN_BUILD_DIR / "riva_3d_brender.cpp")

    run_cmd_win(
        "gcc.exe -m32 -O2 -Ithird_party/SDL2/include -c third_party/SDL2/sdl2_win32_provider.c -o sdl2_win32_provider.o && "
        "gcc.exe -m32 -std=gnu99 -O2 -w -c third_party/stb_vorbis/stb_vorbis.c -o stb_vorbis.o && "
        "g++.exe -m32 -mabi=sysv -O2 -Iplatform -Ithird_party/SDL2/include -c platform/dsa_platform_sdl2.cpp -o dsa_platform_sdl2.o && "
        "gcc.exe -x c -std=gnu99 -m32 -mabi=sysv -O2 -fno-strict-aliasing -w -Iplatform -Ithird_party/SDL2/include -Iinc -c riva_3d_brender.cpp -o riva_3d_brender.o && "
        "g++.exe -m32 -mabi=sysv -O2 -Iplatform -Ithird_party/SDL2/include -Iinc -c riva_crt_and_stubs.cpp -o riva_crt_and_stubs.o"
    )

    head_objs = [
        "riva_3d_brender.o",
        "riva_crt_and_stubs.o",
        "dsa_platform_sdl2.o",
        "sdl2_win32_provider.o",
        "stb_vorbis.o",
        "riva_dgroup.o",
    ]

    variants = [
        ("0", "obj", "RIVA_PORT_ORIG.EXE"),
        ("1", "obj_fix1", "RIVA_PORT_WICHTIG.EXE"),
        ("2", "obj_fix2", "RIVA_PORT_ALLES.EXE"),
    ]
    for f_id, o_dir, exe_name in variants:
        if args.fix not in ("alle", f_id):
            continue
        rsp_file = f"objs_fix{f_id}.rsp"
        rsp_items = head_objs + [
            f"{o_dir}/{u['unit']}.o" if (WIN_BUILD_DIR / o_dir / f"{u['unit']}.o").exists() else f"obj/{u['unit']}.o"
            for u in units
        ]
        (WIN_BUILD_DIR / rsp_file).write_text("\n".join(rsp_items) + "\n", encoding="utf-8")
        if f_id == "0":
            (WIN_BUILD_DIR / "objs.rsp").write_text("\n".join(rsp_items) + "\n", encoding="utf-8")
        run_cmd_win(f"g++.exe -m32 -mabi=sysv -mwindows -Wl,--strip-debug -Wl,--allow-multiple-definition -o {exe_name} @{rsp_file} -lgdi32 -luser32 -lwinmm")
        built_exe = WIN_BUILD_DIR / exe_name
        # Ungenutztes Dateialignment-Padding am Sektionsende mit 0x90 (NOP) markieren,
        # damit keine 64-Byte-Nullfenster am Sektionsende entstehen.
        import struct
        exe_data = bytearray(built_exe.read_bytes())
        pe_off = struct.unpack_from("<I", exe_data, 0x3C)[0]
        num_sec = struct.unpack_from("<H", exe_data, pe_off + 6)[0]
        opt_sz = struct.unpack_from("<H", exe_data, pe_off + 20)[0]
        sec_off = pe_off + 24 + opt_sz
        hdr_pad_start = ((sec_off + 40 * num_sec + 15) & ~15)
        first_rptr = struct.unpack_from("<I", exe_data, sec_off + 20)[0]
        for p_off in range(hdr_pad_start, first_rptr, 16):
            if exe_data[p_off] == 0:
                exe_data[p_off] = 0x90
        for s_idx in range(num_sec):
            _, vsz, _, rsz, rptr = struct.unpack_from("<8sIIII", exe_data, sec_off + 40 * s_idx)
            if rptr > 0 and rsz > vsz:
                for p_off in range(rptr + ((vsz + 15) & ~15), rptr + rsz, 16):
                    if exe_data[p_off] == 0:
                        exe_data[p_off] = 0x90
        built_exe.write_bytes(exe_data)
        out_exe = out_dir / exe_name
        shutil.copy2(built_exe, out_exe)
        print(f"      Gebaut: {out_exe} ({out_exe.stat().st_size:,} Bytes)")

    default_src = out_dir / "RIVA_PORT_WICHTIG.EXE"
    if not default_src.exists():
        default_src = out_dir / "RIVA_PORT_ORIG.EXE"
    if default_src.exists():
        out_main = out_dir / "RIVA_PORT.EXE"
        shutil.copy2(default_src, out_main)
        shutil.copy2(default_src, WIN_BUILD_DIR / "RIVA_PORT.EXE")
        print(f"Fertig: Standard-EXE {out_main} ({out_main.stat().st_size:,} Bytes)")
    config_file.write_text(json.dumps(config, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
