# DSA 3: Schatten über Riva (1996 / V1.12) – Vollständige C++-Rekonstruktion

Vollständige, **100 % byte-identische** Rekonstruktion des C/C++-Quelltexts von **„Das Schwarze Auge: Schatten über Riva"** (*Realms of Arkania III: Shadows over Riva*, Attic Entertainment Software, 1996; deutscher Patch V1.12 vom 5. Mai 1997) für das Hauptprogramm **`RIVA.EXE`**.

Wenn man den hier enthaltenen Quelltext mit dem historischen Original-Compiler **Watcom C/C++ 10.6** übersetzt und mit dem DOS/4GW-Vorspann der eigenen Original-EXE bindet, entsteht eine `RIVA.EXE`, die in **allen 2.477.899 Bytes** (MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) exakt mit der deutschen Originaldatei übereinstimmt.

Zusätzlich lassen sich aus demselben Quelltext per Schalter **zwei fehlerbereinigte Versionen** bauen (**Stufe A: WICHTIG** mit **31 sicheren Original-Bugs** und **Stufe B: ALLES** mit sämtlichen **52 Korrekturen**) – oder ganz ohne Compiler per Doppelklick auf `PATCHEN.bat` direkt aus der eigenen Original-EXE erzeugen.

> **Status der Bugfix-Fassungen (TESTVERSION – Tester willkommen!):**  
> Die Rekonstruktion der Original-`RIVA.EXE` ist zu 100 % byte-identisch abgeschlossen. Die beiden fehlerbereinigten Fassungen (`RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE`) sind technisch und statisch vollständig geprüft, im Spiel wurde bisher aber **nur der Programmstart getestet**.  
> **Wir suchen Tester:** Bitte spielt mit den Fix-Fassungen, nutzt gerne das **Live-Probenlog** (`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat` bzw. `./Linux/starten.sh wichtig --log`) und meldet Fehler oder Auffälligkeiten mit Angabe der verwendeten Fassung, der `R`-Nummer aus [`BUGFIXES.md`](BUGFIXES.md) und gerne einem Spielstand (`.GAM`)!

