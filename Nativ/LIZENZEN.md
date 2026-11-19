# Lizenzen der mitgelieferten Bibliotheken

Das Spiel *Das Schwarze Auge 3: Schatten über Riva* (*Realms of Arkania 3: Shadows over Riva*) bleibt das kommerzielle Werk von Attic Entertainment Software / Fantasy Productions / TopWare Interactive (1996/1997). In `Port/release` sind **keine** Spieldaten, **keine** `RIVA.EXE` und **keine** eingebetteten Originalbytes enthalten (`0` übereinstimmende 64-Byte-Fenster; das Datensegment `DGROUP` wird erst beim Spielstart aus der eigenen `RIVA.EXE` des Nutzers geladen).

Diese Datei nennt die Lizenzen der im Port verwendeten freien Bibliotheken:

- **SDL2-Header & eingebauter Win32-Provider** (`Port/third_party/SDL2/`):
  - Die SDL2-Header (`SDL.h`) stehen unter der **zlib-Lizenz** (Copyright Sam Lantinga).
  - Der leichtgewichtige Win32-GDI/WinMM-Provider (`sdl2_win32_provider.c`) stellt die benötigten SDL2-Video-, Audio-, Timer- und Eingabefunktionen direkt über die Windows-Systembibliotheken (`gdi32`, `user32`, `winmm`) bereit, sodass keine externe `SDL2.dll` mitgeliefert werden muss.
- **stb_vorbis** (`Port/third_party/stb_vorbis/stb_vorbis.c`, von Sean Barrett):
  - Dual-lizenziert unter **Public Domain (Unlicense)** bzw. **MIT-Lizenz**. Dekodiert die Ogg-Vorbis-CD-Musikspuren (`MUSIC\Track02..13.ogg`) der GOG-Fassung direkt im Programm, sodass keine externen `libogg`/`libvorbis`-DLLs erforderlich sind.
- **OPL2-FM-Synthesizer (YM3812-Emulation in `Port/platform/riva_crt_and_stubs.cpp`)**:
  - Basiert auf der freien OPL2/AdLib-Emulation (**LGPL v2.1+ / GPL v2+**).
- **BRender Software-Renderer-Strukturen** (`Port/platform/riva_3d_brender.cpp`):
  - **MIT-Lizenz** (Argonaut Software / BRender Open-Source-Release), soweit Konstanten und Datenstrukturen der 3D-Pipeline aus der BRender-Referenz stammen.
