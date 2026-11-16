# DSA 3: Schatten über Riva unter Linux spielen (und bauen)

Alle Werkzeuge in diesem Projekt funktionieren auch nativ unter **Linux** – ohne Windows, ohne PowerShell und ohne die mitgelieferte `DOSBox.exe` aus dem GOG-Ordner.

---

## Voraussetzungen

1. **`python3`** (auf fast jeder Linux-Distribution bereits vorinstalliert)
2. **`dosbox`** (oder `dosbox-staging` / `dosbox-x`) aus der Paketverwaltung:
   - **Debian / Ubuntu / Linux Mint:** `sudo apt install dosbox python3`
   - **Fedora:** `sudo dnf install dosbox-staging python3`
   - **Arch / Manjaro:** `sudo pacman -S dosbox python`
   - **openSUSE:** `sudo zypper install dosbox python3`
3. **Deutsche GOG-Version von „DSA 3: Schatten über Riva"** (*Realms of Arkania 3*, Version 1.12), z. B. installiert über:
   - **Lutris** oder **Heroic Games Launcher**,
   - **Wine**, oder
   - direkt entpackt aus dem Offline-Installer von GOG (`innoextract setup_realms_of_arkania_3_*.exe`).  
   Wichtig ist nur, dass der Ordner mit `RIVA.EXE` (`2.477.899 Bytes`, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`), den Spieldaten und `game.ins` irgendwo auf der Platte liegt.

---

## 1. Fehlerbereinigte Version erzeugen (ohne Compiler)

Einmalig im Hauptordner des Projekts ausführen:

```bash
chmod +x Linux/*.sh
./Linux/patchen.sh
```

Falls der Spielordner nicht automatisch in `~/GOG Games/...` oder `~/Games/...` gefunden wird, öffnet das Skript einen Ordner-Auswahldialog (bzw. fragt im Terminal nach dem Pfad) und merkt ihn sich in `SPIELPFAD.txt`. Alternativ kannst du den Pfad direkt übergeben:

```bash
./Linux/patchen.sh "/pfad/zu/Realms of Arkania 3"
```

Das Skript prüft die MD5-Prüfsumme deiner `RIVA.EXE` und legt im Unterordner `Build/` beide fehlerbereinigten Versionen an:
- `Build/RIVA_FIX_WICHTIG.EXE` (**Stufe A**, empfohlen: nur 100 % sichere Original-Bugs behoben)
- `Build/RIVA_FIX_ALLES.EXE` (**Stufe B**: alle Korrekturen)

Dein Original-Spielordner wird dabei **nicht** verändert.

---

## 2. Spiel starten

```bash
# Empfohlene Version (Stufe A: sichere Fixes) starten:
./Linux/starten.sh

# Oder explizit auswählen:
./Linux/starten.sh wichtig          # RIVA_FIX_WICHTIG.EXE (Stufe A)
./Linux/starten.sh alles            # RIVA_FIX_ALLES.EXE   (Stufe B)
./Linux/starten.sh original         # RIVA.EXE (selbst gebauter Nachbau)
```

### Mit Live-Probenlog im Terminal

Wenn du beim Spielen live im Terminal sehen möchtest, was bei Talent-, Zauber-, Attribut- und Kampfproben gewürfelt wird:

```bash
./Linux/starten.sh wichtig --log
# bzw.
./Linux/starten.sh alles --log
```

### Was macht `starten.sh` automatisch für Linux?

1. **Saubere Spielumgebung:** Kopiert die Spieldateien beim ersten Start nach `Build/Testspielstaende_Fix_Wichtig/` (bzw. `..._Fix_Alles/`), sodass deine Original-Installation unangetastet bleibt und vorhandene Spielstände (auch aus `cloud_saves/`) übernommen werden.
2. **CD-Musik (`game.ins`):** In GOGs `game.ins` stehen Windows-Backslashes (`MUSIC\Track02.OGG`), mit denen eine native Linux-DOSBox die OGG-Musikdateien sonst nicht findet. `starten.sh` legt deshalb automatisch eine bereinigte `game_linux.ins` mit normalen Schrägstrichen an und bindet sie als Laufwerk `D:` ein.

---

## 3. Optional: Selbst aus dem C++-Quelltext kompilieren

Auch das Bauskript `Bauen/bauen.py` läuft direkt unter Linux mit `python3`:

```bash
# Originalgetreuer Nachbau (100% byte-identisch, MD5 fb8f5fc3ba5454c7344c17aaf362de35):
python3 Bauen/bauen.py

# Fehlerbereinigte Versionen selbst kompilieren:
python3 Bauen/bauen.py wichtig
python3 Bauen/bauen.py alles
```

Voraussetzung dafür sind (genau wie unter Windows) der historische Compiler **Watcom C/C++ 10.6** in `Compiler/` und die `RIVA.EXE` in `Original/` – siehe [`START_HIER.md`](../START_HIER.md).