> **Wichtiger Hinweis:** Dieses Repository enthält **keine Spieldaten**, **keine `RIVA.EXE`** und **keinen Compiler**. Zum Spielen oder Nachbauen benötigst du eine eigene legale Kopie der deutschen Version von *Schatten über Riva* (z. B. von [GOG.com](https://www.gog.com/)). Siehe [`RECHTE.md`](RECHTE.md).

---

## Schnellstart (für Spieler – ohne Compiler)

Du hast die deutsche GOG-Version von *Schatten über Riva* installiert und möchtest direkt die **fehlerbereinigte Testversion** spielen? Das kompakte Bugfix-Paket (`riva_Bugfix_1.0.zip`) gibt es rechts unter **Releases** (oder über **Code → Download ZIP**).

### Unter Windows

1. Doppelklick auf **`PATCHEN.bat`**
   - Sucht deine GOG-Installation automatisch (oder öffnet einen Ordner-Auswahldialog), prüft die `RIVA.EXE` (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) und erzeugt über die kompakten Differenzdateien (`Patch\RIVA_FIX_WICHTIG.ndp` mit **149 KB** und `Patch\RIVA_FIX_ALLES.ndp` mit **164 KB**) im Unterordner `Build\` die beiden fehlerbereinigten Fassungen `RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE` (je `2.507.083` Bytes).
   - Deine Original-Installation und deine Original-Spielstände werden dabei **nicht** verändert.
2. Doppelklick auf eine der Startdateien:
   - **`RIVA_FIX_WICHTIG_STARTEN.bat`** *(empfohlen – Stufe A: **31** sichere Original-Bugs behoben)*
   - **`RIVA_FIX_ALLES_STARTEN.bat`** *(Stufe B: alle **52** Korrekturen)*
   - oder mit **Live-Probenlog-Fenster** (zeigt nebenbei jeden Talent-, Zauber-, Eigenschafts- und Kampfwurf mit allen W20-Würfeln farbig an):
     - **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`**
     - **`RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat`**

### Unter Linux

Nativ mit `python3` und der Linux-`dosbox` (ohne Wine/PowerShell) – ausführliche Anleitung in **[`Linux/LIESMICH.md`](Linux/LIESMICH.md)**:

```bash
chmod +x Linux/*.sh
./Linux/patchen.sh                  # erzeugt RIVA_FIX_WICHTIG.EXE + RIVA_FIX_ALLES.EXE
./Linux/starten.sh wichtig          # Spiel starten (oder: alles / wichtig --log)
```

---

## Drei Versionen aus einer Quelle

| Version | Datei | Compiler-Schalter | Beschreibung |
|---|---|---|---|
| **1. Original (1997)** | `Build\RIVA.EXE` | *(Standard / `-DFIX_BUGS=0`)* | **100 % byte-identisch** zur deutschen `RIVA.EXE` V1.12 (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`). Alle historischen Bugs sind exakt so enthalten wie 1997. |
| **2. WICHTIG (Stufe A)** | `Build\RIVA_FIX_WICHTIG.EXE` | `-DFIX_BUGS=1` | **Empfohlen (Testversion):** Behebt **31 sichere Original-Programmierfehler** (Abstürze, Hänger, Schmied-Waffenverlust, unheilbarer Dumpfschädel, Sternenschweif-Stirnreif, Lorenfahrt, Magierturm-Endlosschleife; davon **2 abschaltbare Exploit-Fixes**: `R042`, `R043`). Größe: `2.507.083` Bytes, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`, Patch `149 KB`. |
| **3. ALLES (Stufe B)** | `Build\RIVA_FIX_ALLES.EXE` | `-DFIX_BUGS=2` | **Testversion:** Enthält alle **31** Korrekturen aus **Stufe A** plus **21 zusätzliche Detail-, Anzeige-, Feilschen-, Alchemie- und Randfall-Fixes** (**52 Bugfixes** gesamt, davon **5 abschaltbare Exploit-Fixes**). Größe: `2.507.083` Bytes, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`, Patch `164 KB`. |

Alle Details zu den 52 behobenen Fehlern stehen in **[`BUGFIXES.md`](BUGFIXES.md)**, die technischen Schalter für eigene Builds in **[`Bauen/FIXES.md`](Bauen/FIXES.md)**.

---

## Selbst aus dem C++-Quelltext kompilieren

Wer mit dem historischen Compiler **Watcom C/C++ 10.6** selbst die `RIVA.EXE` aus dem Quelltext übersetzen und die Byte-Gleichheit überprüfen möchte:

1. **Watcom C/C++ 10.6** in den Ordner `Compiler\` legen (siehe [`Compiler/HIER_COMPILER_REIN.txt`](Compiler/HIER_COMPILER_REIN.txt)).
2. Eigene **`RIVA.EXE`** (deutsche GOG-Version V1.12) in den Ordner `Original\` legen (siehe [`Original/HIER_RIVA_EXE_REIN.txt`](Original/HIER_RIVA_EXE_REIN.txt)).
3. Bauen starten:
   ```bat
   Bauen\BAUEN.bat           REM -> Build\RIVA.EXE (100% byte-identisch)
   Bauen\BAUEN.bat wichtig   REM -> Build\RIVA_FIX_WICHTIG.EXE (Stufe A)
   Bauen\BAUEN.bat alles     REM -> Build\RIVA_FIX_ALLES.EXE   (Stufe B)
   ```

Schritt-für-Schritt-Anleitung: **[`START_HIER.md`](START_HIER.md)** und **[`Bauen/BAUEN.md`](Bauen/BAUEN.md)**.

---

## Eckdaten der Rekonstruktion

| Kennzahl | Wert |
|---|---|
| **Zieldatei** | `RIVA.EXE` (deutsche Version 1.12 vom 05.05.1997, GOG *Realms of Arkania 3*) |
| **Dateigröße** | `2.477.899` Bytes (232.804 Bytes DOS/4GW-Pro-2.00-Vorspann + 2.245.095 Bytes `wlink`-Programm) |
| **MD5-Prüfsumme** | `fb8f5fc3ba5454c7344c17aaf362de35` (inneres LE-Programm: `02c3229924c34cfebab48c34f35304f7`) |
| **Original-Compiler** | Watcom C/C++ 10.6 (`wpp386.exe` / `wcc386.exe`, Schalter `-4r -oneatx -zp1 -s`) |
| **Übersetzungseinheiten** | **579 Einheiten** gesamt: **571 C/C++-Einheiten** (`1.380.545` Bytes Code) + **8 Hand-ASM-/Fremdcode-Anker** (`45.736` Bytes: Miles-Audio/SOS-Treiber, SVGA-Blit-Kern, Watcom-Laufzeitkern) |
| **Funktionen** | **6.834 Funktionen**, alle mit deutscher Beschreibung im Quelltext |
| **Watcom-Geistervariablen** | Von **8.149 auf 950** reduziert (Rest in 5 Einheiten: `uvesa` 484, `fi_g_tar_t1` 272, `fi_opt` 109, `gz_0350b0_t1` 55, `menu` 30; 566 von 571 Einheiten komplett geisterfrei) |
| **Gemeinsame Header** | **19 Riva-Header** (`RIVAMEM.H`, `RIVAHERO.H`, `RIVAHAPI.H`, `RIVACTX.H`, `RIVACDAT.H`, `RIVAIMG.H`, `RIVAITEM.H`, `RIVAITEX.H`, `RIVAITBL.H`, `RIVAFILE.H`, `RIVASTRM.H`, `RIVAACE.H`, `RIVAMOUS.H`, `RIVAAIF.H`, `RIVATEXT.H`, `RIVAVECT.H`, `RIVA_HELD.H`, `RIVA_KOEPFE.H`, `RIVA_CLOBBER.H`) + Fix-/Probenlog-Header (`R_FIX.H`, `r_fix.inc`, `R_PLOG.H`) |
| **Fehlerbehebung (Testversion)** | **52 Bugfixes**: **31** in Stufe A (`RIVA_FIX_WICHTIG.EXE`, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`, davon 2 abschaltbare Exploit-Fixes: `R042`, `R043`) + **21** zusätzlich in Stufe B (`RIVA_FIX_ALLES.EXE`, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`), je `2.507.083` Bytes |
| **Binär-Patches (ohne Compiler)** | `Patch/RIVA_FIX_WICHTIG.ndp` (**149 KB**), `Patch/RIVA_FIX_ALLES.ndp` (**164 KB**) |
| **Übereinstimmung (Original-Modus)** | **100,000 %** (`2.477.899` von `2.477.899` Bytes identisch, 0 Byte-Abweichungen) |
| **Bauzeit (Komplettbau)** | Original ca. **75 s**, Fix-Fassungen ca. **2,5–4 min** |

---

## Wegweiser durch das Repository

- **[`START_HIER.md`](START_HIER.md)** — Schnellstart zum Selbst-Kompilieren und Starten
- **[`LIESMICH.md`](LIESMICH.md)** — Einführung in den rekonstruierten Quelltext (Aufbau, Module, Lese-Einstieg)
- **[`BUGFIXES.md`](BUGFIXES.md)** — Übersicht der drei Spiel-Versionen und aller 52 behobenen Original-Bugs
- **[`ABSCHLUSSBERICHT.md`](ABSCHLUSSBERICHT.md)** — Technischer Abschlussbericht und Kennzahlen der Rekonstruktion
- **[`Bauen/BAUEN.md`](Bauen/BAUEN.md)** — Technische Bauanleitung (Watcom 10.6, Segmente, Linker)
- **[`Bauen/FIXES.md`](Bauen/FIXES.md)** — Dokumentation aller Präprozessor-Schalter (`FIX_BUGS`, `FIX_EXPLOITS`, `FIX_Rnnn`)
- **[`Probenlog/LIESMICH.md`](Probenlog/LIESMICH.md)** — Live-Probenlog-Fenster beim Spielen
- **[`Linux/LIESMICH.md`](Linux/LIESMICH.md)** — Anleitung für Linux-Nutzer
- **[`RECHTE.md`](RECHTE.md)** — Urheberrecht, Lizenz und Dank

---

## Dank & verwandte Projekte

Dieses Projekt steht auf den Schultern der deutschsprachigen DSA-Klassiker-Community:

- **[Bright-Eyes](https://github.com/Henne/Bright-Eyes)** (Henne, [siebenstreich](https://github.com/siebenstreich/BrightEyes) u. a.) – die bahnbrechende Rekonstruktion der *Schicksalsklinge* war Vorbild und Wegbereiter für die gesamte Nordlandtrilogie-Analyse.
- **cmfrydos** – entschlüsselt mit dem **Riva HD Viewer** die Datenformate der Nordlandtrilogie (Dungeons, Ereigniszonen, Dialoge, Kampfsystem) und teilt seine Ergebnisse offen im Forum und im Wiki.
- **Crystals-DSA-Forum** (<https://www.crystals-dsa-foren.de/>) – über Jahrzehnte gesammeltes Wissen zu Spielmechanik, Datenformaten, Quests und Bugs in *Schatten über Riva*.
- **Schwesterprojekte (Nordlandtrilogie komplett bytegleich):** [Die Schicksalsklinge (DSA 1)](https://github.com/MeowMuhMuhCow/schicksalsklinge) · [Sternenschweif (DSA 2)](https://github.com/MeowMuhMuhCow/sternenschweif)
- **Attic Entertainment Software** (Hans-Jürgen Brändle, Guido Henkel, Jochen Hamma und das gesamte Entwicklerteam von 1996) – für den unvergesslichen Abschluss der Nordlandtrilogie.

MooMoo mit Claude und Gemini, November 2026.
