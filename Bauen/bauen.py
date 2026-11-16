#!/usr/bin/env python3
"""
bauen.py - Vollstaendiger Gesamtbau von RIVA.EXE sowie der fehlerbereinigten
           Fassungen RIVA_FIX_WICHTIG.EXE und RIVA_FIX_ALLES.EXE aus dem
           rekonstruierten C/C++-Quelltext (Quelle/) und dem Basis-Baustand
           (Bauen/baustand.tgz).

Voraussetzungen im Paketordner (eine Ebene ueber Bauen/):
  1. Compiler/          Watcom C/C++ 10.6 (BINNT/, BINW/, H/)
  2. Original/RIVA.EXE  Deutsche GOG-Version V1.12 (2.477.899 Bytes,
                        MD5 fb8f5fc3ba5454c7344c17aaf362de35)
  3. Quelle/            571 C/C++-Einheiten in Quelle/cpp/ sowie 21 Header
                        inkl. R_FIX.H, R_PLOG.H und r_fix.inc in Quelle/inc/
  4. Bauen/baustand.tgz D22-Basisbaum (Anker, Datenobjekte, Laufzeit, Fuellung)

Aufrufe:
  Windows:
    Bauen\\BAUEN.bat
    Bauen\\BAUEN.bat wichtig
    Bauen\\BAUEN.bat alles
  WSL / Linux / Kommandozeile:
    python3 Bauen/bauen.py                 -> Build/RIVA.EXE             (MD5 fb8f5fc3ba5454c7344c17aaf362de35)
    python3 Bauen/bauen.py wichtig         -> Build/RIVA_FIX_WICHTIG.EXE (MD5 8e1fb73fcf6cad374aa6d4076f13a64d)
    python3 Bauen/bauen.py alles           -> Build/RIVA_FIX_ALLES.EXE   (MD5 d8dba0e2ecb2ced9b380ea708b8be25f)
    (alternativ auch mit --fix 1 / --fix 2)
"""

from pathlib import Path
import argparse
import datetime
import hashlib
import json
import os
import re
import shutil
import stat
import struct
import subprocess
import sys
import tarfile
import tempfile
import time

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
PAKET_ROOT = HERE.parent
WERKZEUGE_DIR = HERE / "werkzeuge"
sys.path.insert(0, str(WERKZEUGE_DIR))

import partial_group as pg
import fragment_model as fm
from static_check import (
    ANCHORS,
    FUNKTIONEN_STARTS,
    IMAGE,
    MAP,
    TEILE_ALLE_LINES,
    analyse,
    explicit,
    init_context,
    lib as sc_lib,
)
from exports_d22 import export
from baum_inventar import GOOD, inventory, padding
from order_audit import audit, layout, expected as original_pages
from symbols import symbols
from baum_comdat import existing as existing_comdat

SOLL_GROESSE = 2_477_899
SOLL_MD5 = GOOD
DOS4GW_PREFIX_LEN = 0x38D64
INNER_STUB_LEN = 0x02C90

FIX_SOLL_MD5 = {
    0: "fb8f5fc3ba5454c7344c17aaf362de35",
    1: "8e1fb73fcf6cad374aa6d4076f13a64d",
    2: "d8dba0e2ecb2ced9b380ea708b8be25f",
}

DEFAULT_FLAGS = ["-4r", "-oneatx", "-zp1", "-s"]
FIX_EXE_NAMES = {
    0: ("RIVA.EXE", "RIVA_LE.EXE"),
    1: ("RIVA_FIX_WICHTIG.EXE", "RIVA_FIX_WICHTIG_LE.EXE"),
    2: ("RIVA_FIX_ALLES.EXE", "RIVA_FIX_ALLES_LE.EXE"),
}
SWITCH_HEADER_NAMES = ("r_fix.h", "r_fix.inc", "r_plog.h")
ANCHOR_UNITS = {
    "fz_1788d0",
    "fz_17c708_t1",
    "fz_17c708_t2",
    "fz_17c708_t3",
    "fz_17e4a0_t2",
    "fz_199700_t1",
    "fz_199700_t2",
    "gz_0d451f_t1",
}


