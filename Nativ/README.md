# Schatten über Riva — Native 32-bit Windows Port

Version 1.0 (19 Nov 2026). Detailed German documentation is in `START_HIER.md`.

This package runs the native 32-bit Windows port of *Das Schwarze Auge 3: Schatten über Riva* (*Realms of Arkania 3: Shadows over Riva*, V1.12) without DOSBox. It contains **no commercial game assets and no embedded original binary data**: at startup, the executable locates your own installation (`SPIELPFAD.txt` or a standard GOG *Realms of Arkania 3* directory), verifies `RIVA.EXE` (`2,477,899` bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`), and loads the `DGROUP` data segment into memory at runtime.

## Quick Start

Double-click one of the `.bat` launchers in this directory:

- `Riva_starten_WICHTIGE_FIXES.bat` — **Recommended** (`bin\RIVA_PORT_WICHTIG.EXE` / `bin\RIVA_PORT.EXE`, `FIX_BUGS=1`: important bug fixes enabled)
- `Riva_starten_WICHTIGE_FIXES_MIT_PROBENLOG.bat` — Important bug fixes + live dice-roll log window (`PROBEN.CSV`)
- `Riva_starten_ALLE_FIXES.bat` — All bug and exploit/balance fixes (`bin\RIVA_PORT_ALLES.EXE`, `FIX_BUGS=2`)
- `Riva_starten_ALLE_FIXES_MIT_PROBENLOG.bat` — All fixes + live dice-roll log window (`PROBEN.CSV`)
- `Riva_starten_ORIGINAL.bat` — Original 1996/1997 behaviour (`bin\RIVA_PORT_ORIG.EXE`, `FIX_BUGS=0`)
- `start_riva.bat` / `start_riva.ps1` — Universal launcher supporting `--kein-intro` (`--skip-intro`), `--probenlog`, and an explicit game path argument

No external Ogg/Vorbis DLLs are required (`stb_vorbis` is compiled directly into the executable). If the game installation directory is read-only (e.g. under `C:\Program Files (x86)\...`), savegames (`GAMES\*.GAM`), temporary files (`TEMP\`, `CTEMP\`), `RIVA.CFG`, and `PROBEN.CSV` are automatically redirected to `Spielstaende\` next to the executable.

## Features

- All 576 compilation units compiled natively for 32-bit Windows.
- Bidirectional savegame compatibility (`GAMES\*.GAM`) with the 1996/1997 DOS original.
- Full BRender 3D software renderer (city of Riva and all dungeons), 2D menus, character generator (with German umlauts), tactical combat, Smacker (`*.SMK`) and FLC videos including the 640×480 SVGA credits (`OUTRO01S..03S`), ACE/BOB animations, and lip-synced portrait animations.
- Full audio support: GOG CD audio tracks (`MUSIC\Track02..13.ogg` via integrated `stb_vorbis`), OPL2 FM synthesis for XMIDI music, RAW/VOC sound effects, and `SPEX` speech audio read directly from `GAME.GOG`.
- Verified end-to-end from the intro across all main quest chapters through the Yellow Tower finale, the Giant Hive Queen battle, the victory screen, the 640×480 SVGA outro, and the final score screen.

## Build & Licenses

See `BAUEN.md` for build instructions and `LIZENZEN.md` for third-party library licenses.
