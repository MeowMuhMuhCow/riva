# Schnellstart – Bauen & Spielen

## Nur spielen (fehlerbereinigte Testversion, ohne Compiler)

> **Hinweis zur Testversion – Tester gesucht!**  
> Die beiden fehlerbereinigten Fassungen (`RIVA_FIX_WICHTIG.EXE` mit **31 Fixes** und `RIVA_FIX_ALLES.EXE` mit **52 Fixes**) sind technisch und statisch vollständig geprüft, im Spiel wurde bisher aber **nur der Programmstart getestet**.  
> **Bitte an alle Tester:** Spielt mit den Fix-Fassungen, lasst gerne das **Live-Probenlog** mitlaufen und meldet Beobachtungen oder Fehler mit Angabe der Fassung, der `R`-Nummer aus [`BUGFIXES.md`](BUGFIXES.md) und gerne einem Spielstand (`.GAM`)!

Wenn du die fehlerbereinigten Versionen (`RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE`) einfach direkt spielen möchtest, brauchst du **keinen Compiler** (und unter Windows auch **kein Python**):

1. **Unter Windows:** Doppelklick auf **[`PATCHEN.bat`](PATCHEN.bat)** → wendet über PowerShell (`Patch\patchen.ps1`) die kompakten Binär-Patches (`Patch\RIVA_FIX_WICHTIG.ndp`, **149 KB**, und `Patch\RIVA_FIX_ALLES.ndp`, **164 KB**) auf deine eigene deutsche GOG-`RIVA.EXE` (Version 1.12, `2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) an und erzeugt im Ordner `Build\` bitgenau beide fehlerbereinigten EXEs:
   - `Build\RIVA_FIX_WICHTIG.EXE` (`2.507.083` Bytes, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`, **Stufe A: 31 sichere Korrekturen**, davon 2 abschaltbare Exploit-Fixes: `R042`, `R043`)
   - `Build\RIVA_FIX_ALLES.EXE` (`2.507.083` Bytes, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`, **Stufe B: alle 52 Korrekturen**: 31 A + 21 B)
   Danach starten mit:
   - **`RIVA_FIX_WICHTIG_STARTEN.bat`** *(empfohlen: Stufe A, 31 sichere Korrekturen)*
   - **`RIVA_FIX_ALLES_STARTEN.bat`** *(Stufe B: alle 52 Korrekturen)*
   - oder mit Live-Probenlog: **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`** / **`RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat`**
2. **Unter Linux:** `./Linux/patchen.sh` (nutzt `Patch/patchen.py`) und `./Linux/starten.sh` – siehe **[`Linux/LIESMICH.md`](Linux/LIESMICH.md)**.

---

## Selbst aus dem C++-Quelltext kompilieren (in 3 Schritten)

Dieses Paket enthält den rekonstruierten C/C++-Quelltext von **„Das Schwarze Auge 3: Schatten über Riva"** (1996 / Patch V1.12 von 1997, **571 Übersetzungseinheiten** mit **6.834 deutsch kommentierten Funktionen** in `Quelle/cpp/` und 21 Header inkl. Schalter-Headern in `Quelle/inc/`) sowie den zugehörigen Basis-Baustand (`Bauen/baustand.tgz` mit den **8 Hand-ASM-Ankern**, Datenobjekten und Laufzeit-Modulen).  
Aus Urheberrechtsgründen sind **keine Spieldaten**, **keine `RIVA.EXE`** und **kein Compiler** enthalten.

Um aus dem Quelltext selbst deine eigene, **100 % byte-identische `RIVA.EXE`** (oder die fehlerbereinigten Fassungen) zu kompilieren, legst du einmalig zwei Dinge bereit:

---

### Schritt 1: Watcom C/C++ 10.6 in `Compiler\` ablegen

Kopiere eine Installation des historischen Compilers **Watcom C/C++ 10.6** (von 1996) in den Ordner `Compiler\`, sodass dort die Unterordner `BINNT\`, `BINW\` (bzw. `BINB\`) und `H\` liegen (siehe [`Compiler/HIER_COMPILER_REIN.txt`](Compiler/HIER_COMPILER_REIN.txt)).

---

### Schritt 2: Deine `RIVA.EXE` in `Original\` ablegen

Kopiere die Datei **`RIVA.EXE`** aus deiner eigenen deutschen GOG-Installation (*Realms of Arkania 3 – Shadows over Riva*, Version 1.12) in den Ordner:

```
Original\RIVA.EXE
```

- Erwartete Größe: **`2.477.899` Bytes**
- Erwartete MD5: **`fb8f5fc3ba5454c7344c17aaf362de35`**

Sie wird für den gebundenen DOS/4GW-Professional-2.00-Vorspann (die ersten 232.804 Bytes), den inneren Linker-Stub (`STUB.EXE`, 11.408 Bytes) und für den anschließenden Byte-für-Byte-Vergleich benötigt.

---

### Schritt 3: Bauen starten!

Voraussetzung: **Python 3** (unter <https://www.python.org/downloads/>, Haken bei *„Add Python to PATH"* setzen) sowie die mit dem GOG-Spiel installierte **DOSBox** (wird automatisch für den `WLINK`-Lauf genutzt).

Unter Windows einfach doppelt anklicken:

```bat
Bauen\BAUEN.bat
```

Oder auf der Kommandozeile (Windows bzw. WSL/Linux) eine der drei Varianten wählen:

```bat
REM 1. Originalgetreuer Nachbau (100% byte-identisch, ca. 75 s) -> Build\RIVA.EXE (MD5 fb8f5fc3ba5454c7344c17aaf362de35)
Bauen\BAUEN.bat

REM 2. Fehlerbereinigt Stufe A ("wichtig", 31 Fixes, ca. 2,5-4 min) -> Build\RIVA_FIX_WICHTIG.EXE (MD5 8e1fb73fcf6cad374aa6d4076f13a64d)
Bauen\BAUEN.bat wichtig

REM 3. Fehlerbereinigt Stufe B ("alles", 52 Fixes, ca. 2,5-4 min)   -> Build\RIVA_FIX_ALLES.EXE (MD5 d8dba0e2ecb2ced9b380ea708b8be25f)
Bauen\BAUEN.bat alles
```

Unter WSL / Linux:

```bash
python3 Bauen/bauen.py            # -> Build/RIVA.EXE (ca. 75 s)
python3 Bauen/bauen.py wichtig    # -> Build/RIVA_FIX_WICHTIG.EXE (ca. 2,5-4 min)
python3 Bauen/bauen.py alles      # -> Build/RIVA_FIX_ALLES.EXE (ca. 2,5-4 min)
```

Alle Details zum Bauablauf stehen in **[`Bauen/BAUEN.md`](Bauen/BAUEN.md)**.

---

## Die selbst gebaute Version in DOSBox starten

Nach dem Bauen (oder Patchen) kannst du jede der drei Versionen direkt über die Startskripte im Hauptordner starten:

- **`RIVA_STARTEN.bat`** — startet die originalgetreue `Build\RIVA.EXE` (Spielstände in `Build\Testspielstaende`)
- **`RIVA_FIX_WICHTIG_STARTEN.bat`** — startet `Build\RIVA_FIX_WICHTIG.EXE` (Spielstände in `Build\Testspielstaende_Fix_Wichtig`)
- **`RIVA_FIX_ALLES_STARTEN.bat`** — startet `Build\RIVA_FIX_ALLES.EXE` (Spielstände in `Build\Testspielstaende_Fix_Alles`)
- **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`** / **`RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat`** — startet die jeweilige Fix-Fassung samt Live-Probenlog-Fenster

Deine Original-Installation im GOG-Ordner bleibt in allen Fällen **völlig unangetastet**; vorhandene Spielstände werden beim ersten Start automatisch in den jeweiligen Test-Ordner kopiert.