def sha256_file(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def _rw_remove(func, path, _):
    try:
        os.chmod(path, stat.S_IWRITE | stat.S_IREAD)
        func(path)
    except Exception:
        pass


def rmtree_safe(path):
    p = Path(path)
    if p.exists():
        if sys.version_info >= (3, 12):
            shutil.rmtree(p, onexc=_rw_remove)
        else:
            shutil.rmtree(p, onerror=_rw_remove)


def find_ci(directory: Path, name: str) -> Path | None:
    cand = directory / name
    if cand.exists():
        return cand
    if directory.is_dir():
        target = name.lower()
        for p in directory.iterdir():
            if p.name.lower() == target:
                return p
    return None


def find_file_recursive(root: Path, filename: str) -> Path | None:
    target = filename.lower()
    if not root.is_dir():
        return None
    for p in root.rglob("*"):
        if p.is_file() and p.name.lower() == target:
            return p
    return None


def locate_original_exe(paket_root: Path) -> Path | None:
    orig_dir = paket_root / "Original"
    if orig_dir.is_dir():
        found = find_ci(orig_dir, "RIVA.EXE") or find_file_recursive(orig_dir, "RIVA.EXE")
        if found:
            return found
    for sp_file in (paket_root / "SPIELPFAD.txt", paket_root.parent.parent.parent / "SPIELPFAD.txt"):
        if sp_file.is_file():
            raw = sp_file.read_text(encoding="utf-8", errors="ignore").strip()
            for cand_dir in (Path(raw), wsl_path_from_win(raw)):
                if cand_dir and cand_dir.is_dir():
                    f = find_ci(cand_dir, "RIVA.EXE")
                    if f:
                        return f
    return None


def wsl_path_from_win(win_path: str) -> Path | None:
    if not win_path:
        return None
    if os.name == "nt":
        return Path(win_path)
    m = re.match(r"^([A-Za-z]):[\\/](.*)$", win_path)
    if m:
        drive = m.group(1).lower()
        rest = m.group(2).replace("\\", "/")
        return Path(f"/mnt/{drive}/{rest}")
    return Path(win_path)


def to_win_path(path: Path) -> str:
    s = str(path.resolve())
    if os.name == "nt":
        return s
    m = re.match(r"^/mnt/([a-zA-Z])/(.*)$", s)
    if m:
        return f"{m.group(1).upper()}:\\" + m.group(2).replace("/", "\\")
    if shutil.which("wslpath"):
        return subprocess.check_output(["wslpath", "-w", s], text=True, stdin=subprocess.DEVNULL).strip()
    return s


def get_win_work_base() -> Path:
    """Liefert ein garantiert leerzeichen- und umlautfreies Arbeitsverzeichnis auf einem
    Windows-Laufwerk (fuer cmd.exe und DOSBox.exe)."""
    if os.name == "nt":
        tmp = Path(tempfile.gettempdir())
        if str(tmp).isascii() and " " not in str(tmp):
            base = tmp / "riva_bau_work"
        else:
            drive = os.environ.get("SystemDrive", "C:")
            base = Path(drive + "\\") / "riva_bau_work"
        base.mkdir(parents=True, exist_ok=True)
        return base

    # Unter WSL: Windows-%TEMP% pruefen
    if shutil.which("cmd.exe"):
        try:
            out = subprocess.check_output(
                ["cmd.exe", "/d", "/c", "echo %TEMP%"],
                stdin=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                text=True,
            ).strip()
            if out and out.isascii() and " " not in out:
                wsl_p = wsl_path_from_win(out)
                if wsl_p and wsl_p.parent.exists():
                    base = wsl_p / "riva_bau_work"
                    base.mkdir(parents=True, exist_ok=True)
                    return base
        except Exception:
            pass
    if Path("/mnt/c/Windows/Temp").is_dir():
        base = Path("/mnt/c/Windows/Temp/riva_bau_work")
        base.mkdir(parents=True, exist_ok=True)
        return base
    base = Path(tempfile.gettempdir()) / "riva_bau_work"
    base.mkdir(parents=True, exist_ok=True)
    return base


def stage_watcom_compiler(compiler_dir: Path, win_work_base: Path) -> Path:
    """Prueft Watcom 10.6 in Compiler/ und stellt eine kompakte Arbeitskopie auf einem
    leerzeichen- und umlautfreien Pfad bereit."""
    wpp = find_file_recursive(compiler_dir, "WPP386.EXE")
    wcc = find_file_recursive(compiler_dir, "WCC386.EXE")
    wlink = find_file_recursive(compiler_dir, "WLINK.EXE")
    stdio_h = find_file_recursive(compiler_dir, "STDIO.H")
    if not (wpp and wcc and wlink and stdio_h):
        raise FileNotFoundError(
            f"Watcom C/C++ 10.6 unvollstaendig in {compiler_dir} "
            f"(benoetigt: WPP386.EXE, WCC386.EXE, WLINK.EXE und H/STDIO.H)."
        )
    watcom_src_root = stdio_h.parent.parent

    # Falls der Quellpfad bereits reines ASCII ohne Leerzeichen ist, direkt nutzbar
    win_src = to_win_path(watcom_src_root)
    if win_src.isascii() and " " not in win_src and (watcom_src_root / "BINW" / "WLINK.EXE").exists():
        return watcom_src_root

    cache_tag = hashlib.sha256(str(watcom_src_root.resolve()).encode("utf-8")).hexdigest()[:12]
    staged = win_work_base / f"watcom_{cache_tag}"
    marker = staged / "FERTIG.TXT"
    if marker.exists():
        return staged

    rmtree_safe(staged)
    staged.mkdir(parents=True, exist_ok=True)

    for sub_name in ("BINNT", "BINB"):
        src_sub = find_ci(watcom_src_root, sub_name)
        if src_sub and src_sub.is_dir():
            dst_sub = staged / sub_name
            dst_sub.mkdir(parents=True, exist_ok=True)
            for p in src_sub.iterdir():
                if p.is_file():
                    shutil.copy2(p, dst_sub / p.name.upper())

    src_h = find_ci(watcom_src_root, "H")
    if src_h and src_h.is_dir():
        dst_h = staged / "H"
        dst_h.mkdir(parents=True, exist_ok=True)
        for p in src_h.iterdir():
            if p.is_file():
                shutil.copy2(p, dst_h / p.name.upper())
            elif p.is_dir() and p.name.upper() == "SYS":
                dst_sys = dst_h / "SYS"
                dst_sys.mkdir(parents=True, exist_ok=True)
                for sp in p.iterdir():
                    if sp.is_file():
                        shutil.copy2(sp, dst_sys / sp.name.upper())

    src_binw = find_ci(watcom_src_root, "BINW") or wlink.parent
    dst_binw = staged / "BINW"
    dst_binw.mkdir(parents=True, exist_ok=True)
    skip_prefixes = (
        "WBRW", "WD", "WPROF", "WR", "WIMG", "WSPY", "WHELP", "WIN",
        "FT", "FOX", "CMIX", "CGUIDE", "CPPLIB", "CLIB", "BKMFC",
        "BKWVP", "DRWATCOM", "CODEVIEW", "DWARF", "COMMDLG", "COMPOBJ", "CTL3D",
    )
    for p in src_binw.iterdir():
        if not p.is_file():
            continue
        uname = p.name.upper()
        if p.suffix.upper() in (".HLP", ".IHP"):
            continue
        if uname.startswith(skip_prefixes) and uname not in ("WDISASM.EXE", "WIN386.EXT"):
            continue
        shutil.copy2(p, dst_binw / uname)

    marker.write_text(str(watcom_src_root), encoding="utf-8")
    return staged


def locate_dosbox(arg_dosbox: str | Path | None, paket_root: Path) -> Path:
    candidates = []
    if arg_dosbox:
        candidates.append(Path(arg_dosbox))
    candidates.extend([
        HERE / "DOSBox" / "DOSBox.exe",
        HERE / "DOSBox.exe",
        HERE / "DOSBox" / "dosbox",
        paket_root / "DOSBOX" / "DOSBox.exe",
    ])
    for sp_file in (paket_root / "SPIELPFAD.txt", paket_root.parent.parent.parent / "SPIELPFAD.txt"):
        if sp_file.is_file():
            raw = sp_file.read_text(encoding="utf-8", errors="ignore").strip()
            for d in (Path(raw), wsl_path_from_win(raw)):
                if d:
                    candidates.append(d / "DOSBOX" / "DOSBox.exe")
                    candidates.append(d / "DOSBox.exe")
    win_gog_paths = [
        r"C:\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania 3\DOSBOX\DOSBox.exe",
        r"C:\Program Files\GOG Galaxy\Games\Realms of Arkania 3\DOSBOX\DOSBox.exe",
        r"C:\GOG Games\Realms of Arkania 3\DOSBOX\DOSBox.exe",
        r"D:\GOG Games\Realms of Arkania 3\DOSBOX\DOSBox.exe",
        r"C:\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania - Shadows over Riva\DOSBOX\DOSBox.exe",
        r"C:\Program Files\GOG Galaxy\Games\Realms of Arkania - Shadows over Riva\DOSBOX\DOSBox.exe",
        r"C:\Program Files (x86)\DOSBox-0.74-3\DOSBox.exe",
        r"C:\Program Files\DOSBox-0.74-3\DOSBox.exe",
        r"C:\Program Files (x86)\DOSBox-0.74-2\DOSBox.exe",
        r"C:\Program Files (x86)\DOSBox-0.74\DOSBox.exe",
    ]
    for wp in win_gog_paths:
        p = wsl_path_from_win(wp)
        if p:
            candidates.append(p)
    if os.name != "nt":
        which_db = shutil.which("dosbox")
        if which_db:
            candidates.append(Path(which_db))

    for c in candidates:
        if c and c.is_file():
            return c.resolve()
    raise FileNotFoundError(
        "DOSBox wurde nicht gefunden. Bitte GOG-Installation von 'Schatten ueber Riva' "
        "bereithalten oder --dosbox PFAD angeben."
    )


def ensure_baustand(baustand_tgz: Path, extract_root: Path) -> tuple[Path, Path]:
    if not baustand_tgz.is_file():
        raise FileNotFoundError(f"Basis-Archiv fehlt: {baustand_tgz}")
    digest = sha256_file(baustand_tgz)
    marker = extract_root / "FERTIG"
    if not marker.exists() or marker.read_text().strip() != digest:
        rmtree_safe(extract_root)
        extract_root.mkdir(parents=True, exist_ok=True)
        with tarfile.open(baustand_tgz, "r:gz") as tar:
            for item in tar.getmembers():
                dest = (extract_root / item.name).resolve()
                if not dest.is_relative_to(extract_root.resolve()) or not (item.isfile() or item.isdir()):
                    raise ValueError("Unsicherer Archiveintrag in baustand.tgz")
            if hasattr(tarfile, "data_filter"):
                tar.extractall(extract_root, filter="data")
            else:
                tar.extractall(extract_root)
        marker.write_text(digest)
    return extract_root / "m", extract_root / "meta"


def parse_opts(text):
    cc = "wpp386"
    flags = list(DEFAULT_FLAGS)
    for line in text.splitlines():
        s = line.strip()
        if s.startswith("// CC "):
            cc = s[6:].strip().lower()
        elif s.startswith("// OPT "):
            flags = s[7:].strip().split()
    return cc, flags


def collect_units(quelle_dir: Path, source_override_dirs=()):
    units = []
    anchors = []
    idx = 0
    cpp_dir = quelle_dir / "cpp"
    for line in TEILE_ALLE_LINES:
        t = line.split("\t")
        if len(t) < 4:
            continue
        u, lo, hi = t[1], int(t[2], 16), int(t[3], 16)
        if u in ANCHOR_UNITS:
            anchors.append(dict(unit=u, lo=lo, hi=hi))
            continue
        override = next(
            (Path(d) / (u + "_P1.CPP") for d in source_override_dirs if (Path(d) / (u + "_P1.CPP")).exists()),
            None,
        )
        src = override
        tier = "override"
        if src is None:
            cand = find_ci(cpp_dir, u + "_P1.CPP") if cpp_dir.is_dir() else None
            if cand is not None:
                src = cand
                tier = "Quelle/cpp"
            else:
                # Fallback falls direkt auf Hauptprojekt-Struktur (p3 / p1) aufgerufen
                p3 = cpp_dir / "p3" / (u + "_P1.CPP")
                p1 = cpp_dir / "p1" / (u + "_P1.CPP")
                if p3.exists():
                    src, tier = p3, "p3"
                elif p1.exists():
                    src, tier = p1, "p1"
        if src is None:
            anchors.append(dict(unit=u, lo=lo, hi=hi))
            continue
        text = src.read_text(encoding="latin1")
        cc, flags = parse_opts(text)
        if not any(f.startswith("-nt=") for f in flags):
            sn = (
                "_TEXT3"
                if lo >= 0x175FFE
                else "_TEXT2"
                if lo >= 0x15DE10
                else "_TEXT1"
                if lo >= 0x15689D
                else None
            )
            if sn:
                flags = list(flags) + [f"-nt={sn}"]
        code = f"U{idx:04d}"
        idx += 1
        units.append(
            dict(
                unit=u,
                code=code,
                source=str(src),
                source_rel=str(src.relative_to(quelle_dir.parent))
                if src.is_relative_to(quelle_dir.parent)
                else str(src),
                tier=tier,
                source_sha256=sha256_file(src),
                lo=lo,
                hi=hi,
                cc=cc,
                options=flags,
                has_plog=("PLOG_" in text),
                has_fix=("FIX_" in text or "PLOG_" in text),
            )
        )
    return units, anchors


def find_headers_and_switches(quelle_dir: Path):
    inc_dir = quelle_dir / "inc"
    cpp_dir = quelle_dir / "cpp"
    search_dirs = [d for d in (inc_dir, cpp_dir, quelle_dir) if d.is_dir()]
    headers = {}
    for d in search_dirs:
        for h in sorted(d.glob("*.[hH]")):
            uname = h.name.upper()
            if uname not in headers:
                headers[uname] = h
    switches = {}
    for name in SWITCH_HEADER_NAMES:
        for d in search_dirs:
            found = find_ci(d, name)
            if found:
                switches[name] = found
                break
    return headers, switches


def run_batch_compile(batch_dir: Path, bat_lines: list[str], staged_watcom: Path, dosbox_exe: Path | None):
    (batch_dir / "GO.BAT").write_text("\r\n".join(bat_lines) + "\r\n", encoding="ascii")
    if os.name == "nt" or shutil.which("cmd.exe"):
        cmd_exe = "cmd.exe"
        subprocess.run(
            [cmd_exe, "/d", "/c", "GO.BAT"],
            cwd=batch_dir,
            check=False,
            stdin=subprocess.DEVNULL,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
    else:
        if dosbox_exe is None:
            raise RuntimeError("Weder cmd.exe noch DOSBox fuer den Compilerlauf verfuegbar.")
        conf_path = batch_dir / "dosbox_compile.conf"
        conf_txt = "\n".join([
            "[sdl]",
            "output=surface",
            "[dosbox]",
            "memsize=63",
            "[cpu]",
            "core=normal",
            "cycles=max",
            "[mixer]",
            "nosound=true",
            "[autoexec]",
            f'mount c "{staged_watcom}"',
            f'mount d "{batch_dir}"',
            "d:",
            "call GO.BAT",
            "exit",
            "",
        ])
        conf_path.write_text(conf_txt, encoding="utf-8")
        env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")
        subprocess.run(
            [str(dosbox_exe), "-conf", str(conf_path), "-noconsole", "-exit"],
            cwd=batch_dir,
            env=env,
            stdin=subprocess.DEVNULL,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )


def compile_all_units(
    units,
    quelle_dir: Path,
    batch_dir: Path,
    staged_watcom: Path,
    dosbox_exe: Path | None,
    fix_level=0,
    fix_exploits=None,
    extra_fix_flags="",
):
    rmtree_safe(batch_dir)
    batch_dir.mkdir(parents=True, exist_ok=True)

    hdr_map, sw_map = find_headers_and_switches(quelle_dir)
    headers_info = {}
    for uname, hpath in sorted(hdr_map.items()):
        shutil.copy2(hpath, batch_dir / uname)
        headers_info[uname] = sha256_file(hpath)

    if fix_level > 0:
        missing_sh = [n for n in SWITCH_HEADER_NAMES if n not in sw_map]
        if missing_sh:
            raise FileNotFoundError(f"Schalter-Header nicht gefunden in Quelle/inc: {missing_sh}")
    switch_info = {}
    for name, spath in sw_map.items():
        shutil.copy2(spath, batch_dir / name)
        shutil.copy2(spath, batch_dir / name.upper())
        switch_info[name] = dict(
            source=str(spath.relative_to(quelle_dir.parent))
            if spath.is_relative_to(quelle_dir.parent)
            else str(spath),
            sha256=sha256_file(spath),
        )

    use_cmd = bool(os.name == "nt" or shutil.which("cmd.exe"))
    wat_win = to_win_path(staged_watcom) if use_cmd else "C:"
    bat_lines = [
        "@echo off",
        f"set WATCOM={wat_win}",
        f"set PATH={wat_win}\\BINNT;{wat_win}\\BINW;%PATH%",
        f"set INCLUDE=.;{wat_win}\\H",
    ]
    extra_parts = (os.environ.get("FIX_EXTRA", "") + " " + extra_fix_flags).split()

    for r in units:
        code = r["code"]
        ext = ".C" if r["cc"] == "wcc386" else ".CPP"
        exe = "WCC386.EXE" if r["cc"] == "wcc386" else "WPP386.EXE"
        shutil.copy2(r["source"], batch_dir / (code + ext))
        opt_parts = list(r["options"])
        if fix_level > 0:
            opt_parts.append(f"-DFIX_BUGS={fix_level}")
            if fix_exploits is not None:
                opt_parts.append(f"-DFIX_EXPLOITS={fix_exploits}")
            if not r.get("has_plog", False):
                opt_parts.append("-DPLOG_AKTIV=0")
            opt_parts.append("-fi=r_fix.h")
            opt_parts += extra_parts
        opt_str = " ".join(opt_parts)
        bat_lines.append(f"{exe} {opt_str} -zq -fo={code}.OBJ {code}{ext} > {code}.ERR")
        if fix_level > 0 and r.get("has_fix", False):
            orig_opt_str = " ".join(r["options"])
            bat_lines.append(
                f"{exe} {orig_opt_str} -DFIX_BUGS=0 -fi=r_fix.h -zq -fo={code}_O.OBJ {code}{ext} > {code}_O.ERR"
            )

    run_batch_compile(batch_dir, bat_lines, staged_watcom, dosbox_exe)
    return headers_info, switch_info


def compile_single_orig_unit(r, quelle_dir: Path, temp_batch_dir: Path, staged_watcom: Path, dosbox_exe: Path | None):
    rmtree_safe(temp_batch_dir)
    temp_batch_dir.mkdir(parents=True, exist_ok=True)
    hdr_map, sw_map = find_headers_and_switches(quelle_dir)
    for uname, hpath in sorted(hdr_map.items()):
        shutil.copy2(hpath, temp_batch_dir / uname)
    for name, spath in sw_map.items():
        shutil.copy2(spath, temp_batch_dir / name)
        shutil.copy2(spath, temp_batch_dir / name.upper())
    code = r["code"]
    ext = ".C" if r["cc"] == "wcc386" else ".CPP"
    exe = "WCC386.EXE" if r["cc"] == "wcc386" else "WPP386.EXE"
    shutil.copy2(r["source"], temp_batch_dir / (code + ext))
    opt_str = " ".join(r["options"])
    use_cmd = bool(os.name == "nt" or shutil.which("cmd.exe"))
    wat_win = to_win_path(staged_watcom) if use_cmd else "C:"
    bat_lines = [
        "@echo off",
        f"set WATCOM={wat_win}",
        f"set PATH={wat_win}\\BINNT;{wat_win}\\BINW;%PATH%",
        f"set INCLUDE=.;{wat_win}\\H",
        f"{exe} {opt_str} -DFIX_BUGS=0 -fi=r_fix.h -zq -fo={code}.OBJ {code}{ext} > {code}.ERR",
    ]
    run_batch_compile(temp_batch_dir, bat_lines, staged_watcom, dosbox_exe)
    return temp_batch_dir / f"{code}.OBJ"


def unit_symbol_bindings(u, text):
    bindings = {
        "gz_01eb40": {"W?$dt:D$n()_": 0x01EBD0},
        "ship2": {
            "W?$dt:X1034b0$n()_": 0x107280,
            "W?$ct:X1034b0$n()_": 0x1034B0,
        },
        "star2": {"W?$dt:X118e60$n()_": 0x11A880},
    }.get(u, {})
    stripped = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    for m_ct in re.finditer(r"//@\s*f_([0-9a-fA-F]{6})\s*\n\s*X\1::X\1\s*\(", stripped):
        sym_ct = f"W?$ct:X{m_ct[1]}$n()_"
        bindings = dict(bindings, **{sym_ct: int(m_ct[1], 16)})
    return bindings


def build_fix_unit_model(r, fix_raw_obj, orig_work, orig_md, bindings):
    orig_ren = {}
    if (orig_work / "names.json").exists():
        orig_ren.update(json.loads((orig_work / "names.json").read_text()))
    for k, v in MAP.items():
        orig_ren.setdefault(k, f"L{v:06X}")
    for k, v in orig_md.get("names", {}).items():
        orig_ren[k] = f"L{v:06X}"
    for k, v in bindings.items():
        orig_ren[k] = f"L{v:06X}"

    orig_clean = Path(orig_md["raw"])
    orig_meta = pg.r3_reloc.parse(orig_clean)
    orig_obj = pg.lib["omf"].modules(str(orig_clean))[0]
    orig_code_sids = {i for i, s in orig_obj["segs"].items() if s["cls"] == "CODE" and s["data"]}

    orig_dropped = {
        n
        for d in orig_md.get("dropped_comdats", [])
        for n in (d.get("names", []) if "names" in d else ([d["name"]] if "name" in d else []))
    }
    orig_pub_addrs = {}
    for sid, off, name in orig_meta["pubs"]:
        if sid not in orig_code_sids or name in orig_dropped:
            continue
        addr = explicit(name) or bindings.get(name) or MAP.get(name)
        if addr is None and name in orig_ren and re.fullmatch(r"L[0-9A-Fa-f]{6}", orig_ren[name]):
            addr = int(orig_ren[name][1:], 16)
        if addr is not None:
            orig_pub_addrs[name] = addr

    orig_seg_bases = {}
    for db in orig_md.get("data_bindings", []):
        owner = tuple(db["owner"])
        if "anchors" in db and db["anchors"]:
            for off_k, a_val in db["anchors"].items():
                orig_seg_bases[owner] = int(a_val) - int(off_k)
                break

    work_fix = Path(r["details"]["work"])
    fix_clean = work_fix / "clean.OBJ"
    sc_lib["clean_comdats"](fix_raw_obj, fix_clean, orig_ren)
    fix_clean, lidata = fm.expand_lidata(fix_clean)
    raw_bytes = fix_clean.read_bytes()
    meta = pg.r3_reloc.parse(fix_clean)
    obj = pg.lib["omf"].modules(str(fix_clean))[0]
    fx = pg.omf_extra.fixups(raw_bytes)

    owners = {("seg", i): s for i, s in obj["segs"].items() if s["cls"] == "CODE" and s["data"]}
    if not owners:
        raise ValueError(f'Kein CODE in Fix-Objekt: {r["unit"]}')
    cds = {c["name"]: c for c in obj["comdats"]}
    for name, c in cds.items():
        if obj["segs"][c["seg"]]["cls"] == "CODE":
            owners[("comdat", name)] = c

    segment_ids = {(s["name"], s["cls"], ""): ("seg", i) for i, s in obj["segs"].items()}
    for ss, p_off, p_name in meta["pubs"]:
        if ("seg", ss) in orig_seg_bases:
            orig_pub_addrs.setdefault(p_name, orig_seg_bases[("seg", ss)] + p_off)

    def resolve_ext_symbol(name):
        a = explicit(name) or bindings.get(name) or orig_pub_addrs.get(name) or MAP.get(name)
        if a is None and name in orig_ren and re.fullmatch(r"L[0-9A-Fa-f]{6}", orig_ren[name]):
            a = int(orig_ren[name][1:], 16)
        return a

    code_segs = [k for k in owners if k[0] == "seg"]
    if len(code_segs) != 1:
        raise ValueError(f'Mehrere aktive CODE-Segmente in Fix-Objekt: {r["unit"]}')
    main_key = code_segs[0]
    main_sid = main_key[1]
    main_body = owners[main_key]

    pubs_in_main = sorted([(off, name) for s, off, name in meta["pubs"] if s == main_sid], key=lambda x: x[0])
    mapped_pubs = {}
    local_helper_pubs = {}
    dropped_ranges = []

    for idx_p, (off, name) in enumerate(pubs_in_main):
        next_off = pubs_in_main[idx_p + 1][0] if idx_p + 1 < len(pubs_in_main) else len(main_body["data"])
        addr = resolve_ext_symbol(name)
        if addr is not None and name not in orig_dropped:
            mapped_pubs[name] = (off, addr)
        elif "riva_plog_" in name:
            local_helper_pubs[name] = off
        elif name in orig_dropped:
            dropped_ranges.append((off, next_off, name))
        else:
            is_ref = any(f["target"] == ("external", name) for f in fx)
            if is_ref:
                local_helper_pubs[name] = off
            else:
                dropped_ranges.append((off, next_off, name))

    if not mapped_pubs:
        raise ValueError(f'Keine gebundenen Public-Symbole in Fix-Objekt: {r["unit"]}')

    start_off = 0
    while any(d_lo == start_off for d_lo, d_hi, _ in dropped_ranges):
        start_off = next(d_hi for d_lo, d_hi, _ in dropped_ranges if d_lo == start_off)

    end_off = len(main_body["data"])
    last_pub_off = max(v[0] for v in mapped_pubs.values())
    trimmed_end = fm.payload_end(main_body, last_pub_off, end_off)
    max_seg_target = 0
    for f in fx:
        if tuple(f["owner"]) == main_key and f["target"][0] == "segment" and tuple(f["target"][1]) in segment_ids:
            if segment_ids[tuple(f["target"][1])] == main_key:
                val = (
                    int.from_bytes(main_body["data"][f["offset"] : f["offset"] + 4], "little")
                    + f["displacement"]
                ) & 0xFFFFFFFF
                max_seg_target = max(max_seg_target, val + 4)
        if tuple(f["owner"]) == main_key and start_off <= f["offset"] < end_off:
            max_seg_target = max(max_seg_target, f["offset"] + f["width"])
    end_off = max(trimmed_end, min(end_off, max_seg_target))

    orig_main_chunks = [
        c for c in orig_md["chunks"] if any(tuple(p["owner"]) == main_key for p in c["parts"])
    ]
    orig_main_lo = min(c["address"] for c in orig_main_chunks)
    orig_main_hi = max(c["address"] + c["length"] for c in orig_main_chunks)

    pub_offsets = {}
    for name, (off, addr) in mapped_pubs.items():
        if start_off <= off < end_off:
            pub_offsets[addr] = off - start_off

    main_data = bytearray(main_body["data"][start_off:end_off])
    embedded_const_offsets = {}

    def embed_const_symbol(sym_name):
        if sym_name in embedded_const_offsets:
            return embedded_const_offsets[sym_name]
        for ss, p_off, p_name in meta["pubs"]:
            if p_name == sym_name and ("seg", ss) not in owners:
                seg_body = obj["segs"][ss]
                pubs_ss = sorted(o for s2, o, _ in meta["pubs"] if s2 == ss)
                next_o = next((o for o in pubs_ss if o > p_off), len(seg_body["data"]))
                while len(main_data) % 4 != 0:
                    main_data.append(0)
                emb_off = len(main_data)
                main_data.extend(seg_body["data"][p_off:next_o])
                embedded_const_offsets[sym_name] = emb_off
                return emb_off
        return None

    main_fixups = []
    for f in fx:
        if tuple(f["owner"]) != main_key or not (start_off <= f["offset"] < end_off):
            continue
        if f["width"] != 4 or f["location"] not in (9, 13):
            raise ValueError(f'Nicht unterstuetzter Fixuptyp in {r["unit"]}: {f}')
        rel_off = f["offset"] - start_off
        val = int.from_bytes(main_body["data"][f["offset"] : f["offset"] + 4], "little")
        add = (val + f["displacement"]) & 0xFFFFFFFF
        target = f["target"]
        if target[0] == "external":
            tname = target[1]
            if tname in local_helper_pubs:
                helper_off = local_helper_pubs[tname] - start_off
                main_fixups.append(
                    dict(
                        original=f,
                        address=orig_main_lo + rel_off,
                        piece_offset=rel_off,
                        value=val,
                        add=add,
                        target=None,
                        seg_target_offset=(helper_off + add) & 0xFFFFFFFF,
                    )
                )
            else:
                ext_addr = resolve_ext_symbol(tname)
                if ext_addr is not None:
                    resolved = (ext_addr + add) & 0xFFFFFFFF
                    main_fixups.append(
                        dict(
                            original=f,
                            address=orig_main_lo + rel_off,
                            piece_offset=rel_off,
                            value=val,
                            add=add,
                            target=resolved,
                        )
                    )
                else:
                    emb_off = embed_const_symbol(tname)
                    if emb_off is None:
                        raise ValueError(f'Unbekanntes externes Symbol in Fix-Objekt {r["unit"]}: {tname}')
                    main_fixups.append(
                        dict(
                            original=f,
                            address=orig_main_lo + rel_off,
                            piece_offset=rel_off,
                            value=val,
                            add=add,
                            target=None,
                            seg_target_offset=(emb_off + add) & 0xFFFFFFFF,
                        )
                    )
        elif target[0] == "segment":
            dst = segment_ids.get(tuple(target[1]))
            if dst == main_key:
                main_fixups.append(
                    dict(
                        original=f,
                        address=orig_main_lo + rel_off,
                        piece_offset=rel_off,
                        value=val,
                        add=add,
                        target=None,
                        seg_target_offset=(add - start_off) & 0xFFFFFFFF,
                    )
                )
            elif dst in orig_seg_bases:
                resolved = (orig_seg_bases[dst] + add) & 0xFFFFFFFF
                main_fixups.append(
                    dict(
                        original=f,
                        address=orig_main_lo + rel_off,
                        piece_offset=rel_off,
                        value=val,
                        add=add,
                        target=resolved,
                    )
                )
            else:
                pubs_dst = sorted((o, n) for ss, o, n in meta["pubs"] if ("seg", ss) == dst and o <= add)
                if pubs_dst:
                    p_off, p_name = pubs_dst[-1]
                    p_addr = resolve_ext_symbol(p_name)
                    if p_addr is not None:
                        resolved = (p_addr + (add - p_off)) & 0xFFFFFFFF
                        main_fixups.append(
                            dict(
                                original=f,
                                address=orig_main_lo + rel_off,
                                piece_offset=rel_off,
                                value=val,
                                add=add,
                                target=resolved,
                            )
                        )
                        continue
                raise ValueError(f'Ungebundenes Segmentziel in Fix-Objekt {r["unit"]}: {target}')
        else:
            raise ValueError(f'Unbekannte Fixup-Zielart in {r["unit"]}: {target}')

    main_data = bytes(main_data)
    end_off = start_off + len(main_data)
    chunks = [
        dict(
            owner=main_key,
            offset=start_off,
            end=end_off,
            address=orig_main_lo,
            orig_end_address=orig_main_hi,
            length=len(main_data),
            kind="fix_joined",
            data=main_data,
            fixups=main_fixups,
            pub_offsets={str(k): v for k, v in pub_offsets.items()},
            changed_by_fix=True,
            parts=[
                dict(
                    owner=main_key,
                    offset=start_off,
                    end=end_off,
                    address=orig_main_lo,
                    orig_end_address=orig_main_hi,
                    sha256=hashlib.sha256(main_data).hexdigest(),
                    pub_offsets={str(k): v for k, v in pub_offsets.items()},
                    changed_by_fix=True,
                )
            ],
        )
    ]

    orig_comdat_chunks = [
        c for c in orig_md["chunks"] if any(p["owner"][0] == "comdat" for p in c["parts"])
    ]
    for oc in orig_comdat_chunks:
        for p in oc["parts"]:
            if p["owner"][0] != "comdat":
                continue
            cname = p["owner"][1]
            caddr = p["address"]
            orig_clen = p["end"] - p["offset"]
            if cname not in cds:
                raise ValueError(f'Benoetigter CODE-COMDAT fehlt in Fix-Objekt {r["unit"]}: {cname}')
            cbody = cds[cname]
            cend = fm.payload_end(cbody, 0, len(cbody["data"]))
            cdata = bytes(cbody["data"][:cend])
            cfixups = []
            for f in fx:
                if tuple(f["owner"]) != ("comdat", cname) or not (0 <= f["offset"] < cend):
                    continue
                val = int.from_bytes(cdata[f["offset"] : f["offset"] + 4], "little")
                add = (val + f["displacement"]) & 0xFFFFFFFF
                if f["target"][0] == "external":
                    ext_addr = resolve_ext_symbol(f["target"][1])
                    if ext_addr is None:
                        raise ValueError(f'Unbekanntes COMDAT-Ziel in {r["unit"]}: {f["target"][1]}')
                    cfixups.append(
                        dict(
                            original=f,
                            address=caddr + f["offset"],
                            piece_offset=f["offset"],
                            value=val,
                            add=add,
                            target=(ext_addr + add) & 0xFFFFFFFF,
                        )
                    )
                else:
                    raise ValueError(f"Segment-Fixup in COMDAT {cname} nicht unterstuetzt")
            chunks.append(
                dict(
                    owner=("comdat", cname),
                    offset=0,
                    end=cend,
                    address=caddr,
                    orig_end_address=caddr + orig_clen,
                    length=len(cdata),
                    kind="comdat",
                    data=cdata,
                    fixups=cfixups,
                    pub_offsets={str(caddr): 0},
                    changed_by_fix=True,
                    parts=[
                        dict(
                            owner=("comdat", cname),
                            offset=0,
                            end=cend,
                            address=caddr,
                            orig_end_address=caddr + orig_clen,
                            sha256=hashlib.sha256(cdata).hexdigest(),
                            pub_offsets={str(caddr): 0},
                            changed_by_fix=True,
                        )
                    ],
                )
            )

    chunks.sort(key=lambda c: c["address"])
    return dict(
        unit=r["unit"],
        source=r["source"],
        source_sha256=r["source_sha256"],
        raw=str(fix_clean),
        raw_sha256=hashlib.sha256(raw_bytes).hexdigest(),
        chunks=chunks,
        names=orig_md.get("names", {}),
        dropped_comdats=orig_md.get("dropped_comdats", []),
        data_bindings=orig_md.get("data_bindings", []),
        lidata=lidata,
        reconstructed_rel32=[],
        changed_by_fix=True,
    )


def model_all_units(units, quelle_dir: Path, batch_dir: Path, work_root: Path, staged_watcom: Path, dosbox_exe: Path | None, fix_level=0):
    rmtree_safe(work_root)
    work_root.mkdir(parents=True, exist_ok=True)
    fm.HERE = work_root

    out = []
    errors = []
    for r in units:
        u = r["unit"]
        code = r["code"]
        src = Path(r["source"])
        work = work_root / u
        work.mkdir(parents=True)
        shutil.copy2(src, work / "source.CPP")
        obj_file = batch_dir / f"{code}.OBJ"
        if not obj_file.exists():
            err_txt = (
                (batch_dir / f"{code}.ERR").read_text(errors="replace")
                if (batch_dir / f"{code}.ERR").exists()
                else "Kein OBJ erzeugt"
            )
            row = dict(r, good=False, stage="compile", error=err_txt.strip())
            out.append(row)
            errors.append(dict(unit=u, stage="compile", error=row["error"]))
            continue
        shutil.copy2(obj_file, work / "raw.OBJ")

        text = src.read_text(encoding="latin1")
        detail = dict(
            unit=u,
            source=str(src),
            source_sha256=r["source_sha256"],
            lo=r["lo"],
            hi=r["hi"],
            name="C%06X" % r["lo"],
            legacy_name=code,
            work=str(work),
            options=r["options"],
            origin="native Uebersetzung" if fix_level == 0 else f"Fix-Uebersetzung (-DFIX_BUGS={fix_level})",
            gate_status="OK",
        )
        try:
            analyse(detail)
            if not detail.get("error"):
                exp_obj, exp_names = export(detail)
                detail["export_object"] = exp_obj
                detail["exports"] = exp_names
        except Exception as e:
            detail["error"] = str(e)

        row = dict(
            unit=u,
            code=code,
            cc=r["cc"],
            options=r["options"],
            source=str(src),
            source_rel=r["source_rel"],
            tier=r["tier"],
            source_sha256=r["source_sha256"],
            lo=r["lo"],
            hi=r["hi"],
            details=detail,
            whole_module_error=detail.get("error"),
        )
        bindings = unit_symbol_bindings(u, text)
        before = {name: fm.MAP.get(name) for name in bindings}
        if bindings:
            fm.MAP.update(bindings)
            row["additional_symbol_bindings"] = bindings
            row["details"]["original_comdat_names"] = {
                **row["details"].get("original_comdat_names", {}),
                **bindings,
            }
        try:
            md = fm.model(row)
            row["model"] = fm.serializable(md)
            row["good"] = True
            row["changed_by_fix"] = False
        except Exception as e:
            if fix_level > 0:
                try:
                    precompiled_orig = batch_dir / f"{code}_O.OBJ"
                    if precompiled_orig.exists():
                        orig_obj_path = precompiled_orig
                        orig_batch = None
                    else:
                        orig_batch = batch_dir.parent / f"_compile_orig_ref_tmp_{os.getpid()}"
                        orig_obj_path = compile_single_orig_unit(
                            r, quelle_dir, orig_batch, staged_watcom, dosbox_exe
                        )
                    orig_work = work_root / (u + "__orig_ref")
                    orig_work.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(src, orig_work / "source.CPP")
                    shutil.copy2(orig_obj_path, orig_work / "raw.OBJ")
                    if orig_batch is not None:
                        rmtree_safe(orig_batch)
                    orig_detail = dict(
                        unit=u,
                        source=str(src),
                        source_sha256=r["source_sha256"],
                        lo=r["lo"],
                        hi=r["hi"],
                        name="C%06X" % r["lo"],
                        legacy_name=code,
                        work=str(orig_work),
                        options=r["options"],
                        origin="Original-Referenz (FIX_BUGS=0)",
                        gate_status="OK",
                        original_comdat_names=dict(bindings),
                    )
                    analyse(orig_detail)
                    if not orig_detail.get("error"):
                        exp_obj, exp_names = export(orig_detail)
                        orig_detail["export_object"] = exp_obj
                        orig_detail["exports"] = exp_names
                    orig_row = dict(row, details=orig_detail)
                    orig_md = fm.model(orig_row)
                    fix_md = build_fix_unit_model(row, work / "raw.OBJ", orig_work, orig_md, bindings)
                    row["model"] = fm.serializable(fix_md)
                    row["good"] = True
                    row["changed_by_fix"] = True
                except Exception as fix_exc:
                    row["good"] = False
                    row["stage"] = "fix_model"
                    row["error"] = str(fix_exc)
                    errors.append(dict(unit=u, stage="fix_model", error=str(fix_exc), orig_diff=str(e)))
            else:
                row["good"] = False
                row["stage"] = "fragment_model"
                row["error"] = str(e)
                errors.append(
                    dict(unit=u, stage="fragment_model", error=str(e), detail_error=detail.get("error"))
                )
        finally:
            for name, val in before.items():
                if val is None:
                    fm.MAP.pop(name, None)
                else:
                    fm.MAP[name] = val
        out.append(row)
    return out, errors


def extract_views(base, codebase, dest, names, lay, all_publics, needed_targets):
    out = []
    for name in sorted(names, key=lambda n: lay[n][0]):
        original = base / (name + ".OBJ")
        raw = original.read_bytes()
        obj = pg.lib["omf"].modules(str(original))[0]
        data = {i: s for i, s in obj["segs"].items() if s["cls"] != "CODE" and s["data"]}
        if not data:
            continue
        assert not obj["comdats"]
        code = {i for i, s in obj["segs"].items() if s["cls"] == "CODE"}
        assert len(code) == 1
        sid = next(iter(code))
        lo = lay[name][0]
        fx = pg.omf_extra.fixups(raw)
        meta = pg.r3_reloc.parse(original)
        assert all(f["owner"] == ("seg", sid) for f in fx), "Datenfixups brauchen gesonderte Behandlung"
        targets = {}
        for f in fx:
            if f["target"][0] != "external" or f["target"][1].startswith("L"):
                continue
            at = lo + f["offset"]
            value = int.from_bytes(obj["segs"][sid]["data"][f["offset"] : f["offset"] + 4], "little")
            target = (pg.want(at, f["relative"]) - value - f["displacement"]) & 0xFFFFFFFF
            n = f["target"][1]
            assert n not in targets or targets[n] == target
            targets[n] = target
        bases = {}
        for ds, off, n in meta["pubs"]:
            if ds in data:
                if n in targets:
                    address = targets[n] - off
                    assert ds not in bases or bases[ds] == address
                    bases[ds] = address
                elif re.fullmatch(r"L[0-9A-F]{6}", n):
                    address = int(n[1:], 16) - off
                    assert ds not in bases or bases[ds] == address
                    bases[ds] = address
        assert set(bases) == set(data), (name, bases, list(data))
        for ds, s in data.items():
            a = bases[ds]
            assert bytes(s["data"]) == pg.IMAGE[a - 0x10000 : a - 0x10000 + len(s["data"])], name
        for ds, off, n in meta["pubs"]:
            if ds in data:
                targets[n] = bases[ds] + off
        aliases = {(ds, off) for ds, off, n in meta["pubs"] if ds in data}
        aliases.update(
            (ds, a - start)
            for ds, start in bases.items()
            for a in needed_targets
            if start <= a < start + len(data[ds]["data"])
        )

        def convert(keep_code):
            result = bytearray()
            segno = 0
            last_keep = True
            for typ, body0 in pg.r3_reloc.records(raw):
                body = bytearray(body0)
                if typ in (0x98, 0x99):
                    segno += 1
                    if (segno in code) != keep_code:
                        at = 1 + (3 if body[0] >> 5 == 0 else 0)
                        width = 4 if typ == 0x99 else 2
                        body[at : at + width] = bytes(width)
                elif typ in (0x90, 0x91, 0xB6, 0xB7):
                    _, at = pg.r3_reloc.idx(body, 0)
                    sn, at = pg.r3_reloc.idx(body, at)
                    assert sn != 0
                    if (sn in code) != keep_code:
                        continue
                elif typ in (0xA0, 0xA1, 0xA2, 0xA3):
                    sn, _ = pg.r3_reloc.idx(body, 0)
                    last_keep = (sn in code) == keep_code
                    if not last_keep:
                        continue
                elif typ in (0x9C, 0x9D):
                    if not last_keep:
                        continue
                elif typ in (0x8C, 0xB4) and keep_code:
                    at = 0
                    rewritten = bytearray()
                    mapped = []
                    while at < len(body):
                        length = body[at]
                        n = body[at + 1 : at + 1 + length].decode("latin1")
                        at += 1 + length
                        ti, at = pg.r3_reloc.idx(body, at)
                        mapped.append(n in targets)
                        if n in targets:
                            n = "L%06X" % targets[n]
                        encoded = n.encode("latin1")
                        rewritten += bytes([len(encoded)]) + encoded + pg.ix(ti)
                    body = rewritten
                    if typ == 0xB4 and any(mapped):
                        assert all(mapped), "Gemischte lokale Externliste gesondert aufteilen"
                        typ = 0x8C
                elif typ in (0x8A, 0x8B):
                    assert body == b"\0", "Programmeinstieg nicht verschieben"
                    if not keep_code:
                        for ds, off in sorted(aliases):
                            alias = "L%06X" % (bases[ds] + off)
                            if alias in all_publics:
                                continue
                            all_publics.add(alias)
                            nb = alias.encode("ascii")
                            result += pg.record(
                                0x91,
                                b"\0"
                                + pg.ix(ds)
                                + bytes([len(nb)])
                                + nb
                                + struct.pack("<I", off)
                                + b"\0",
                            )
                result += pg.record(typ, body)
            return bytes(result)

        code_view = codebase / (name + ".OBJ")
        code_view.write_bytes(convert(True))
        data_name = "D%06X" % lo
        data_path = dest / (data_name + ".OBJ")
        data_path.write_bytes(convert(False))
        for path, wanted in [(code_view, True), (data_path, False)]:
            after = pg.lib["omf"].modules(str(path))[0]
            for ds, s in obj["segs"].items():
                assert bytes(after["segs"][ds]["data"]) == (
                    bytes(s["data"]) if (s["cls"] == "CODE") == wanted else b""
                ), (name, path, ds)
        out.append(
            dict(
                name=data_name,
                original_module=name,
                original_sha256=hashlib.sha256(raw).hexdigest(),
                sha256=hashlib.sha256(data_path.read_bytes()).hexdigest(),
                code_view_sha256=hashlib.sha256(code_view.read_bytes()).hexdigest(),
                segments=[
                    dict(
                        segment=ds,
                        address=bases[ds],
                        length=len(s["data"]),
                        sha256=hashlib.sha256(bytes(s["data"])).hexdigest(),
                    )
                    for ds, s in data.items()
                ],
                symbols=targets,
                numeric_aliases=[
                    dict(segment=ds, offset=off, address=bases[ds] + off)
                    for ds, off in sorted(aliases)
                ],
                origin="Unveraenderte native C++-Daten aus dem geprueften D22-Baum; nur CODE entfernt, Datenmarken ergaenzt.",
            )
        )
    return out


def make_normal_group(
    base,
    m,
    name,
    lo,
    hi,
    grp_pieces,
    dest,
    basenames,
    retain,
    allowed,
    wrapper_segment,
    preserved_publics,
    base_layout,
    global_rows,
    orig_pages_tuple,
):
    pieces = [dict(p) for p in grp_pieces]
    intervals = [(c["address"], c["address"] + len(c["data"])) for c in pieces]
    ff = []
    comdat_publics = {}
    for basename in basenames:
        baselo, basehi = base_layout[basename]
        raw = (base / (basename + ".OBJ")).read_bytes()
        obj = pg.lib["omf"].modules(str(base / (basename + ".OBJ")))[0]
        if obj["comdats"]:
            sid, body = next(
                (i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and len(s["data"])
            )
            old_fixes, saved, extra_pubs = existing_comdat(
                base / (basename + ".OBJ"), baselo, basehi, intervals, retain, allowed
            )
            ff += old_fixes
            pieces += saved
            comdat_publics[basename] = extra_pubs
            continue
        active = [(i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
        assert len(active) == 1 and not obj["comdats"]
        sid, body = active[0]
        assert len(body["data"]) == basehi - baselo
        assert not any(s["data"] for s in obj["segs"].values() if s["cls"] != "CODE")
        labels = {
            baselo + o
            for sid0, o, n in pg.r3_reloc.parse(base / (basename + ".OBJ"))["pubs"]
            if sid0 == sid
        }
        fx = pg.omf_extra.fixups(raw)
        baseff = []
        for f in fx:
            assert f["owner"] == ("seg", sid) and (
                (f["width"] == 4 and f["location"] in (9, 13))
                or (f["width"] == 6 and f["location"] == 11 and not f["relative"])
            )
            at = baselo + f["offset"]
            val = int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little")
            add = (val + f["displacement"]) & 0xFFFFFFFF
            target = f["target"]
            if target[0] == "external":
                resolved = (int(target[1][1:], 16) + add) & 0xFFFFFFFF
                assert target[1].startswith("L")
            elif target[0] == "segment":
                resolved = baselo + add
            else:
                raise ValueError("Unbelegtes ASM-Ziel " + str(target))
            expected_target = (
                pg.LE[at][1]
                if f["width"] == 6 and pg.LE.get(at, (None,))[0] == 6
                else pg.want(at, f["relative"])
            )
            assert resolved == expected_target, (hex(at), resolved, expected_target)
            baseff.append(
                dict(original=f, address=at, value=val, add=add, want=resolved, target=resolved)
            )
        ff += baseff
        for typ, b in pg.r3_reloc.records(raw):
            if typ not in (0xA0, 0xA1):
                continue
            sn, j = pg.r3_reloc.idx(b, 0)
            w = 4 if typ & 1 else 2
            off = int.from_bytes(b[j : j + w], "little")
            data = b[j + w :]
            assert sn == sid
            for left, right in pg.subtract(baselo + off, baselo + off + len(data), intervals):
                cuts = (
                    [left]
                    + sorted(
                        {x for x in labels if left < x < right}
                        | {x for g in allowed for x in (g["lo"], g["hi"]) if left < x < right}
                    )
                    + [right]
                )
                for a, z in zip(cuts, cuts[1:]):
                    refs = [f for f in baseff if a <= f["address"] < z]
                    assert all(f["address"] + f["original"]["width"] <= z for f in refs)
                    pieces.append(
                        retain(
                            basename,
                            baselo,
                            sid,
                            a,
                            z,
                            data[a - baselo - off : z - baselo - off],
                            refs,
                            raw,
                        )
                    )
    pieces.sort(key=lambda c: c["address"])
    at = lo
    owner = {}
    for i, c in enumerate(pieces):
        assert c["address"] == at, ("Luecke/Overlap", hex(at), hex(c["address"]))
        at += len(c["data"])
        for f in c["fixups"]:
            assert f["address"] not in owner
            owner[f["address"]] = i
    assert at == hi
    expected = [f["address"] for f in ff if not f["original"]["relative"]]
    actual = {f["address"] for c in pieces for f in c["fixups"] if not f["original"]["relative"]}
    assert set(expected) == actual
    edges = {i: set() for i in range(len(pieces))}
    degree = [0] * len(pieces)
    for i, c in enumerate(pieces):
        seq = [f["address"] for f in c["fixups"] if not f["original"]["relative"]]
        assert set(seq) == {a for a in expected if owner[a] == i}
    pages, sizes, _ = orig_pages_tuple
    streams = []
    block_choices = []
    for pg_idx, page in enumerate(pages):
        if not any(lo <= a < hi for a in page):
            continue
        wanted = set(page)
        before = [r["address"] for r in global_rows if r["address"] in wanted]
        candidates = [before]

        def fits(candidate):
            outsiders = [a for a in candidate if a not in owner]
            if outsiders != [a for a in before if a not in owner]:
                return False
            signature = lambda seq: [a if a not in owner else "GROUP" for a in seq]

            def compact(seq):
                out = []
                for a in signature(seq):
                    if a != "GROUP" or not out or out[-1] != "GROUP":
                        out.append(a)
                return out

            if compact(candidate) != compact(before):
                return False
            groups = []
            for a in candidate:
                if a not in owner:
                    continue
                v = owner[a]
                if not groups or groups[-1] != v:
                    groups.append(v)
            if len(groups) != len(set(groups)):
                return False
            for i in groups:
                own = [
                    f["address"]
                    for f in pieces[i]["fixups"]
                    if not f["original"]["relative"] and f["address"] in wanted
                ]
                if own != [a for a in candidate if owner.get(a) == i]:
                    return False
            return True

        if not fits(before):
            candidates += pg.inverse(page, {a: sizes[(pg_idx, a)] for a in page})
        choices = [c for c in candidates if fits(c)]
        if not choices:
            raise ValueError("Keine ganze Beitragsfolge fuer Seite %d" % pg_idx)
        chosen = choices[0]
        sequence = [a for a in chosen if a in owner]
        streams.append(sequence)
        if chosen != before:
            block_choices.append(
                dict(
                    page=pg_idx,
                    reason="Mehrdeutige Umkehrung der 512-Byte-Blockliste; ganze Funktionen bleiben zusammen",
                    input=chosen,
                )
            )
        for a, b in zip(sequence, sequence[1:]):
            x, y = owner[a], owner[b]
            if x != y and y not in edges[x]:
                edges[x].add(y)
                degree[y] += 1
    ready = [i for i, d in enumerate(degree) if not d]
    pg.heapq.heapify(ready)
    order = []
    while ready:
        i = pg.heapq.heappop(ready)
        order.append(i)
        for j in edges[i]:
            degree[j] -= 1
            if not degree[j]:
                pg.heapq.heappush(ready, j)
    assert len(order) == len(pieces), ("Zyklus", name, [hex(pieces[i]["address"]) for i, d in enumerate(degree) if d])
    outname = "B%06X" % lo
    source = ("GESAMTBAU source-bound link " + name + ".OBJ").encode()
    seg, segattr = wrapper_segment(base, basenames[0])
    out = bytearray(pg.record(0x80, bytes([len(source)]) + source))
    out += pg.record(0x96, b"\0" + bytes([len(seg)]) + seg.encode() + b"\x04CODE")
    out += pg.record(0x99, bytes([segattr]) + struct.pack("<I", hi - lo) + b"\x02\x03\x01")
    targets = sorted({f["target"] for c in pieces for f in c["fixups"]})
    ext = {a: i + 1 for i, a in enumerate(targets)}
    for k in range(0, len(targets), 70):
        out += pg.record(0x8C, b"".join(b"\x07" + ("L%06X" % a).encode() + b"\0" for a in targets[k : k + 70]))
    inputs = [n for n, (a, b) in base_layout.items() if a < hi and b > lo and a < b]
    named_pubs = []
    pubs = set()
    for n in inputs:
        a, z = base_layout[n]
        assert lo <= a < z <= hi
        pubs.update(comdat_publics.get(n, set()))
        for s, off, nm in pg.r3_reloc.parse(m / (n + ".OBJ"))["pubs"]:
            if nm != "L%06X" % (a + off):
                assert (n, nm, a + off) in preserved_publics, (n, nm, hex(a + off))
                named_pubs.append((nm, a + off))
            pubs.add(a + off)
    pubs.update(a for a in targets if lo <= a < hi)
    labels = sorted(pubs)
    for k in range(0, len(labels), 40):
        out += pg.record(
            0x91,
            b"\0\x01"
            + b"".join(
                b"\x07" + ("L%06X" % a).encode() + struct.pack("<I", a - lo) + b"\0"
                for a in labels[k : k + 40]
            ),
        )
    for nm, address in sorted(set(named_pubs)):
        nb = nm.encode("latin1")
        out += pg.record(
            0x91, b"\0\x01" + bytes([len(nb)]) + nb + struct.pack("<I", address - lo) + b"\0"
        )
    for i in order:
        c = pieces[i]
        pos = 0
        while pos < len(c["data"]):
            end = min(pos + 1000, len(c["data"]))
            for f in c["fixups"]:
                off = f["address"] - c["address"]
                if off < end < off + f["original"]["width"]:
                    end = off
            out += pg.record(0xA1, b"\x01" + struct.pack("<I", c["address"] - lo + pos) + c["data"][pos:end])
            parts = []
            for f in c["fixups"]:
                off = f["address"] - c["address"] - pos
                if not 0 <= off < end - pos:
                    continue
                old = f["original"]
                head = 0x80 | (0 if old["relative"] else 0x40) | (old["location"] << 2) | (off >> 8)
                parts.append(
                    bytes([head, off & 255, 0x52])
                    + pg.ix(ext[f["target"]])
                    + struct.pack("<I", (-f["value"]) & 0xFFFFFFFF)
                )
            if parts:
                out += pg.record(0x9D, b"".join(parts))
            pos = end
    out += pg.record(0x8A, b"\0")
    dest = Path(dest)
    dest.mkdir(exist_ok=True)
    path = dest / (outname + ".OBJ")
    path.write_bytes(out)
    parsed = pg.r3_reloc.parse(path)
    for c in pieces:
        off = c["address"] - lo
        assert parsed["segs"][1]["data"][off : off + len(c["data"])] == c["data"]
    seq = [lo + f["off"] for f in parsed["fix"] if not f["relative"]]
    for sequence in streams:
        assert [a for a in seq if a in set(sequence)] == sequence
    proof = dict(
        name=outname,
        base_module=name,
        base_modules=basenames,
        block_choices=block_choices,
        lo=lo,
        hi=hi,
        inputs=inputs,
        sha256=hashlib.sha256(out).hexdigest(),
        order=[pieces[i]["address"] for i in order],
        spans=[
            {k: v for k, v in c.items() if k not in ("data", "fixups")}
            | dict(hi=c["address"] + len(c["data"]), payload_sha256=hashlib.sha256(c["data"]).hexdigest())
            for c in pieces
        ],
    )
    return path, proof


def make_fix_group(
    base,
    m,
    name,
    lo,
    hi,
    group_pieces,
    dest,
    basenames,
    retain,
    allowed,
    wrapper_segment,
    preserved_publics,
    base_layout,
):
    intervals = [(p["address"], p["orig_end_address"]) for p in group_pieces]
    all_pieces = list(group_pieces)
    comdat_publics = {}

    for basename in basenames:
        baselo, basehi = base_layout[basename]
        raw = (base / (basename + ".OBJ")).read_bytes()
        obj = pg.lib["omf"].modules(str(base / (basename + ".OBJ")))[0]
        if obj["comdats"]:
            sid, body = next(
                (i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and len(s["data"])
            )
            _, saved, extra_pubs = existing_comdat(
                base / (basename + ".OBJ"), baselo, basehi, intervals, retain, allowed
            )
            for sp in saved:
                sp["orig_end_address"] = sp["address"] + len(sp["data"])
            all_pieces += saved
            comdat_publics[basename] = extra_pubs
            continue
        active = [(i, s) for i, s in obj["segs"].items() if s["cls"] == "CODE" and len(s["data"])]
        assert len(active) == 1
        sid, body = active[0]
        labels = {
            baselo + o
            for sid0, o, n in pg.r3_reloc.parse(base / (basename + ".OBJ"))["pubs"]
            if sid0 == sid
        }
        fx = pg.omf_extra.fixups(raw)
        baseff = []
        for f in fx:
            at = baselo + f["offset"]
            val = int.from_bytes(body["data"][f["offset"] : f["offset"] + 4], "little")
            add = (val + f["displacement"]) & 0xFFFFFFFF
            target = f["target"]
            if target[0] == "external":
                resolved = (int(target[1][1:], 16) + add) & 0xFFFFFFFF
            elif target[0] == "segment":
                resolved = baselo + add
            else:
                raise ValueError("Unbelegtes ASM-Ziel " + str(target))
            baseff.append(
                dict(original=f, address=at, value=val, add=add, want=resolved, target=resolved)
            )
        for typ, b in pg.r3_reloc.records(raw):
            if typ not in (0xA0, 0xA1):
                continue
            sn, j = pg.r3_reloc.idx(b, 0)
            w = 4 if typ & 1 else 2
            off = int.from_bytes(b[j : j + w], "little")
            data = b[j + w :]
            for left, right in pg.subtract(baselo + off, baselo + off + len(data), intervals):
                cuts = (
                    [left]
                    + sorted(
                        {x for x in labels if left < x < right}
                        | {x for g in allowed for x in (g["lo"], g["hi"]) if left < x < right}
                    )
                    + [right]
                )
                for a, z in zip(cuts, cuts[1:]):
                    refs = [dict(f, piece_offset=f["address"] - a) for f in baseff if a <= f["address"] < z]
                    sp = retain(
                        basename,
                        baselo,
                        sid,
                        a,
                        z,
                        data[a - baselo - off : z - baselo - off],
                        refs,
                        raw,
                    )
                    sp["orig_end_address"] = z
                    all_pieces.append(sp)

    all_pieces.sort(key=lambda c: c["address"])
    cur_orig = lo
    cur_seg_off = 0
    for c in all_pieces:
        assert c["address"] == cur_orig, (
            "Luecke/Overlap im Fix-Gruppenbau",
            name,
            hex(cur_orig),
            hex(c["address"]),
        )
        cur_orig = c.get("orig_end_address", c["address"] + len(c["data"]))
        c["seg_offset"] = cur_seg_off
        cur_seg_off += len(c["data"])
    assert cur_orig == hi, ("Gruppenende weicht ab", name, hex(cur_orig), hex(hi))
    total_seg_len = cur_seg_off

    inputs = [n for n, (a, b) in base_layout.items() if a < hi and b > lo and a < b]
    orig_pubs = set()
    named_pubs = []
    for n in inputs:
        a, z = base_layout[n]
        orig_pubs.update(comdat_publics.get(n, set()))
        for s, off, nm in pg.r3_reloc.parse(m / (n + ".OBJ"))["pubs"]:
            if nm != "L%06X" % (a + off):
                assert (n, nm, a + off) in preserved_publics, (n, nm, hex(a + off))
                named_pubs.append((nm, a + off))
            orig_pubs.add(a + off)

    for c in all_pieces:
        for f in c["fixups"]:
            if f.get("target") is not None and lo <= f["target"] < hi:
                orig_pubs.add(f["target"])
        for k_addr in c.get("pub_offsets", {}):
            orig_pubs.add(int(k_addr))

    def map_orig_addr_to_seg_offset(addr):
        for c in all_pieces:
            c_lo = c["address"]
            c_hi = c.get("orig_end_address", c_lo + len(c["data"]))
            if c_lo <= addr < c_hi:
                pub_map = c.get("pub_offsets")
                if pub_map and str(addr) in pub_map:
                    return c["seg_offset"] + int(pub_map[str(addr)])
                if addr == c_lo:
                    return c["seg_offset"]
                return c["seg_offset"] + (addr - c_lo)
        if addr == hi:
            return total_seg_len
        raise ValueError(f"Public-Adresse {hex(addr)} konnte in Fix-Gruppe {name} nicht abgebildet werden")

    outname = "B%06X" % lo
    source_tag = ("GESAMTBAU fix-bound link " + name + ".OBJ").encode()
    seg, segattr = wrapper_segment(base, basenames[0])
    out = bytearray(pg.record(0x80, bytes([len(source_tag)]) + source_tag))
    out += pg.record(0x96, b"\0" + bytes([len(seg)]) + seg.encode() + b"\x04CODE")
    out += pg.record(0x99, bytes([segattr]) + struct.pack("<I", total_seg_len) + b"\x02\x03\x01")

    targets = sorted(
        {f["target"] for c in all_pieces for f in c["fixups"] if f.get("target") is not None}
    )
    ext = {a: i + 1 for i, a in enumerate(targets)}
    for k in range(0, len(targets), 70):
        out += pg.record(
            0x8C, b"".join(b"\x07" + ("L%06X" % a).encode() + b"\0" for a in targets[k : k + 70])
        )

    for nm, address in sorted(set(named_pubs)):
        nb = nm.encode("latin1")
        out += pg.record(
            0x91,
            b"\0\x01"
            + bytes([len(nb)])
            + nb
            + struct.pack("<I", map_orig_addr_to_seg_offset(address))
            + b"\0",
        )

    labels = sorted(orig_pubs)
    for k in range(0, len(labels), 40):
        out += pg.record(
            0x91,
            b"\0\x01"
            + b"".join(
                b"\x07"
                + ("L%06X" % a).encode()
                + struct.pack("<I", map_orig_addr_to_seg_offset(a))
                + b"\0"
                for a in labels[k : k + 40]
            ),
        )

    for c in all_pieces:
        pos = 0
        while pos < len(c["data"]):
            end = min(pos + 1000, len(c["data"]))
            for f in c["fixups"]:
                off = f.get("piece_offset", f["address"] - c["address"])
                if off < end < off + f["original"]["width"]:
                    end = off
            out += pg.record(
                0xA1, b"\x01" + struct.pack("<I", c["seg_offset"] + pos) + c["data"][pos:end]
            )
            parts = []
            for f in c["fixups"]:
                off = f.get("piece_offset", f["address"] - c["address"]) - pos
                if not 0 <= off < end - pos:
                    continue
                old = f["original"]
                head = 0x80 | (0 if old["relative"] else 0x40) | (old["location"] << 2) | (off >> 8)
                if f.get("target") is not None:
                    parts.append(
                        bytes([head, off & 255, 0x52])
                        + pg.ix(ext[f["target"]])
                        + struct.pack("<I", (-f["value"]) & 0xFFFFFFFF)
                    )
                else:
                    target_seg_off = (c["seg_offset"] + f["seg_target_offset"]) & 0xFFFFFFFF
                    parts.append(
                        bytes([head, off & 255, 0x50, 0x01])
                        + struct.pack("<I", (target_seg_off - f["value"]) & 0xFFFFFFFF)
                    )
            if parts:
                out += pg.record(0x9D, b"".join(parts))
            pos = end

    out += pg.record(0x8A, b"\0")
    dest = Path(dest)
    dest.mkdir(exist_ok=True)
    path = dest / (outname + ".OBJ")
    path.write_bytes(out)
    parsed = pg.r3_reloc.parse(path)
    for c in all_pieces:
        off = c["seg_offset"]
        assert parsed["segs"][1]["data"][off : off + len(c["data"])] == c["data"]
    proof = dict(
        name=outname,
        base_module=name,
        base_modules=basenames,
        lo=lo,
        hi=hi,
        new_length=total_seg_len,
        orig_length=hi - lo,
        changed_by_fix=True,
        inputs=inputs,
        sha256=hashlib.sha256(out).hexdigest(),
        spans=[
            {k: v for k, v in c.items() if k not in ("data", "fixups")}
            | dict(hi=c["address"] + len(c["data"]), payload_sha256=hashlib.sha256(c["data"]).hexdigest())
            for c in all_pieces
        ],
    )
    return path, proof


def relocate_unfixed_asm_rel32(base, codebase, m, lay, units, extra_anchors, touched, all_publics):
    unit_spans = sorted([(u["lo"], u["hi"]) for u in units])
    asm_intervals = []
    for name, (lo, hi) in sorted(lay.items(), key=lambda x: x[1][0]):
        if lo >= hi:
            continue
        rem = list(pg.subtract(lo, hi, unit_spans))
        for a, b in extra_anchors:
            if lo <= a < b <= hi:
                rem.append((a, b))
        rem.sort()
        merged = []
        for a, b in rem:
            if merged and a <= merged[-1][1]:
                merged[-1] = (merged[-1][0], max(merged[-1][1], b))
            else:
                merged.append((a, b))
        for a, b in merged:
            asm_intervals.append((name, lo, hi, a, b))

    rels_by_mod = {}
    needed_pubs = set()
    for name, lo, hi, a, z in asm_intervals:
        scan_end = min(z, 0x199365) if (a <= 0x199390 < z) else z
        if scan_end <= a:
            continue
        p = codebase / (name + ".OBJ")
        raw = p.read_bytes()
        meta = pg.r3_reloc.parse(p)
        obj = pg.lib["omf"].modules(str(p))[0]
        fx = pg.omf_extra.fixups(raw)
        mask = bytearray(hi - lo)
        for f in fx:
            for i in range(f["offset"], min(hi - lo, f["offset"] + f["width"])):
                mask[i] = 1
        for sid, s in obj["segs"].items():
            if s["cls"] == "CODE" and s["data"]:
                cuts = sorted(
                    {a - lo, scan_end - lo}
                    | {off for ss, off, _ in meta["pubs"] if ss == sid and a - lo < off < scan_end - lo}
                )
                for c0, c1 in zip(cuts, cuts[1:]):
                    data = bytes(s["data"][c0:c1])
                    for ins in pg.MD.disasm(data, lo + c0):
                        b = bytes(ins.bytes)
                        disp_off = (
                            1
                            if len(b) == 5 and b[0] in (0xE8, 0xE9)
                            else (2 if len(b) == 6 and b[0] == 0x0F and 0x80 <= b[1] <= 0x8F else None)
                        )
                        if disp_off is not None and not any(
                            mask[ins.address - lo : ins.address - lo + ins.size]
                        ):
                            disp = int.from_bytes(b[disp_off : disp_off + 4], "little", signed=True)
                            tgt = ins.address + ins.size + disp
                            if not (a <= tgt < z) and (0x10000 <= tgt < 0x19D630):
                                rels_by_mod.setdefault(name, []).append((ins.address - lo + disp_off, tgt))
                                needed_pubs.add(tgt)

    pubs_by_mod = {}
    for tgt in sorted(needed_pubs):
        mod = next(n for n, (lo, hi) in lay.items() if lo <= tgt < hi)
        pubs_by_mod.setdefault(mod, []).append(tgt)

    affected = sorted(set(rels_by_mod) | set(pubs_by_mod))
    saved_asm_dir = m / "CPP_BELEGE/GESAMTBAU_ASM_RELOC"
    for name in affected:
        lo, hi = lay[name]
        p = codebase / (name + ".OBJ")
        raw = p.read_bytes()
        meta = pg.r3_reloc.parse(p)
        obj = pg.lib["omf"].modules(str(p))[0]
        code_sid = next(i for i, s in obj["segs"].items() if s["cls"] == "CODE" and s["data"])
        existing_pubs = {nm for s, off, nm in meta["pubs"]}
        existing_exts = list(meta["ext"][1:])
        ext_map = {nm: i + 1 for i, nm in enumerate(existing_exts)}

        rels = sorted(rels_by_mod.get(name, []))
        new_exts = []
        for _, tgt in rels:
            sym = f"L{tgt:06X}"
            if sym not in ext_map:
                ext_map[sym] = len(existing_exts) + len(new_exts) + 1
                new_exts.append(sym)

        new_pubs = [tgt for tgt in pubs_by_mod.get(name, []) if f"L{tgt:06X}" not in existing_pubs]
        for tgt in new_pubs:
            all_publics.add(f"L{tgt:06X}")

        records = list(pg.r3_reloc.records(raw))
        out = bytearray()
        exts_emitted = False
        i_rec = 0
        while i_rec < len(records):
            typ, body = records[i_rec]
            if not exts_emitted and typ in (0x90, 0x91, 0xA0, 0xA1, 0x8A, 0x8B):
                for k in range(0, len(new_exts), 70):
                    out += pg.record(
                        0x8C, b"".join(b"\x07" + s.encode("ascii") + b"\0" for s in new_exts[k : k + 70])
                    )
                exts_emitted = True
            if typ in (0x8A, 0x8B):
                for k in range(0, len(new_pubs), 40):
                    out += pg.record(
                        0x91,
                        b"\0"
                        + pg.ix(code_sid)
                        + b"".join(
                            b"\x07" + (f"L{a:06X}").encode("ascii") + struct.pack("<I", a - lo) + b"\0"
                            for a in new_pubs[k : k + 40]
                        ),
                    )
                out += pg.record(typ, body)
                i_rec += 1
                continue
            if typ in (0xA0, 0xA1):
                sn, j = pg.r3_reloc.idx(body, 0)
                w = 4 if typ & 1 else 2
                s_lo = int.from_bytes(body[j : j + w], "little")
                payload = body[j + w :]
                s_hi = s_lo + len(payload)
                out += pg.record(typ, body)
                if i_rec + 1 < len(records) and records[i_rec + 1][0] in (0x9C, 0x9D):
                    i_rec += 1
                    out += pg.record(records[i_rec][0], records[i_rec][1])
                if sn == code_sid:
                    parts = []
                    for off, tgt in rels:
                        if s_lo <= off and off + 4 <= s_hi:
                            led_off = off - s_lo
                            val = int.from_bytes(payload[led_off : led_off + 4], "little")
                            head = 0x80 | (9 << 2) | (led_off >> 8)
                            sym = f"L{tgt:06X}"
                            parts.append(
                                bytes([head, led_off & 255, 0x52])
                                + pg.ix(ext_map[sym])
                                + struct.pack("<I", (-val) & 0xFFFFFFFF)
                            )
                    if parts:
                        out += pg.record(0x9D, b"".join(parts))
                i_rec += 1
                continue
            out += pg.record(typ, body)
            i_rec += 1

        p.write_bytes(out)
        if name not in touched:
            (m / (name + ".OBJ")).write_bytes(out)
            asm_path = m / (name + ".ASM")
            if asm_path.exists():
                saved_asm_dir.mkdir(parents=True, exist_ok=True)
                asm_path.rename(saved_asm_dir / asm_path.name)


def export_missing_data_symbols(m):
    mods, missing, _ = symbols(m)
    missing_syms = sorted({s for names in missing.values() for s in names})
    if not missing_syms:
        return []
    added = []
    for sym in missing_syms:
        if not re.fullmatch(r"L[0-9A-F]{6}", sym):
            continue
        address = int(sym[1:], 16)
        found = None
        for mod_name, row in mods.items():
            for sid, seg in row["meta"]["segs"].items():
                if seg["cls"] == "CODE" or not seg["data"]:
                    continue
                pubs = [
                    (off, n)
                    for si, off, n in row["meta"]["pubs"]
                    if si == sid and re.fullmatch(r"L[0-9A-F]{6}", n)
                ]
                bases = {int(n[1:], 16) - off for off, n in pubs}
                if len(bases) == 1:
                    base_addr = next(iter(bases))
                    if base_addr <= address < base_addr + len(seg["data"]):
                        found = (mod_name, sid, address - base_addr)
                        break
            if found:
                break
        if not found:
            continue
        mod_name, sid, seg_off = found
        obj_path = m / (mod_name + ".OBJ")
        raw = obj_path.read_bytes()
        out = bytearray()
        nb = sym.encode("ascii")
        for typ, body in pg.r3_reloc.records(raw):
            if typ in (0x8A, 0x8B):
                out += pg.record(
                    0x91, b"\0" + pg.ix(sid) + bytes([len(nb)]) + nb + struct.pack("<I", seg_off) + b"\0"
                )
            out += pg.record(typ, body)
        obj_path.write_bytes(out)
        asm_path = m / (mod_name + ".ASM")
        if asm_path.exists():
            saved_dir = m / "CPP_BELEGE/GESAMTBAU_DATA_ALIAS"
            saved_dir.mkdir(parents=True, exist_ok=True)
            asm_path.rename(saved_dir / asm_path.name)
        added.append(dict(symbol=sym, module=mod_name, segment=sid, offset=seg_off))
    return added


def wlink_build(
    m: Path,
    tag: str,
    orig_exe_bytes: bytes,
    staged_watcom: Path,
    dosbox_exe: Path,
    win_work_base: Path,
):
    m = m.resolve()
    is_win_dosbox_on_wsl = dosbox_exe.name.lower().endswith(".exe") and os.name != "nt"
    if is_win_dosbox_on_wsl:
        win_link_root = win_work_base / f"wlink_{os.getpid()}"
        rmtree_safe(win_link_root)
        run_m = win_link_root / "m"
        run_m.mkdir(parents=True, exist_ok=True)
        shutil.copy2(m / "RIVA.LNK", run_m / "RIVA.LNK")
        for line in (m / "RIVA.LNK").read_text().splitlines():
            if line.startswith("file "):
                obj_name = line[5:].strip()
                shutil.copy2(m / obj_name, run_m / obj_name)
    else:
        win_link_root = None
        run_m = m

    try:
        archive = run_m.parent / ("build_" + tag)
        archive.mkdir(exist_ok=True)
        for name in ("RIVA.EXE", "RIVA.MAP", "E1.TXT", "E2.TXT", "DONE.TXT", "GO.BAT"):
            p = run_m / name
            if p.exists():
                p.unlink()
        (run_m.parent / "STUB.EXE").write_bytes(
            orig_exe_bytes[DOS4GW_PREFIX_LEN : DOS4GW_PREFIX_LEN + INNER_STUB_LEN]
        )
        batch = [
            "@echo off",
            "set WATCOM=C:\\",
            "set PATH=C:\\BINW;C:\\BINNT;C:\\BINB",
            "wlink @RIVA.LNK > E2.TXT",
            "echo fertig > DONE.TXT",
            "exit",
        ]
        (run_m / "GO.BAT").write_bytes(("\r\n".join(batch) + "\r\n").encode("ascii"))

        mount_c = to_win_path(staged_watcom) if is_win_dosbox_on_wsl else str(staged_watcom)
        mount_d = to_win_path(run_m.parent) if is_win_dosbox_on_wsl else str(run_m.parent)
        conf = archive / "dosbox.conf"
        conf.write_text(
            "\n".join([
                "[sdl]",
                "output=surface",
                "[dosbox]",
                "memsize=63",
                "[cpu]",
                "core=normal",
                "cycles=max",
                "[mixer]",
                "nosound=true",
                "[speaker]",
                "pcspeaker=false",
                "[sblaster]",
                "sbtype=none",
                "[gus]",
                "gus=false",
                "[autoexec]",
                f'mount c "{mount_c}"',
                f'mount d "{mount_d}"',
                "d:",
                f"cd \\{run_m.name}",
                "GO.BAT",
                "exit",
                "",
            ]),
            encoding="ascii",
        )
        conf_arg = to_win_path(conf) if is_win_dosbox_on_wsl else str(conf)
        env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")
        start = time.time()
        with (archive / "dosbox.log").open("wb") as log:
            p = subprocess.Popen(
                [str(dosbox_exe), "-conf", conf_arg, "-noconsole", "-exit"],
                cwd=dosbox_exe.parent,
                env=env,
                stdin=subprocess.DEVNULL,
                stdout=log,
                stderr=subprocess.STDOUT,
            )
            while p.poll() is None and not (run_m / "DONE.TXT").exists() and time.time() - start < 600:
                time.sleep(0.2)
            done = (run_m / "DONE.TXT").exists()
            if p.poll() is None:
                try:
                    p.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    p.terminate()
                    try:
                        p.wait(timeout=3)
                    except subprocess.TimeoutExpired:
                        p.kill()
                        p.wait()
        if is_win_dosbox_on_wsl:
            for fn in ("RIVA.EXE", "RIVA.MAP", "E2.TXT", "DONE.TXT"):
                if (run_m / fn).exists():
                    shutil.copy2(run_m / fn, m / fn)
        ex = m / "RIVA.EXE"
        md5 = (
            hashlib.md5(orig_exe_bytes[:DOS4GW_PREFIX_LEN] + ex.read_bytes()).hexdigest()
            if ex.exists()
            else None
        )
        errors = "\n".join(
            l
            for f in ("E1.TXT", "E2.TXT")
            if (m / f).exists()
            for l in (m / f).read_text(errors="replace").splitlines()
            if re.search("error|undefined|warning", l, re.I)
        )
        return dict(
            tag=tag,
            done=done,
            md5=md5,
            good=bool(done and md5 == GOOD),
            seconds=round(time.time() - start, 2),
            assembled=0,
            dir=str(m),
            errors=errors,
        )
    finally:
        if win_link_root is not None:
            rmtree_safe(win_link_root)


def main():
    ap = argparse.ArgumentParser(
        description="Baut RIVA.EXE sowie RIVA_FIX_WICHTIG.EXE / RIVA_FIX_ALLES.EXE aus Quelle/ und Bauen/baustand.tgz."
    )
    ap.add_argument(
        "modus",
        nargs="?",
        default=None,
        choices=["original", "wichtig", "alles"],
        help="Bau-Modus: 'original' (Standard, bytegleich), 'wichtig' (Stufe A, -DFIX_BUGS=1) oder 'alles' (Stufe B, -DFIX_BUGS=2)",
    )
    ap.add_argument(
        "--fix",
        type=int,
        choices=[0, 1, 2],
        default=None,
        help="Alternativer Schalter fuer Fix-Stufe: 1 = Stufe A (wichtig), 2 = Stufe B (alles)",
    )
    ap.add_argument(
        "--exploits-lassen",
        action="store_true",
        help="Im Fix-Modus Exploits zum Vorteil des Spielers unveraendert lassen (-DFIX_EXPLOITS=0)",
    )
    ap.add_argument(
        "--fix-exploits",
        type=int,
        choices=[0, 1],
        default=None,
        help="Optionaler Zusatzschalter -DFIX_EXPLOITS=0/1 im Fix-Modus",
    )
    ap.add_argument(
        "--fixflags",
        default="",
        help="Zusaetzliche -D-Schalter fuer gezielte Einzel-Fixes (z.B. '-DFIX_R001=0')",
    )
    ap.add_argument(
        "--dosbox",
        type=Path,
        default=None,
        help="Pfad zu DOSBox.exe / dosbox",
    )
    ap.add_argument(
        "--paket",
        type=Path,
        default=PAKET_ROOT,
        help="Paket-Wurzelverzeichnis (Standard: Ordner ueber Bauen/)",
    )
    ap.add_argument(
        "--out",
        "--ausgabe",
        dest="out",
        type=Path,
        default=None,
        help="Expliziter Ausgabeordner (Standard: Build/ im Paketordner)",
    )
    ap.add_argument(
        "--source-override",
        action="append",
        default=[],
        help="Optionale Zusatzverzeichnisse mit *_P1.CPP zum Vorabtest",
    )
    args = ap.parse_args()

    if args.fix is not None:
        fix_level = args.fix
    elif args.modus == "wichtig":
        fix_level = 1
    elif args.modus == "alles":
        fix_level = 2
    else:
        fix_level = 0

    fix_exploits = args.fix_exploits
    if args.exploits_lassen:
        fix_exploits = 0

    paket_root = args.paket.resolve()
    quelle_dir = paket_root / "Quelle"
    compiler_dir = paket_root / "Compiler"
    build_dir = paket_root / "Build"
    baustand_tgz = HERE / "baustand.tgz"

    exe_name, le_exe_name = FIX_EXE_NAMES[fix_level]
    t0 = time.time()
    stamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    mode_tag = "original" if fix_level == 0 else ("wichtig" if fix_level == 1 else "alles")

    build_dir.mkdir(parents=True, exist_ok=True)
    out_dir = args.out.resolve() if args.out else (build_dir / f"nachweis_{mode_tag}")
    out_dir.mkdir(parents=True, exist_ok=True)

    log_path = build_dir / "bau.log"
    log_file = open(log_path, "w", encoding="utf-8")

    def log_print(msg):
        print(msg, flush=True)
        log_file.write(msg + "\n")
        log_file.flush()

    mode_label = (
        f'FIX-MODUS STUFE {"A (WICHTIG, -DFIX_BUGS=1)" if fix_level == 1 else "B (ALLES, -DFIX_BUGS=2)"} -> {exe_name}'
        if fix_level > 0
        else f"ORIGINAL-MODUS -> {exe_name} (100% bytegleich)"
    )
    log_print(f"=== {mode_label} ({stamp}) ===")
    log_print(f"Paketordner:  {paket_root}")

    if not quelle_dir.is_dir() or not (quelle_dir / "cpp").is_dir():
        log_print(
            "FEHLER: Quelle/cpp/ fehlt. Bitte zuerst 'python3 Werkzeuge/mk_baupaket.py --ausfuehren' starten."
        )
        return 1

    orig_exe_path = locate_original_exe(paket_root)
    if orig_exe_path is None:
        log_print("FEHLER: Original/RIVA.EXE wurde nicht gefunden.")
        log_print(f"Bitte RIVA.EXE (deutsche GOG-Version V1.12) nach {paket_root / 'Original'} kopieren.")
        return 3

    orig_exe_bytes = orig_exe_path.read_bytes()
    orig_md5 = hashlib.md5(orig_exe_bytes).hexdigest()
    if len(orig_exe_bytes) != SOLL_GROESSE or orig_md5 != SOLL_MD5:
        log_print(
            f"FEHLER: {orig_exe_path} entspricht nicht der deutschen GOG-Version V1.12 "
            f"(Groesse {len(orig_exe_bytes)} statt {SOLL_GROESSE}, MD5 {orig_md5} statt {SOLL_MD5})."
        )
        return 4

    win_work_base = get_win_work_base()
    try:
        staged_watcom = stage_watcom_compiler(compiler_dir, win_work_base)
    except Exception as exc:
        log_print(f"FEHLER: {exc}")
        return 2

    try:
        dosbox_exe = locate_dosbox(args.dosbox, paket_root)
    except Exception as exc:
        log_print(f"FEHLER: {exc}")
        return 2

    log_print(f"Compiler:     {compiler_dir} (Arbeitskopie: {staged_watcom})")
    log_print(f"Original-EXE: {orig_exe_path} (MD5: {orig_md5})")
    log_print(f"DOSBox:       {dosbox_exe}")

    cache_root = Path(tempfile.gettempdir()) / "riva_baustand_cache"
    base, meta_dir = ensure_baustand(baustand_tgz, cache_root)
    init_context(meta_dir, orig_exe_path)

    units, anchors = collect_units(quelle_dir, args.source_override)
    if len(units) != 571:
        log_print(f"FEHLER: {len(units)} statt 571 C/C++-Einheiten in {quelle_dir / 'cpp'} gefunden.")
        return 1

    log_print(
        f"[1/5] Einheiten erfasst: {len(units)} C/C++ + {len(anchors)} Hand-ASM-Anker = {len(units) + len(anchors)} gesamt"
    )

    batch_dir = win_work_base / f"batch_{os.getpid()}"
    t_comp = time.time()
    headers, switch_headers = compile_all_units(
        units,
        quelle_dir,
        batch_dir,
        staged_watcom,
        dosbox_exe,
        fix_level=fix_level,
        fix_exploits=fix_exploits,
        extra_fix_flags=args.fixflags,
    )
    log_print(f"[2/5] Watcom 10.6 Batch-Kompilierung abgeschlossen ({time.time() - t_comp:.1f}s)")

    work_root = Path(tempfile.mkdtemp(prefix="riva_bau_work_"))
    link_root = Path(tempfile.mkdtemp(prefix="riva_bau_link_"))
    try:
        t_mod = time.time()
        models, model_errors = model_all_units(
            units,
            quelle_dir,
            batch_dir,
            work_root,
            staged_watcom,
            dosbox_exe,
            fix_level=fix_level,
        )
        rmtree_safe(batch_dir)
        good_count = sum(1 for r in models if r.get("good"))
        changed_fix_units = [r["unit"] for r in models if r.get("changed_by_fix")]
        if fix_level > 0:
            log_print(
                f"[3/5] Objekt- und Symbolmodellierung (Fix-Modus): {good_count}/{len(models)} fehlerfrei, "
                f"{len(changed_fix_units)} Einheit(en) durch Fixes geaendert ({time.time() - t_mod:.1f}s)"
            )
        else:
            log_print(
                f"[3/5] Objekt- und Relokationspruefung (fragment_model): {good_count}/{len(models)} fehlerfrei ({time.time() - t_mod:.1f}s)"
            )

        if model_errors:
            err_path = out_dir / "ABWEICHUNGEN.json"
            err_path.write_text(json.dumps(model_errors, indent=2) + "\n")
            log_print(f"ERGEBNIS: FEHLER/ABWEICHUNG in {len(model_errors)} Einheit(en)! Details in {err_path}")
            for e in model_errors:
                log_print(f'  - {e["unit"]} ({e["stage"]}): {e["error"]}')
            return 1

        t_link = time.time()
        rmtree_safe(link_root)
        link_root.mkdir(parents=True, exist_ok=True)
        m = link_root / "m"
        shutil.copytree(base, m)
        lay = layout(base)
        pieces = []
        provenance = []
        for row in models:
            md = row["model"]
            saved = m / "CPP_BELEGE/GESAMTBAU_CURRENT" / row["unit"]
            saved.mkdir(parents=True)
            shutil.copy2(row["source"], saved / "source.CPP")
            shutil.copy2(md["raw"], saved / "raw.OBJ")
            for chunk in md["chunks"]:
                raw = bytes.fromhex(chunk["data"])
                for part in chunk["parts"]:
                    a = part["address"]
                    n = part["end"] - part["offset"]
                    orig_end = part.get("orig_end_address", a + n)
                    if not row["lo"] <= a < row["hi"]:
                        continue
                    assert orig_end <= row["hi"], (row["unit"], hex(a), hex(orig_end), hex(row["hi"]))
                    data = raw[a - chunk["address"] : a - chunk["address"] + n]
                    assert hashlib.sha256(data).hexdigest() == part["sha256"]
                    pieces.append(
                        dict(
                            address=a,
                            orig_end_address=orig_end,
                            data=data,
                            fixups=[f for f in chunk["fixups"] if a <= f["address"] < a + n],
                            pub_offsets=part.get("pub_offsets", chunk.get("pub_offsets", {})),
                            changed_by_fix=bool(part.get("changed_by_fix") or chunk.get("changed_by_fix")),
                            cpp=True,
                            unit=row["unit"],
                            source=row["source"],
                            source_sha256=row["source_sha256"],
                            raw=md["raw"],
                            raw_sha256=md["raw_sha256"],
                            part=part,
                            saved_source=str((saved / "source.CPP").relative_to(m)),
                            saved_raw=str((saved / "raw.OBJ").relative_to(m)),
                        )
                    )
            provenance.append(
                dict(
                    unit=row["unit"],
                    tier=row["tier"],
                    source=row["source_rel"],
                    source_sha256=row["source_sha256"],
                    raw_sha256=md["raw_sha256"],
                    gate_status=row["details"]["gate_status"],
                    chunks=len(md["chunks"]),
                    changed_by_fix=bool(row.get("changed_by_fix")),
                )
            )

        pieces.sort(key=lambda p: p["address"])
        assert all(a["orig_end_address"] <= b["address"] for a, b in zip(pieces, pieces[1:]))

        parent = {n: n for n, (a, b) in lay.items() if a < b}
        touched = set()

        def find(n):
            while parent[n] != n:
                parent[n] = parent[parent[n]]
                n = parent[n]
            return n

        for p in pieces:
            hits = [
                n for n, (a, b) in lay.items() if a < b and a < p["orig_end_address"] and b > p["address"]
            ]
            assert hits, (hex(p["address"]), hex(p["orig_end_address"]))
            touched.update(hits)
            for n in hits[1:]:
                parent[find(n)] = find(hits[0])
        components = {}
        for n in touched:
            components.setdefault(find(n), []).append(n)
        components = sorted(
            (sorted(ns, key=lambda n: lay[n][0]) for ns in components.values()),
            key=lambda ns: lay[ns[0]][0],
        )

        extra_anchors = list(ANCHORS) + [(0x198D23, 0x199410), (0x1994E5, 0x199700)]
        allowed = []
        for names in components:
            lo = lay[names[0]][0]
            hi = lay[names[-1]][1]
            assert all(lay[a][1] == lay[b][0] for a, b in zip(names, names[1:])), (
                "Linkerausrichtung im neuen Verband",
                names,
            )
            spans = [(p["address"], p["orig_end_address"]) for p in pieces if lo <= p["address"] < hi]
            for a, b in pg.subtract(lo, hi, spans):
                cuts = sorted({a, b} | {x for pair in extra_anchors for x in pair if a < x < b})
                for x, y in zip(cuts, cuts[1:]):
                    anchor = any(aa <= x < y <= bb for aa, bb in extra_anchors)
                    pad = not any(x <= s < y for s in FUNKTIONEN_STARTS) and padding(
                        bytes(IMAGE[x - 0x10000 : y - 0x10000])
                    )
                    assert anchor or pad, ("Unbelegter Restkoerper", names, hex(x), hex(y))
                    allowed.append(dict(lo=x, hi=y, kind="Anker" if anchor else "Fuellung"))

        base_saved = m / "CPP_BELEGE/GESAMTBAU_REPLACED"
        base_saved.mkdir(parents=True)
        for n in touched:
            shutil.copy2(base / (n + ".OBJ"), base_saved / (n + ".OBJ"))
        codebase = link_root / "codebase"
        shutil.copytree(base, codebase)
        data_dest = link_root / "daten"
        data_dest.mkdir()
        all_publics = {n for name in lay for _, _, n in pg.r3_reloc.parse(base / (name + ".OBJ"))["pubs"]}
        needed_targets = {f["target"] for p in pieces for f in p["fixups"] if f.get("target") is not None}
        data_proofs = extract_views(base, codebase, data_dest, touched, lay, all_publics, needed_targets)
        if fix_level > 0 and changed_fix_units:
            relocate_unfixed_asm_rel32(
                base, codebase, m, lay, units, extra_anchors, touched, all_publics
            )

        def retain(basename, baselo, sid, a, z, data, refs, raw):
            permit = next(g for g in allowed if g["lo"] <= a < z <= g["hi"])
            if permit["kind"] == "Fuellung":
                assert not refs and data == bytes(IMAGE[a - 0x10000 : z - 0x10000])
            return dict(
                address=a,
                data=data,
                fixups=refs,
                cpp=False,
                source=permit["kind"] + " aus vorhandenem D22-Objekt " + basename + ".OBJ",
                preserved_kind=permit["kind"],
                raw_sha256=sha256_file(base / (basename + ".OBJ")),
                saved_asm_raw=str((base_saved / (basename + ".OBJ")).relative_to(m)),
                asm_segment=sid,
                asm_offset=a - baselo,
            )

        def wrapper_segment(folder, name):
            raw = (folder / (name + ".OBJ")).read_bytes()
            meta = pg.r3_reloc.parse(folder / (name + ".OBJ"))
            sid, seg = next((i, s) for i, s in meta["segs"].items() if s["cls"] == "CODE" and s["data"])
            attributes = [b[0] for t, b in pg.r3_reloc.records(raw) if t in (0x98, 0x99)]
            attr = attributes[sid - 1]
            assert attr & 31 == 9 and attr >> 5 in (1, 2, 3, 4, 5)
            return seg["name"], attr

        preserved_publics = {
            ("C01EB40", "W?$dt:D$n()_", 0x01EBD0),
            ("G051AE0", "W?id963$n(pn$Zeile$$)pn$1$", 0x051C80),
            ("G051AE0", "W?keep963$n(ui)ui", 0x051C80),
        }
        global_rows = pg.stream(base)
        orig_pages_tuple = original_pages()

        groups = []
        dest = link_root / "objekte"
        dest.mkdir()
        for names in components:
            lo = lay[names[0]][0]
            hi = lay[names[-1]][1]
            grp_pieces = [p for p in pieces if lo <= p["address"] < hi]
            if fix_level > 0 and any(p.get("changed_by_fix") for p in grp_pieces):
                obj, proof = make_fix_group(
                    codebase,
                    codebase,
                    names[0],
                    lo,
                    hi,
                    grp_pieces,
                    dest,
                    basenames=names,
                    retain=retain,
                    allowed=allowed,
                    wrapper_segment=wrapper_segment,
                    preserved_publics=preserved_publics,
                    base_layout=lay,
                )
            else:
                obj, proof = make_normal_group(
                    codebase,
                    codebase,
                    names[0],
                    lo,
                    hi,
                    grp_pieces,
                    dest,
                    basenames=names,
                    retain=retain,
                    allowed=allowed,
                    wrapper_segment=wrapper_segment,
                    preserved_publics=preserved_publics,
                    base_layout=lay,
                    global_rows=global_rows,
                    orig_pages_tuple=orig_pages_tuple,
                )
            groups.append(proof)

        replace = {n: g["name"] for g in groups for n in g["inputs"]}
        assert set(replace) == touched
        before = (m / "RIVA.LNK").read_text()
        lines = []
        inserted = set()
        data_by_old = {p["original_module"]: p for p in data_proofs}
        for line in before.splitlines():
            n = line[5:-4] if line.startswith("file ") else None
            if n not in replace:
                lines.append(line)
                continue
            if n in data_by_old:
                lines.append("file " + data_by_old[n]["name"] + ".OBJ")
            target = replace[n]
            if target not in inserted:
                lines.append("file " + target + ".OBJ")
                inserted.add(target)

        for n in touched:
            for ext in [".OBJ", ".ASM"]:
                src = m / (n + ext)
                if src.exists():
                    src.rename(base_saved / ("LINK_" + n + ext))
        for g in groups:
            shutil.copy2(dest / (g["name"] + ".OBJ"), m / (g["name"] + ".OBJ"))
        for proof in data_proofs:
            shutil.copy2(data_dest / (proof["name"] + ".OBJ"), m / (proof["name"] + ".OBJ"))
        (m / "RIVA.LNK").write_text("\n".join(lines) + "\n")
        for manifest in ["D22_GROUPS.json", "D22_FRAGMENTS.json"]:
            old_m = json.loads((m / manifest).read_text()) if (m / manifest).exists() else []
            kept = [g for g in old_m if g["name"] not in touched]
            if manifest == "D22_GROUPS.json":
                kept += groups
            (m / manifest).write_text(json.dumps(kept, indent=2) + "\n")

        added_data_aliases = []
        if fix_level > 0:
            added_data_aliases = export_missing_data_symbols(m)

        _, missing, local = symbols(m)
        if missing or local:
            sym_err = dict(global_missing=missing, local_missing=local)
            (out_dir / "SYMBOLE.json").write_text(json.dumps(sym_err, indent=2) + "\n")
            raise RuntimeError(f"Unaufgeloeste Symbole vor Linkerlauf: {sym_err}")

        order = None
        if fix_level == 0 or not changed_fix_units:
            order = audit(m, [512])
            if fix_level == 0:
                assert not order["missing"] and not order["extra"] and not order["results"][0]["count"]

        link_tag = f"bau_fix{fix_level}_{stamp}" if fix_level > 0 else f"bau_{stamp}"
        link_res = wlink_build(m, link_tag, orig_exe_bytes, staged_watcom, dosbox_exe, win_work_base)
        if not link_res.get("done") or link_res.get("errors"):
            raise RuntimeError(f"WLINK 10.6 Fehler: {link_res}")
        log_print(
            f'[4/5] WLINK 10.6 Gesamtlink abgeschlossen ({time.time() - t_link:.1f}s) -> MD5: {link_res["md5"]}'
        )

        inv = None
        cpp_ok = len(units)
        anc_ok = len(anchors)
        if fix_level == 0 or not changed_fix_units:
            t_inv = time.time()
            inv = inventory(m)
            cpp_ok = sum(r["covered_without_fill"] and not r["anchor"] for r in inv["units"])
            anc_ok = sum(r["anchor"] for r in inv["units"])
            log_print(
                f"[5/5] Unabhaengige Inventarpruefung (baum_inventar): C++={cpp_ok}/571, ANKER={anc_ok}/8 ({time.time() - t_inv:.1f}s)"
            )
        else:
            log_print(
                f"[5/5] Fix-Bau-Pruefung: {len(units)}/571 C/C++-Einheiten uebersetzt ({len(changed_fix_units)} mit aktivem Fix-Code), {anc_ok}/8 Anker erhalten, Symbole & WLINK fehlerfrei"
            )

        le_bytes = (m / "RIVA.EXE").read_bytes()
        full_exe = orig_exe_bytes[:DOS4GW_PREFIX_LEN] + le_bytes
        full_md5 = hashlib.md5(full_exe).hexdigest()
        full_sha256 = hashlib.sha256(full_exe).hexdigest()

        if fix_level == 0:
            status = (
                "GLEICH"
                if (full_md5 == GOOD and inv and inv["good"] and cpp_ok == 571 and anc_ok == 8)
                else "ABWEICHUNG"
            )
        else:
            link_ok = bool(
                link_res.get("done")
                and not link_res.get("errors")
                and not missing
                and not local
                and len(models) == 571
                and good_count == 571
            )
            if not changed_fix_units:
                status = "OK_IDENTISCH" if (link_ok and full_md5 == GOOD) else "FEHLER"
            else:
                status = "OK_FIXBAU" if link_ok else "FEHLER"

        # Ergebnisse sowohl in Build/<exe_name> als auch in out_dir ablegen
        ziel_build_exe = build_dir / exe_name
        ziel_build_exe.write_bytes(full_exe)
        (out_dir / exe_name).write_bytes(full_exe)
        (out_dir / le_exe_name).write_bytes(le_bytes)
        shutil.copy2(m / "RIVA.LNK", out_dir / "RIVA.LNK")
        (out_dir / "EINGABEN.json").write_text(json.dumps(provenance, indent=2) + "\n")
        (out_dir / "ERHALTENE_BEREICHE.json").write_text(json.dumps(allowed, indent=2) + "\n")
        (out_dir / "ERHALTENE_DATEN.json").write_text(json.dumps(data_proofs, indent=2) + "\n")
        if order is not None:
            (out_dir / "ORDNUNG.json").write_text(json.dumps(order, indent=2) + "\n")
        (out_dir / "SYMBOLE.json").write_text(
            json.dumps(
                dict(global_missing=missing, local_missing=local, added_data_aliases=added_data_aliases),
                indent=2,
            )
            + "\n"
        )
        if inv is not None:
            (out_dir / "INVENTAR.json").write_text(json.dumps(inv, indent=2) + "\n")

        soll_fix_md5 = (
            FIX_SOLL_MD5.get(fix_level)
            if (fix_exploits is None and not args.fixflags and not os.environ.get("FIX_EXTRA"))
            else None
        )
        nachweis = dict(
            timestamp=stamp,
            mode="normal" if fix_level == 0 else f"fix_{fix_level}",
            fix_level=fix_level,
            fix_define=f"-DFIX_BUGS={fix_level}" if fix_level > 0 else None,
            fix_exploits=fix_exploits,
            executable=exe_name,
            le_executable=le_exe_name,
            status=status,
            md5=full_md5,
            original_md5=GOOD,
            target_md5=soll_fix_md5,
            sha256=full_sha256,
            byte_identical_to_original=(full_exe == orig_exe_bytes),
            exe_bytes=len(full_exe),
            le_bytes=len(le_bytes),
            dos4gw_stub_bytes=DOS4GW_PREFIX_LEN,
            compiled_cpp_units=len(units),
            changed_fix_units_count=len(changed_fix_units),
            changed_fix_units=changed_fix_units,
            anchor_units=len(anchors),
            total_units=len(units) + len(anchors),
            native_code_pieces=len(pieces),
            partial_link_groups=len(groups),
            replaced_link_objects=len(touched),
            separated_data_objects=len(data_proofs),
            headers=headers,
            switch_headers=switch_headers,
            basis_archive="Bauen/baustand.tgz",
            basis_sha256=sha256_file(baustand_tgz),
            order_audit=(
                dict(
                    missing=len(order["missing"]),
                    extra=len(order["extra"]),
                    block_512_mismatches=order["results"][0]["count"],
                )
                if order is not None
                else "entfaellt im Fix-Modus bei geaenderten Funktionsgroessen"
            ),
            symbols_audit=dict(
                global_missing=len(missing),
                local_missing=len(local),
                added_data_aliases=len(added_data_aliases),
            ),
            wlink=link_res,
            duration_seconds=round(time.time() - t0, 2),
            build_exe=str(ziel_build_exe),
            output_dir=str(out_dir),
        )
        (out_dir / "NACHWEIS.json").write_text(json.dumps(nachweis, indent=2) + "\n")

        log_print("================================================")
        log_print(f"Zieldatei:    {ziel_build_exe} ({len(full_exe):,} Bytes)")
        log_print(f"MD5:          {full_md5}")
        if soll_fix_md5:
            log_print(f"Soll-MD5:     {soll_fix_md5}")
        log_print(f"Status:       {status}")
        log_print(f"Nachweise:    {out_dir}")
        log_print(f'Dauer:        {nachweis["duration_seconds"]}s')
        log_print("================================================")
        if fix_level == 0 and status == "GLEICH":
            log_print("BYTEGLEICH mit dem Original (alle 2.477.899 Bytes stimmen exakt ueberein)")
        log_file.close()
        if fix_level == 0:
            return 0 if status == "GLEICH" else 1
        return 0 if status in ("OK_IDENTISCH", "OK_FIXBAU") else 1
    finally:
        rmtree_safe(batch_dir)
        rmtree_safe(link_root)
        rmtree_safe(work_root)


if __name__ == "__main__":
    sys.exit(main())
