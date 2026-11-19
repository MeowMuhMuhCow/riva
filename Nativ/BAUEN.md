# Bauen aus dem Quelltext

Aus dem Projektordner wird der gesamte native Port mit einem Befehl gebaut:

```bash
python3 Port/bauen_port.py
```

## Ablauf

1. `Port/tools/prepare_sources.py` bereitet die 576 rekonstruierten C++-Einheiten nach `Port/src/cpp/` vor.
2. `Port/tools/gen_data.py` liest die Symbol- und Relokationsstruktur aus der eigenen `RIVA.EXE` (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`, gesucht unter `Original/RIVA.EXE`, `SPIELPFAD.txt` oder im GOG-Ordner) und erzeugt einen reinen `.bss`-Reservierungsblock (`riva_dgroup.S`) sowie die Relokationstabelle (`0` eingebettete Originalbytes; das Datensegment wird erst beim Spielstart zur Laufzeit aus der `RIVA.EXE` des Spielers geladen).
3. Alle 576 Einheiten werden mit dem 32-Bit-MinGW-GCC (`g++.exe -m32 -mabi=sysv -std=gnu++98 -fpermissive -funsigned-char -O1`) in den drei Fix-Stufen (`FIX_BUGS=0`, `FIX_BUGS=1`, `FIX_BUGS=2`) übersetzt und über `Port/tools/normalize_objs.py` normalisiert.
4. Die SDL2-Plattformschicht (`Port/platform/`), der integrierte Win32-SDL2-Provider (`Port/third_party/SDL2/sdl2_win32_provider.c`) und `stb_vorbis` (`Port/third_party/stb_vorbis/stb_vorbis.c`) werden übersetzt und ohne externe DLL-Abhängigkeiten zu `RIVA_PORT_ORIG.EXE`, `RIVA_PORT_WICHTIG.EXE`, `RIVA_PORT_ALLES.EXE` und `RIVA_PORT.EXE` unter `Port/build/` gelinkt.
5. `python3 Port/tools/pruefe_port_rechte.py` prüft abschließend alle gebauten EXEs im gleitenden 64-Byte-Fenster gegen `RIVA.EXE` (`0` Treffer).

## Schalter

- `--fix 0`, `--fix 1`, `--fix 2` oder `--fix alle` (Standard: `alle`)
- `--no-prepare`: überspringt `prepare_sources.py`, wenn `Port/src/cpp/` bereits aktuell ist
