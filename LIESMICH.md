# DSA 3: Schatten über Riva (1996 / V1.12) – Führung durch den Quelltext

Willkommen im rekonstruierten C/C++-Quelltext von **„Das Schwarze Auge: Schatten über Riva"** (deutsche Version 1.12 vom 5. Mai 1997, GOG *Realms of Arkania 3 – Shadows over Riva*).

Dieses Dokument gibt dir einen schnellen Überblick darüber, was hier vorliegt, wie das Programm technisch aufgebaut ist und wo du beim Stöbern im Quelltext am besten anfängst.

---

## 1. Erste Schritte

- **Du möchtest sofort die fehlerbereinigte Version spielen (ohne Compiler)?**  
  → Doppelklick auf **[`PATCHEN.bat`](PATCHEN.bat)** und danach auf **[`RIVA_FIX_WICHTIG_STARTEN.bat`](RIVA_FIX_WICHTIG_STARTEN.bat)** (bzw. unter Linux `./Linux/patchen.sh` und `./Linux/starten.sh`).
- **Du möchtest die `RIVA.EXE` selbst aus dem Quelltext kompilieren?**  
  → Lies **[`START_HIER.md`](START_HIER.md)** und **[`Bauen/BAUEN.md`](Bauen/BAUEN.md)**.
- **Du möchtest wissen, welche Original-Bugs von 1996/1997 behoben werden?**  
  → Lies **[`BUGFIXES.md`](BUGFIXES.md)** (für Spieler) und **[`Bauen/FIXES.md`](Bauen/FIXES.md)** (Schalter im Code).

---

## 2. Was steckt in `RIVA.EXE`?

Anders als *Schicksalsklinge* (1992) und *Sternenschweif* (1994), die noch als 16-Bit-Real-Mode-Programme mit Borland C++ 3.1 und Overlay-Manager (`OVR`) übersetzt wurden, ist *Schatten über Riva* (1996) ein **32-Bit-Protected-Mode-Programm** (Linear Executable `LE` mit gebundenem **DOS/4GW Professional 2.00**), übersetzt mit **Watcom C/C++ 10.6** (`wpp386.exe` / `wcc386.exe`, Schalter `-4r -oneatx -zp1 -s`).

Ein besonderer Glücksfall für die Rekonstruktion: In der 1996 veröffentlichten **Demo-Version** von *Schatten über Riva* lagen zahlreiche Module unoptimiert und mit originalen Debug-/Symbolspuren sowie Original-Quelldateipfaden (`C:\RIVA\SRC\...`) vor. Dadurch ließen sich Modulzuschnitte, Klassennamen und Funktionsstrukturen der Vollversion V1.12 mit hoher Präzision wiederherstellen.

### Umfang des Programms

- **`RIVA.EXE` gesamt:** `2.477.899` Bytes (MD5 `fb8f5fc3ba5454c7344c17aaf362de35`)
  - `232.804` Bytes (`0x00000..0x38D63`): Gebundener DOS/4GW-Professional-2.00-Extender
  - `11.408` Bytes (`0x38D64..0x3B9F3`): Innerer MZ-Stub (`STUB.EXE`) des Watcom-Linkers
  - `2.233.687` Bytes (`0x3B9F4..Ende`): 32-Bit-LE-Programmabbild (Code-Segmente `_TEXT`, `_TEXT1`, `_TEXT2`, `_TEXT3` und Datensegment `DGROUP`)
- **579 Übersetzungseinheiten** (gemäß `teile_alle.tsv`):
  - **571 C/C++-Einheiten** (`1.380.545` Bytes Maschinencode) – 100 % aus C/C++ mit Watcom 10.6 übersetzt
  - **8 Hand-ASM-/Fremdcode-Ankereinheiten** (`45.736` Bytes) – handgeschriebene Assembler-Routinen (Audio-/SOS-Treiber, SVGA-Grafikkern, Watcom-Laufzeit-Startup)
