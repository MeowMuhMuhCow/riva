# Schatten über Riva — nativ unter Windows starten

Stand: 19.11.2026 (Version 1.0).

## Spiel starten

Einfach im Ordner `Port\release` (bzw. im entpackten Release-Paket) eine der Startdateien doppelt anklicken:

| Startdatei | Bedeutung |
| --- | --- |
| `Riva_starten_WICHTIGE_FIXES.bat` | **Empfohlene Fassung** (`RIVA_PORT_WICHTIG.EXE`, `FIX_BUGS=1`: alle wichtigen Fehlerkorrekturen aktiv) |
| `Riva_starten_WICHTIGE_FIXES_MIT_PROBENLOG.bat` | Wichtige Fehlerkorrekturen + Live-Probenlog-Fenster (`PROBEN.CSV`) |
| `Riva_starten_ALLE_FIXES.bat` | Alle Fehlerkorrekturen inkl. Balance-/Exploit-Korrekturen (`RIVA_PORT_ALLES.EXE`, `FIX_BUGS=2`) |
| `Riva_starten_ALLE_FIXES_MIT_PROBENLOG.bat` | Alle Fehlerkorrekturen + Live-Probenlog-Fenster (`PROBEN.CSV`) |
| `Riva_starten_ORIGINAL.bat` | Originalverhalten von 1996/1997 ohne Spielkorrekturen (`RIVA_PORT_ORIG.EXE`, `FIX_BUGS=0`) |
| `start_riva.bat` / `start_riva.ps1` | Universeller Starter (unterstützt `--kein-intro`, `--probenlog` und einen expliziten Spielpfad) |

### Automatische Spielordner-Erkennung & Schreibschutz-Absicherung

1. Der Starter und die Port-EXEs suchen die eigene Original-Installation von *DSA 3: Schatten über Riva* (*Realms of Arkania 3: Shadows over Riva*, Version V1.12 / GOG) automatisch über `SPIELPFAD.txt` oder die üblichen GOG-Installationspfade (`C:\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania 3`, `C:\GOG Games\Realms of Arkania 3` usw.).
2. Im gefundenen Spielordner müssen `RIVA.EXE` (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) und `DATA\RIVA.ALF` liegen. Die Original-Dateien werden **nicht** verändert.
3. **Keine Originalbytes in den Port-EXEs**: Die Programme unter `bin\` enthalten keine eingebetteten Originaldaten (`0` übereinstimmende 64-Byte-Fenster zu `RIVA.EXE`), sondern laden das Datensegment (`DGROUP`) erst beim Programmstart im Arbeitsspeicher aus der eigenen `RIVA.EXE` des Spielers.
4. **Schreibschutz-Absicherung (`Spielstaende\`)**: Liegt das Originalspiel in einem schreibgeschützten Ordner (z. B. unter `C:\Program Files (x86)\...`), leitet der Port Spielstände (`GAMES\*.GAM`), temporäre Dateien (`TEMP\`, `CTEMP\`), `RIVA.CFG` und `PROBEN.CSV` automatisch in den Ordner `Spielstaende\` neben der EXE um und kopiert vorhandene Spielstände beim ersten Start dorthin.
5. **Vorspann überspringen (`--kein-intro`)**: Mit dem Schalter `--kein-intro` (oder `-KeinIntro` in `start_riva.ps1`) startet das Spiel ohne Logo-Sequenzen und ohne Intro-Video direkt im Hauptmenü-Tempel.

## Live-Probenlog & Browser-Auswertung

Beim Start über `Riva_starten_WICHTIGE_FIXES_MIT_PROBENLOG.bat` oder `Riva_starten_ALLE_FIXES_MIT_PROBENLOG.bat` öffnet sich neben dem Spiel ein zweites Fenster (**„DSA Schatten über Riva – Live-Probenlog"**), das jede Eigenschafts-, Talent-, Zauber-, Attacke-, Parade- und Fernkampfprobe im selben Moment farbig anzeigt.

Zusätzlich lässt sich die erzeugte `PROBEN.CSV` (sowie archivierte Läufe aus `Probenlogs\`) jederzeit in `Probenlog\Probenlog_Riva.html` im Browser öffnen, filtern und statistisch je Held, Talent und Zauber auswerten (Details siehe `Probenlog\LIESMICH.md`).

## Funktionsumfang

- Vollständiger nativer 32-Bit-Windows-Port aller 576 Übersetzungseinheiten ohne DOSBox:
  - Alle 2D-Bildschirme, Charaktergenerator (inkl. deutscher Umlaute `äöüÄÖÜß`), Inventar, Händler, Tempel, Taverne, Heiler, Tagebuch, Automap und bidirektional mit dem DOS-Original kompatible Spielstände (`GAMES\*.GAM`).
  - Vollständiger 3D-Software-Renderer (BRender) für alle Stadtviertel Rivas sowie alle Dungeons (Kanalisation, Zwergenmine, Hügelgrab, Magierturm, Borontempel-Keller, Piratenhöhle, Wasserdungeon, Wasserturm/Gefängnis, Königinnenbau und Gelber Turm).
  - Alle Videos und Animationen: Smacker-Videos (`*.SMK` inkl. 320×200-Intro und 640×480-SVGA-Abspann `OUTRO01S..03S`), FLC/CEL-Sequenzen, ACE/BOB-Animationen und lippensynchrone Sprachporträts.
  - Komplette Audio-Engine ohne externe Vorbis-DLLs (`stb_vorbis` direkt integriert): CD-Audio-Musik (`MUSIC\Track02..13.ogg` wie in der GOG-Fassung), XMIDI-Hintergrundmusik über zyklusgenauen OPL2-Synthesizer (3812-Emulation), RAW/VOC-Soundeffekte und gesampelte Sprachausgabe (`SPEX` direkt aus `GAME.GOG`).
  - Vollständig durchgespielt und verifiziert vom Intro über alle Kapitel bis zum Endkampf im Gelben Turm, der Riesenhive-Königin, der Siegmeldung, dem 640×480-SVGA-Abspann und der abschließenden Spielpunkte-Abrechnung.

Neu bauen: siehe `BAUEN.md`. Lizenzen: `LIZENZEN.md`.
