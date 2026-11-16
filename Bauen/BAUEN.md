# Bauanleitung – `RIVA.EXE` selbst kompilieren

Diese Anleitung zeigt Schritt für Schritt, wie du aus dem rekonstruierten C/C++-Quelltext in `Quelle/` und dem Basis-Baustand (`Bauen/baustand.tgz`) mit dem historischen Original-Compiler **Watcom C/C++ 10.6** eine eigene `RIVA.EXE` baust – wahlweise **100 % byte-identisch** zum Original von 1997 (Version 1.12) oder als **fehlerbereinigte Fassung** (`RIVA_FIX_WICHTIG.EXE` bzw. `RIVA_FIX_ALLES.EXE`).

> **Du möchtest nur die fehlerbereinigte Version spielen, ohne selbst zu kompilieren?**  
> Dann brauchst du keinen Compiler (und unter Windows auch kein Python): Doppelklick auf **[`PATCHEN.bat`](../PATCHEN.bat)** im Hauptordner genügt.

---

## Was wird benötigt?

1. **Windows 10 / 11** (oder **Linux / WSL** mit Python 3 und DOSBox)
2. **Python 3** (ab 3.9, kostenlos unter <https://www.python.org/downloads/>)
   - Wichtig bei der Installation unter Windows: Haken bei **„Add Python to PATH"** setzen!
   - *(Alternativ ohne Systeminstallation: das „Windows embeddable package (64-bit)" nach `Bauen\python\` entpacken, sodass `Bauen\python\python.exe` existiert.)*
3. **Deutsche GOG-Version von „DSA 3: Schatten über Riva"** (*Realms of Arkania 3 – Shadows over Riva*, Version 1.12)
   - Daraus stammt die Original-`RIVA.EXE` (`2.477.899 Bytes`, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`), aus der der gebundene **DOS/4GW-Professional-2.00-Starter** (die ersten 232.804 Bytes) und der innere Linker-Stub (`STUB.EXE`, 11.408 Bytes) übernommen werden, sowie die mitgelieferte **DOSBox** für den Linkerlauf und zum Spielen.
4. **Watcom C/C++ 10.6** (von 1996)
   - Aus Urheberrechtsgründen ist der Compiler **nicht** in diesem Paket enthalten.

---

## Schritt 1: Watcom C/C++ 10.6 in `Compiler\` ablegen

Kopiere deine Installation von **Watcom C/C++ 10.6** in den Ordner `Compiler\`, sodass dort die Unterordner `BINNT\`, `BINW\` (bzw. `BINB\`) und `H\` liegen. Das Bauskript durchsucht `Compiler\` automatisch nach:

- `WPP386.EXE` (Watcom 32-Bit-C++-Compiler)
- `WCC386.EXE` (Watcom 32-Bit-C-Compiler)
- `WLINK.EXE` (Watcom Linker 10.6 samt `DOS4GW.EXE` und `WLSYSTEM.LNK` in `BINW\`)
- `H\STDIO.H` usw. (Standard-Header in `H\` und `H\SYS\`)

Siehe auch [`Compiler/HIER_COMPILER_REIN.txt`](../Compiler/HIER_COMPILER_REIN.txt).

---

## Schritt 2: `RIVA.EXE` nach `Original\` kopieren

Kopiere die Datei `RIVA.EXE` aus deiner deutschen GOG-Installation in den Ordner:

```
Original\RIVA.EXE
```

*(Falls deine GOG-Installation bereits über `SPIELPFAD_SUCHEN.cmd` in `SPIELPFAD.txt` hinterlegt ist, findet `bauen.py` die Originaldatei auch direkt dort.)*

Zur Kontrolle die Eckdaten der unterstützten Original-EXE (deutsche Version 1.12 vom 5. Mai 1997):
- **Größe:** `2.477.899` Bytes
- **MD5:** `fb8f5fc3ba5454c7344c17aaf362de35`

---

## Schritt 3: Bauen starten

### A) Originalgetreue `RIVA.EXE` (100 % byte-identisch)

Unter Windows einfach doppelt anklicken:

```bat
Bauen\BAUEN.bat
```

Oder auf der Kommandozeile (Windows / WSL / Linux):

```bash
python3 Bauen/bauen.py
```

Ablauf der 5 Bauschritte (`[1/5]` bis `[5/5]`):
1. Erfassen der **571 C/C++-Einheiten** (`Quelle/cpp/*_P1.CPP`) und **8 Hand-ASM-Anker**.
2. Frische Batch-Kompilierung aller 571 C/C++-Einheiten mit `WPP386.EXE` / `WCC386.EXE` (`-4r -oneatx -zp1 -s`).
3. Objekt-, Symbol- und Relokationsprüfung jedes erzeugten `.OBJ` (`fragment_model`).
4. Einsetzen aller 571 Einheiten in den Basis-Linkbaum (`Bauen/baustand.tgz`), Prüfung der 512-Byte-Relokationsseiten-Ordnung und Gesamtlink mit **`WLINK 10.6`** in DOSBox.
5. Unabhängige Inventar- und Bytegleichheitsprüfung (`baum_inventar`) sowie Voranstellen des DOS/4GW-Vorspanns -> **`Build/RIVA.EXE`**.

Am Ende meldet das Skript:

```
================================================
Zieldatei:    ...\Build\RIVA.EXE (2,477,899 Bytes)
MD5:          fb8f5fc3ba5454c7344c17aaf362de35
Soll-MD5:     fb8f5fc3ba5454c7344c17aaf362de35
Status:       GLEICH
================================================
BYTEGLEICH mit dem Original (alle 2.477.899 Bytes stimmen exakt ueberein)
```

### B) Fehlerbereinigte Versionen bauen (`wichtig` / `alles`)

Über denselben Quelltext lassen sich per Präprozessor-Schalter (`Quelle/inc/R_FIX.H`, `Quelle/inc/R_PLOG.H`, `Quelle/inc/r_fix.inc`) die fehlerbereinigten Varianten übersetzen:

```bat
REM Stufe A (empfohlen): nur 100% sichere Original-Bugs (-DFIX_BUGS=1) -> Build\RIVA_FIX_WICHTIG.EXE
Bauen\BAUEN.bat wichtig

REM Stufe B: alle Korrekturen inkl. Stufe A (-DFIX_BUGS=2) -> Build\RIVA_FIX_ALLES.EXE
Bauen\BAUEN.bat alles

REM Optional: Exploits zum Vorteil des Spielers drinlassen (-DFIX_EXPLOITS=0)
Bauen\BAUEN.bat alles --exploits-lassen
```

Unter WSL / Linux entsprechend:

```bash
python3 Bauen/bauen.py wichtig    # oder: python3 Bauen/bauen.py --fix 1
python3 Bauen/bauen.py alles      # oder: python3 Bauen/bauen.py --fix 2
```

| Fassung | Aufruf | Zieldatei in `Build/` | Größe | Erwartete MD5 | Bauzeit |
|---|---|---|---:|---|---|
| **Original** | `Bauen\BAUEN.bat` | `RIVA.EXE` | `2.477.899` B | `fb8f5fc3ba5454c7344c17aaf362de35` | ca. **75 s** |
| **Stufe A (Wichtig, 31 Fixes)** | `Bauen\BAUEN.bat wichtig` | `RIVA_FIX_WICHTIG.EXE` | `2.507.083` B | `8e1fb73fcf6cad374aa6d4076f13a64d` | ca. **2,5–4 min** |
| **Stufe B (Alles, 52 Fixes)** | `Bauen\BAUEN.bat alles` | `RIVA_FIX_ALLES.EXE` | `2.507.083` B | `d8dba0e2ecb2ced9b380ea708b8be25f` | ca. **2,5–4 min** |

Alle Details zu den einzelnen Bugfix-Schaltern (`FIX_R001` .. `FIX_R092`) stehen in **[`FIXES.md`](FIXES.md)** und **[`../BUGFIXES.md`](../BUGFIXES.md)**.

---

## Was der Bau benutzt

| Teil | Woher |
|---|---|
| Rekonstruierte C/C++-Quellen (571 Einheiten) | `Quelle\cpp\*_P1.CPP` |
| Gemeinsame Header & Bugfix-/Probenlog-Schalter (21 `.H` + `r_fix.inc`) | `Quelle\inc\` |
| Basis-Linkbaum (8 Hand-ASM-Anker, `DGROUP`-Datenobjekte, Watcom-Laufzeit, Zuordnungstabellen) | `Bauen\baustand.tgz` |
| Python-Linker- & OMF-Werkzeuge | `Bauen\werkzeuge\` |
| Watcom C/C++ 10.6 (`WPP386`, `WCC386`, `WLINK`) | `Compiler\` (der Bau arbeitet in einer temporären Kopie) |
| Original-EXE (für DOS/4GW-Vorspann, `STUB.EXE` und Bytevergleich) | `Original\RIVA.EXE` |
| DOSBox 0.74 (für den `WLINK`-Lauf) | GOG: `Realms of Arkania 3\DOSBOX\DOSBox.exe` oder `--dosbox PFAD` |
| Bau-Protokoll & Prüfbelege (`NACHWEIS.json`, `EINGABEN.json`, `SYMBOLE.json`) | `Build\bau.log` sowie `Build\nachweis_original\`, `Build\nachweis_wichtig\`, `Build\nachweis_alles\` |

---

## Technische Eckdaten der Übersetzung

- **Compiler:** Watcom C/C++ 10.6 (`wpp386.exe` / `wcc386.exe`)
- **Standard-Schalter:** `-4r -oneatx -zp1 -s`
  - `-4r`: 486-Codegenerierung mit Register-Aufrufkonvention (`__watcall`: Parameter in `EAX`, `EDX`, `EBX`, `ECX`)
  - `-oneatx`: Optimierungspaket (Loop-/Zeit-/Alias-/Inline-/Frame-Optimierungen)
  - `-zp1`: Struktur-Packing auf 1-Byte-Grenzen (wichtig für alle Spielstände, Heldenbögen und Archivformate)
  - `-s`: Keine Stack-Overflow-Prüfungen im Funktionsprolog
- **Code-Segmente:** `_TEXT` (`0x010010..0x15689C`), `_TEXT1` (`0x15689D..0x15DE0F`), `_TEXT2` (`0x15DE10..0x175FFD`), `_TEXT3` (`0x175FFE..0x199B43`)
- **Daten-Segmente:** `DGROUP` (`0x1A0000..0x1F7D3F`, initialisierte Daten `DATA`/`CONST` bis `0x1BC5EF`, uninitialisiertes `BSS`/`STACK` ab `0x1BC5F0`)
- **DOS-Extender:** Gebundener DOS/4GW Professional 2.00 (`Original\RIVA.EXE[:0x38D64]`, 232.804 Bytes) + innerer `wlink`-Stub (`STUB.EXE`, 11.408 Bytes) + 32-Bit-LE-Abbild (`2.233.687` Bytes im Original) = `2.477.899` Bytes.