- **6.834 Funktionen**, alle mit deutscher Beschreibung ihrer Aufgabe, Parameter und Spielwirkung im Quelltext dokumentiert.
- **Watcom-Geistervariablen:** von **8.149 auf 950** reduziert (verbleibender Rest in 5 Einheiten: `uvesa` 484, `fi_g_tar_t1` 272, `fi_opt` 109, `gz_0350b0_t1` 55, `menu` 30; 566 von 571 C/C++-Einheiten sind komplett geisterfrei).
- **52 Fehlerkorrekturen (Testversionen):** **31** in Stufe A (`RIVA_FIX_WICHTIG.EXE`, `2.507.083` Bytes, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`, davon 2 abschaltbare Exploit-Fixes: `R042`, `R043`) und **21** zusätzlich in Stufe B (`RIVA_FIX_ALLES.EXE`, `2.507.083` Bytes, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`, insgesamt 5 abschaltbare Exploit-Fixes).
- **Bauzeit (Komplettbau):** Original ca. **75 s**, Fix-Fassungen ca. **2,5–4 min**; kompakte Binär-Patches ohne Compiler: `RIVA_FIX_WICHTIG.ndp` (**149 KB**), `RIVA_FIX_ALLES.ndp` (**164 KB**).

---

## 3. Die Ordnerstruktur im Überblick

```
riva/
├── README.md                               Hauptseite (Projektüberblick & Schnellstart)
├── LIESMICH.md                             Diese Einführung in den Quelltext
├── START_HIER.md                           Schritt-für-Schritt-Anleitung zum Selbst-Kompilieren
├── BUGFIXES.md                             Beschreibung der drei Spielversionen & aller 52 Bugfixes
├── ABSCHLUSSBERICHT.md                     Technischer Abschlussbericht & Kennzahlen
├── RECHTE.md                               Urheberrecht & Lizenzhinweise
│
├── PATCHEN.bat                             Erzeugt RIVA_FIX_*.EXE ohne Compiler aus deiner RIVA.EXE
├── RIVA_STARTEN.bat                        Startet die originalgetreu gebaute Build\RIVA.EXE
├── RIVA_FIX_WICHTIG_STARTEN.bat            Startet Build\RIVA_FIX_WICHTIG.EXE (Stufe A, empfohlen)
├── RIVA_FIX_ALLES_STARTEN.bat              Startet Build\RIVA_FIX_ALLES.EXE   (Stufe B)
├── RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat  Startet Stufe A + Live-Probenlog-Fenster
├── RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat    Startet Stufe B + Live-Probenlog-Fenster
├── SPIELPFAD_SUCHEN.cmd                    Findet automatisch den GOG-Installationsordner
│
├── Quelle/                                 Der rekonstruierte Quelltext
│   ├── inc/                                Zentrale Header (R_FIX.H, r_fix.inc, R_PLOG.H + 19 RIVA*.H)
│   └── cpp/                                Die 571 C/C++-Übersetzungseinheiten (6.834 Funktionen)
│
├── Bauen/                                  Nachbau-Skripte (BAUEN.bat, bauen.py, baustand.tgz, BAUEN.md, FIXES.md)
├── Patch/                                  Binär-Patcher ohne Compiler (patchen.ps1, patchen.py, *.ndp)
├── Probenlog/                              Live-Anzeige aller Würfelproben (Windows & Linux)
├── Linux/                                  Native Linux-Skripte (patchen.sh, starten.sh, LIESMICH.md)
├── Werkzeuge/                              Hilfsskripte für Schalter & Patches (mk_baupaket.py, mkfix.py, mkpatch.py)
├── Compiler/                               Ablageort für Watcom C/C++ 10.6 (vom Nutzer beizusteuern)
└── Original/                               Ablageort für deine RIVA.EXE V1.12 (vom Nutzer beizusteuern)
```

---

## 4. Wo fange ich beim Lesen an? (Lese-Empfehlungen)

### A) Die gemeinsamen Header (`Quelle/inc/` bzw. `Quelle/cpp/*.H`)

