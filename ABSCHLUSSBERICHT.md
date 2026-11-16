# Abschlussbericht – Byte-identische C++-Rekonstruktion von „DSA 3: Schatten über Riva" (V1.12)

## 1. Gesamtergebnis

Das Hauptprogramm **`RIVA.EXE`** der deutschen Version **1.12** (vom 5. Mai 1997, GOG *Realms of Arkania 3 – Shadows over Riva*) von *Das Schwarze Auge: Schatten über Riva* (Attic Entertainment Software, 1996) wurde vollständig in C/C++ rekonstruiert.

Beim Übersetzen mit dem historischen Original-Compiler **Watcom C/C++ 10.6** (`wpp386.exe` / `wcc386.exe`, Schalter `-4r -oneatx -zp1 -s`), Assemblieren der 8 handgeschriebenen Assembler-/Treiber-Ankerbereiche mit `wasm.exe`, Linken mit `wlink.exe` (`@RIVA.LNK`) und Binden mit dem DOS/4GW-Professional-2.00-Vorspann der Originaldatei entsteht eine ausführbare Datei, die in **allen 2.477.899 Bytes** (MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) zu **100,000 %** mit dem Original von 1997 übereinstimmt.

---

## 2. Kennzahlen im Überblick

| Kennzahl | Wert |
|---|---|
| **Zieldatei** | `RIVA.EXE` (deutsche Version 1.12 vom 05.05.1997) |
| **Dateigröße** | `2.477.899` Bytes (`0x25CFA3`) |
| **MD5 (Gesamtdatei)** | `fb8f5fc3ba5454c7344c17aaf362de35` |
| **MD5 (inneres `wlink`-Programm ab `0x38D64`)** | `02c3229924c34cfebab48c34f35304f7` (`2.245.095` Bytes) |
| **DOS/4GW-Pro-2.00-Vorspann (`0x00000..0x38D63`)** | `232.804` Bytes |
| **Innerer MZ-Linker-Stub `STUB.EXE` (`0x38D64..0x3B9F3`)** | `11.408` Bytes |
| **Übersetzungseinheiten (`teile_alle.tsv`)** | **579** Einheiten gesamt |
| — davon **C/C++-Einheiten** | **571** Einheiten (`1.380.545` Bytes Code) |
| — davon **Hand-ASM-/Fremdcode-Anker** | **8** Einheiten (`45.736` Bytes: Miles-Audio/SOS-Treiber, SVGA-Blit-Kern, Watcom-Laufzeitkern) |
| **Funktionen** | **6.834** Funktionen, alle mit deutscher Beschreibung im Quelltext |
| **Gemeinsame Header (`Quelle/inc/`)** | **19** Riva-Header (`RIVA*.H`) + `R_FIX.H`, `r_fix.inc`, `R_PLOG.H` |
| **Verbleibende Byte-Abweichungen im Original-Modus** | **0** |
| **Fehlerkorrekturen (Stufe A / Stufe B, Testversionen)** | **52 Bugfixes** gesamt: **31** in Stufe A (`RIVA_FIX_WICHTIG.EXE`, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`, davon 2 abschaltbare Exploit-Fixes: `R042`, `R043`) und **21** zusätzlich in Stufe B (`RIVA_FIX_ALLES.EXE`, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`, insgesamt 5 abschaltbare Exploit-Fixes), je `2.507.083` Bytes |
| **Binär-Patches ohne Compiler (`Patch/`, Format `NDP2`)** | `RIVA_FIX_WICHTIG.ndp` (**149 KB**), `RIVA_FIX_ALLES.ndp` (**164 KB**) |
| **Watcom-Geistervariablen / Dokumentationsstand** | Von **8.149 auf 950** reduziert (Rest in 5 Einheiten: `uvesa` 484, `fi_g_tar_t1` 272, `fi_opt` 109, `gz_0350b0_t1` 55, `menu` 30; 566 von 571 C/C++-Einheiten komplett geisterfrei); alle 6.834 Funktionen deutsch kommentiert |
| **Bauzeit (Komplettbau)** | Original ca. **75 s**, Fix-Fassungen ca. **2,5–4 min** |

---

## 3. Technische Besonderheiten von *Schatten über Riva*

1. **Watcom C/C++ 10.6 mit Register-Aufrufkonvention (`-4r`):**  
   Anders als die 16-Bit-Vorgänger *Schicksalsklinge* und *Sternenschweif* (Borland C++ 3.1, Stack-Aufrufkonvention, Overlays) nutzt *Schatten über Riva* durchgängig 32-Bit-Code mit Watcoms Register-Aufrufkonvention (`__watcall`, erste vier Argumente in `EAX`, `EDX`, `EBX`, `ECX`) und dem Optimierungspaket `-oneatx`.
2. **Vier Code-Segmente (`_TEXT`, `_TEXT1`, `_TEXT2`, `_TEXT3`):**  
   Das Code-Layout erstreckt sich von `0x010010` bis `0x199B43` über vier Code-Segmente, gefolgt vom gemeinsamen Datensegment `DGROUP` (`0x1A0000..0x1FC56F`).
3. **Abgleich mit der unoptimierten Demo von 1996:**  
   Über die unoptimierte Demo-EXE von 1996 (mit Original-Pfadspuren und unverschmolzenen Funktionsgrenzen) sowie die gemeinsamen Header-Definitionen (`RIVAHERO.H`, `RIVAITEM.H`, `RIVACTX.H` usw.) konnten die internen Klassen- und Strukturverträge über alle 571 C/C++-Einheiten hinweg konsistent zusammengeführt werden.
