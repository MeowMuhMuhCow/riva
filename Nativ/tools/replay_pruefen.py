#!/usr/bin/env python3
"""Ein begrenzter Port-Replay; Belege bleiben zusammen unter Port/."""
import argparse
import hashlib
import json
import re
import shutil
import subprocess
import time
from pathlib import Path

PORT = Path(__file__).resolve().parents[1]

def win(path):
    return subprocess.check_output(["wslpath", "-w", str(path)]).decode().strip()

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("replay", type=Path)
    ap.add_argument("out", type=Path)
    ap.add_argument("--exe", type=Path, default=PORT / "build/RIVA_PORT.EXE")
    ap.add_argument("--game", type=Path, default=PORT / "spiel")
    ap.add_argument("--save", default="TEST2B")
    ap.add_argument("--seconds", type=int, default=120)
    args = ap.parse_args()
    for p in [args.out, args.game]:
        if not p.resolve().is_relative_to(PORT):
            ap.error("Testablage und Spielkopie müssen unter Port liegen.")
    if args.save:
        save_name = args.save if args.save.upper().endswith(".GAM") else args.save + ".GAM"
        saves = args.game / "GAMES"
        if not saves.is_dir() or not any(p.name.upper() == save_name.upper() for p in saves.iterdir()):
            ap.error("Der angeforderte Spielstand fehlt: " + save_name)
    # Nur prüfen: fremde laufende Spiele niemals beenden.
    ps_bin = shutil.which("powershell.exe") or "/mnt/c/Windows/System32/WindowsPowerShell/v1.0/powershell.exe"
    cmd = "@(Get-Process -ErrorAction SilentlyContinue | Where-Object {$_.ProcessName -match '^RIVA_PORT'}).Count"
    count = subprocess.check_output([ps_bin, "-NoProfile", "-NonInteractive", "-Command", cmd],
                                    stdin=subprocess.DEVNULL, timeout=20).decode().strip()
    if count != "0":
        raise RuntimeError("Eine Port-EXE läuft bereits: " + count)
    out = args.out.resolve()
    out.mkdir(parents=True, exist_ok=False)
    exe = out / args.exe.name
    shutil.copy2(args.exe, exe)
    for dll in (PORT / "release/bin").glob("*.dll"):
        shutil.copy2(dll, out / dll.name)
    replay = out / "probe.rpl"
    shutil.copy2(args.replay, replay)
    for name in ["absturz.log", "crash.log", "stubs.log"]:
        src = args.game / name
        if src.exists():
            inherited = out / "vorherige_logs"
            inherited.mkdir(exist_ok=True)
            shutil.move(str(src), inherited / name)
    command = [ps_bin, "-NoProfile", "-NonInteractive", "-ExecutionPolicy", "Bypass",
               "-File", win(PORT / "tools/win_lauf.ps1"), "-Exe", win(exe),
               "-Seconds", str(args.seconds), "-WorkDir", win(out)]
    if args.save:
        command.append(args.save)
    command += ["--gamedir", win(args.game.resolve()), "--replay", win(replay)]
    started = time.monotonic()
    p = subprocess.run(command, stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                       stderr=subprocess.STDOUT, timeout=args.seconds + 15)
    expected = re.findall(r"^SHOT\s+(\S+)", replay.read_text(), re.M)
    errors = {str(folder / name): (folder / name).stat().st_size
              for folder in [out, args.game] for name in ["absturz.log", "crash.log", "stubs.log"]
              if (folder / name).exists() and (folder / name).stat().st_size}
    result = {"exit": p.returncode, "seconds": round(time.monotonic() - started, 2),
              "output": p.stdout.decode(errors="replace"), "exe_md5": hashlib.md5(exe.read_bytes()).hexdigest(),
              "images": {f.name: hashlib.md5(f.read_bytes()).hexdigest() for f in out.glob("*.bmp")},
              "missing_images": [name for name in expected if not (out / name).is_file()], "error_logs": errors, "fatal_messages": re.findall(r"GURU Meditation|Unhandled exception", p.stdout.decode(errors="replace"), re.I)}
    (out / "lauf.json").write_text(json.dumps(result, indent=2))
    print(json.dumps(result, indent=2), flush=True)
    return int(p.returncode != 0 or bool(errors) or bool(result["missing_images"]) or bool(result["fatal_messages"]))

if __name__ == "__main__":
    raise SystemExit(main())