In den 16 thematischen D23-Headern sind die zentralen Datenstrukturen und Klassenverträge des Spiels zusammengefasst:

| Header | Inhalt |
|---|---|
| `RIVAHERO.H` / `RIVA_HELD.H` | Helden-Datenstruktur (`Held`), Attribute (MU, KL, CH, FF, GE, IN, KK, Aberglaube …), Talente, Zauber, LE/AE, Ausrüstung und Zustände |
| `RIVAHAPI.H` | Gemeinsame Helden- und Gruppen-Zugriffsfunktionen |
| `RIVAITEM.H` / `RIVAITEX.H` / `RIVAITBL.H` | Gegenstände, Waffen, Rüstungen, Kräuter, Tränke und Inventar-Tabellen |
| `RIVACTX.H` / `RIVACDAT.H` | Kampf-Kontext, Kampffeld, Gegner- und Aktionsstrukturen im rundenbasierten Taktikkampf |
| `RIVAIMG.H` / `RIVAACE.H` | Grafik-, Bild-, Sprite- und ACE-Animationsstrukturen |
| `RIVAFILE.H` / `RIVASTRM.H` | Archiv-/Dateizugriff (`ALF`-Archive, Streams, Spielstände) |
| `RIVAMEM.H` / `RIVAVECT.H` | Speicherverwaltung und Container-/Listenklassen (`arylist`, `unilist`) |
| `RIVAMOUS.H` / `RIVAAIF.H` / `RIVATEXT.H` | Maus-/UI-Steuerung, Audio-Interface und Text-/Dialogausgabe |
| `r_fix.h` / `r_plog.h` | Zentrale Schalter für die fehlerbereinigten Builds (`FIX_BUGS=1` / `2`) und das Live-Probenlog |

### B) Ausgewählte Spielmodule in `Quelle/cpp/`

- **Alchimie, Kräuter & Heilung:** `alchemy_P1.CPP`, `healer_P1.CPP`, `herb_P1.CPP`
- **Götter, Tempel & Wunder:** `deity_P1.CPP`
- **Taktikkampf & Kampfbrett:** `board_P1.CPP`, `combat_P1.CPP` / `fight*`
- **3D-Stadt, Automap & Dungeons:** `amap_t12_P1.CPP`, `amap_t345_P1.CPP`, `castle*`, `mine*`, `sewerag*`, `ship*`, `tower*`, `underw*`
- **Animationen & Grafik:** `ace_t1_P1.CPP`..`ace_t3_P1.CPP`, `ani_t1_P1.CPP`, `ani_t2_P1.CPP`, `svga*`
- **Archive & Spielstände:** `alfdisk_P1.CPP`, `loadsave*`
- **Endkampf & Finale:** `final1*`, `final2*`, `endkampf*`

---

## 5. Konventionen im Quelltext

Damit Watcom C/C++ 10.6 aus jeder einzelnen Funktion exakt dieselben Maschinenbefehle, dieselbe Registerbelegung und dieselben Stack-Offsets erzeugt wie 1996/1997, enthält der Quelltext einige gezielte Annotationen:

1. **Einheits-Optionen (`// OPT ...` und `// CC wcc386`):**  
   In der ersten Zeile einer Quelldatei stehen bei Bedarf spezielle Watcom-Schalter (Standard: `-4r -oneatx -zp1 -s`; reine C-Module tragen `// CC wcc386`).
2. **Funktionsmarkierungen (`//@ f_xxxxxx`):**  
   Jede rekonstruierte Funktion beginnt mit ihrer virtuellen Startadresse im Code-Segment (`0x010010..0x199B43`), sodass man sie jederzeit direkt mit dem Original-Disassembly und der unoptimierten 1996er Demo vergleichen kann.
3. **Bugfix-Blöcke (`#if FIX_Rnnn`):**  
   Alle Korrekturen für `RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE` sind mit `#if FIX_Rnnn ... #else ... #endif` gekapselt. Ist `FIX_BUGS == 0` (Standard), übersetzt der Compiler ausschließlich den `#else`-Zweig (Original von 1997).
