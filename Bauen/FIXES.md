# Bugfix-Schalter in `Quelle/inc/R_FIX.H`

Alle Fehlerkorrekturen sind einzeln mit `#if FIX_Rnnn` geklammert und im Standard-Build **ausgeschaltet** (`RIVA.EXE` bleibt 100 % bytegleich zum Original von 1997, Version 1.12, `2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`).

Die Definitionen liegen aufgeteilt in:
- **`Quelle/inc/R_FIX.H`** — Hauptschalter (`FIX_BUGS`, `FIX_EXPLOITS`) und Stufen-Logik (`FIX_STUFE_A`, `FIX_STUFE_A_EXPLOIT`, `FIX_STUFE_B`, `FIX_STUFE_B_EXPLOIT`)
- **`Quelle/inc/r_fix.inc`** — Liste aller **52 Einzelschalter** `FIX_R001` … `FIX_R092`

---

## 1. Stufen-Schalter (`FIX_BUGS`)

| Aufruf / Schalter | Wirkung | Zieldatei (`Größe` / `MD5`) |
|---|---|---|
| `Bauen\BAUEN.bat` bzw. `python3 Bauen/bauen.py` (`-DFIX_BUGS=0`) | **Alle Fixes aus** — 100 % bytegleiches Original V1.12 (Standard) | `Build/RIVA.EXE`<br>(`2.477.899` B, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) |
| `Bauen\BAUEN.bat wichtig` bzw. `python3 Bauen/bauen.py wichtig` (`-DFIX_BUGS=1`) | **Stufe A** — Abstürze, Hänger, kaputte Spielmechanik (**31 Fixes**, davon 2 abschaltbare Exploit-Fixes: `R042`, `R043`) | `Build/RIVA_FIX_WICHTIG.EXE`<br>(`2.507.083` B, MD5 `8e1fb73fcf6cad374aa6d4076f13a64d`) |
| `Bauen\BAUEN.bat alles` bzw. `python3 Bauen/bauen.py alles` (`-DFIX_BUGS=2`) | **Stufe A + B** — zusätzlich kleinere Logik-, Anzeige- und Randfallfehler (**52 Fixes**: 31 A + 21 B, davon 5 Exploits) | `Build/RIVA_FIX_ALLES.EXE`<br>(`2.507.083` B, MD5 `d8dba0e2ecb2ced9b380ea708b8be25f`) |

---

## 2. Exploit-Fixes behalten (`--exploits-lassen`)

Einige bekannte Fehler verschaffen dem Spieler einen Vorteil (z. B. Heilung per *Hexenspeichel* oder *Armatrutz*-Rüstungsschutz ohne ausreichende Astralenergie, Alchemie-Rezepte mit zu knapper Restzeit brauen oder kostenlose Gold-Rückerstattung bei vollem Inventar im Laden). Wer alle technischen Fehler und Abstürze beheben, aber diese **5 klassischen Spielervorteile wie 1997 behalten** möchte:

```bat
Bauen\BAUEN.bat wichtig --exploits-lassen
Bauen\BAUEN.bat alles   --exploits-lassen
```

bzw. unter Linux / WSL:

```bash
python3 Bauen/bauen.py wichtig --exploits-lassen
python3 Bauen/bauen.py alles   --exploits-lassen
```

Unter Watcom entspricht das dem zusätzlichen Schalter `-DFIX_EXPLOITS=0`. Damit werden alle als `FIX_STUFE_A_EXPLOIT` (`FIX_R042`, `FIX_R043`) bzw. `FIX_STUFE_B_EXPLOIT` (`FIX_R025`, `FIX_R037`, `FIX_R041`) markierten Korrekturen automatisch auf `0` gesetzt.

---

## 3. Einzelne Fixes gezielt ein- oder ausschalten

Jeder Schalter in `r_fix.inc` ist mit `#ifndef FIX_Rnnn` geschützt und kann beim Übersetzen über `--fixflags` (bzw. direkt bei `wpp386`/`wcc386`) einzeln überschrieben werden:

- **Alles aus Stufe A, aber einen bestimmten Fix ausschalten:**
  ```bash
  python3 Bauen/bauen.py wichtig --fixflags="-DFIX_R043=0"
  ```
- **Mehrere Einzelschalter gezielt übersteuern:**
  ```bash
  python3 Bauen/bauen.py alles --fixflags="-DFIX_R042=0 -DFIX_R043=0"
  ```

---

## 4. Eigene Zusammenstellung in `Quelle/inc/r_fix.inc`

Wer dauerhaft eine eigene Auswahl treffen möchte, kann in `Quelle/inc/r_fix.inc` bei jedem gewünschten Schalter den Wert direkt auf `1` (immer an) oder `0` (immer aus) setzen:

```c
/* R001: gz_13bb70_t2 / f_13d5d0, f_13d920 - memset-Parameterreihenfolge (0, 12) statt (12, 0) vor DPMI-Interrupt 0x31 */
#ifndef FIX_R001
#define FIX_R001 FIX_STUFE_A
#endif

/* R025: alchemy / f_012dd0 - Unterlauf work.tab[-1] bei Rezeptauswahl-Abbruch verhindern; Braudauer in Stunden statt Tagen pruefen */
#ifndef FIX_R025
#define FIX_R025 FIX_STUFE_B_EXPLOIT
#endif

/* R026: gz_038ba0_t1 / f_039cf0 - Klammerung !(f_043600(p1, i) % 12) bei Krankheits-Nachheilung (Dumpfschaedel heilt alle 12 Stunden aus) */
#ifndef FIX_R026
#define FIX_R026 FIX_STUFE_A
#endif

/* R042: spell3_t1 / f_110200 - Hexenspeichel prueft verfuegbare AE gegen Heilungskosten (amount * 2) statt gegen Vorabwert -4 */
#ifndef FIX_R042
#define FIX_R042 FIX_STUFE_A_EXPLOIT
#endif
```

---

## 5. Live-Probenlog im Fix-Modus (`R_PLOG.H`)

In beiden fehlerbereinigten Fassungen (`FIX_BUGS >= 1`) bindet `Quelle/inc/R_FIX.H` automatisch `Quelle/inc/R_PLOG.H` ein. Damit schreibt das Spiel im Hintergrund jede Eigenschafts-, Talent-, Zauber- und Kampfprobe in `PROBEN.CSV`, ohne die Zufallsfolge oder das Spielstandsformat zu verändern.

Zum Anzeigen beim Spielen einfach über `RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat` / `RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat` (Windows) oder `./Linux/starten.sh wichtig --log` (Linux) starten. Siehe [`Probenlog/LIESMICH.md`](../Probenlog/LIESMICH.md).

---

## 6. Schalter-Übersicht

### Zusammenfassung

| Kategorie | Anzahl Schalter | Davon Exploits (`--exploits-lassen`) |
|---|---:|---:|
| **Stufe A** (`FIX_BUGS=1`, in `WICHTIG` und `ALLES`) | **31** | **2** (`FIX_R042`, `FIX_R043`) |
| **Stufe B** (`FIX_BUGS=2`, zusätzlich in `ALLES`) | **21** | **3** (`FIX_R025`, `FIX_R037`, `FIX_R041`) |
| **Gesamt** | **52** | **5** |

### Alle 52 Einzelschalter (`FIX_R001` – `FIX_R092`)

| Schalter | Stufe | Exploit | Einheit / Datei | Kurzbeschreibung |
|---|:---:|:---:|---|---|
| `FIX_R001` | A | nein | `gz_13bb70_t2` (`f_13d5d0`, `f_13d920`) | Vertauschte `memset`-Argumente `(0, 12)` statt `(12, 0)` vor DPMI-Interrupt `0x31` korrigiert (verhindert Startabstürze durch uninitialisierte Registerstruktur). |
| `FIX_R002` | A | nein | `uvesa` (`f_13efd0`), `gz_13bb70_t2` (`f_13d740`), `svga1_neu` (`f_11e760`) | VESA-Bankwechsel nutzt immer `WinASegment` (`s8`) passend zu Fenster A (`BL = 0`) statt `WinBSegment` (`sa`); redundantes doppeltes `memset` in `f_13d740` entfernt; Nullprüfung vor Scanline-Division. |
| `FIX_R003` | A | nein | `cdaudio_t1` (`CD::f_02ed35`) | Rückgabevariable `r = 0` initialisiert, damit `CD::f_02ed35` bei geschlossenem CD-Laufwerk keinen zufälligen Stackwert liefert. |
| `FIX_R004` | A | nein | `alloc_t1` (`f_014540`) | Nullsetzen im zentralen Heap-Allokator ab Nutzdatenbeginn (`(char *)blk + 4`) statt vor dem `"GUYS"`-Header; Slot-Überlauf (`i < 0`) vor `d_1bc614[i]` abfangen. |
| `FIX_R005` | A | nein | `alfdisk` (`AL::f_0137e0`, `AL::f_013a80`) | Maximale Modulpuffergröße `mx` über alle `ngrp` Archivmodule statt nur `s40` `.MOD`-Zeilen bestimmen; `c3e = -1` setzen, wenn `p7e` in `f_013a80` nicht neu geladen wird. |
| `FIX_R006` | A | nein | `ace_t1` (`Ace::f_010a90`, `Ace::f_0110f0`) | Animationszeiger `rec` nach Freigabe in `f_0110f0` auf `0` setzen (kein Dangling-Pointer/Double-Free) und Arraygrenzen `< 100` für `tab` prüfen. |
| `FIX_R007` | B | nein | `ace_t2a1` (`f_011730`) | Kapazitätsprüfung `p2->n < p2->cap` vor dem Anfügen eines neuen Eintrags im ACE-Variablenregister. |
| `FIX_R008` | A | nein | `import_saveload` (`f_160790`) | 3D-Texturhöhe `d->h = h` statt `w` setzen (behebt verzerrte nicht-quadratische 3D-Texturen) und Mipmap-Halbierung ab `shrink >= 3` für mehrphasige Texturen korrigieren. |
| `FIX_R009` | A | nein | `stock_neu` (`Stock::f_11c580`) | Nullzeiger-Schutz beim Entfernen des letzten verbleibenden Elements am Listenanfang (`if (head) head->prev = ...; else tail = 0;`). |
| `FIX_R010` | A | nein | `smith` (`f_10b0c0`) | Kennung und Waffenanzahl des ersten Schmieds vor der Dateileseschleife sichern, damit die EOF-Kennung `-1` beim Besuch des zweiten Schmieds nicht alle abgegebenen Waffen (inkl. *Schwert des Artherion*) löscht. |
| `FIX_R011` | A | nein | `poolconv` (`f_0e0400`) | Noch nicht fertiggestellte Schmied-Aufträge mit `continue` überspringen statt per `break` alle dahinter liegenden fertigen Waffen abzuschneiden; temporäres Array `tab` freigeben. |
| `FIX_R012` | A | nein | `gz_040280` (`f_041220`) | Nullzeiger-Prüfung `p1 ? f_0de7f0(p1) : 0` beim Abbruch der Gruppenteilungs-Auswahl. |
| `FIX_R013` | B | nein | `charact1` (`f_044890`), `ch_skill` (`f_03ac50`) | Copy-Paste-Ortsprüfung `d_1c2a80 == 0x30000 \|\| d_1c2a80 == 0x30001` statt doppeltem `0x30000` bei der LE-Regeneration und im Talentmenü. |
| `FIX_R014` | B | nein | `gz_028190` (`f_028190`, `f_0281d0`), `carrier` (`Car::f_027750`) | Untergrenze `s > 0` bzw. `i > 0` vor Zugriff auf `d_1a48f4` prüfen und Einmal-Flags `d_1bc81c` / `d_1bc81d` beim Burg-Reset zurücksetzen. |
| `FIX_R015` | A | nein | `import` (`f_0a2e30`) | Importierten *Stirnreif* (`0xd9`, MR +2) aus *Sternenschweif* auf Kopf-Slot `0` statt Brust-Slot `8` legen und doppelten `0xd7`-Vergleich entfernen. |
| `FIX_R016` | A | nein | `amap_t12` (`AMap::f_0156f0`) | Array-Unterlauf `sl[-1]` abfangen (`if (cur >= 0)`), wenn beim Öffnen der Automap keine Heldengruppe auf der angezeigten Karte steht. |
| `FIX_R017` | B | nein | `amap_t345` (`ContextAMap5::f_019fd0`) | Bestehende Automap-Notiz nicht überschreiben (`if (!found) r = -1;`), wenn alle 3×3 Nachbarfelder um einen Marker bereits belegt sind. |
| `FIX_R021` | A | nein | `gz_032ab0` (`f_032ab0`), `gz_0350b0_t1` (`f_0352c0`) | Giftladungen `n2 = n3` beim Stapeln vergifteter Projektile auf einen unvergifteten Stapel übernehmen; Pluralprüfung beim Gegenstandstausch auf `item_to` statt `item_from`. |
| `FIX_R025` | B | **ja** | `alchemy` (`f_012dd0`), `gz_0132a0` (`f_0133b0`) | Array-Unterlauf `work.tab[-1]` bei Abbruch der Rezeptauswahl verhindern, Rezept-Braudauer in Stunden statt Tagen (`/ 24`) gegen die verfügbare Restzeit prüfen und beim Scherzrezept `0x153` den letzten Helden nicht entfernen. |
| `FIX_R026` | A | nein | `gz_038ba0_t1` (`f_039cf0`) | Vorrangfehler `!(f_043600(p1, i) % 12)` statt `(!f_043600(p1, i)) % 12` korrigiert, damit abklingende Krankheiten wie *Dumpfschädel* nach der Windsbraut alle 12 Stunden KK/GE regenerieren und vollständig ausheilen. |
| `FIX_R027` | B | nein | `gz_1099f0_t1` (`f_109a50`) | Feilschen-Rabatt vor dem Eintrag in den Dialogtext auf 30 % deckeln und den 32-Bit-Rabattbetrag ohne `short`-Abschnitt zurückgeben. |
| `FIX_R028` | B | nein | `shop` (`f_1094e0`, `f_109800`), `gz_040280` (`f_040cb0`) | Negative Kauf-/Verkaufspreise nach dem Feilschen auf `0` begrenzen und den `+1`-Probenaufschlag bei 0 % Rabattforderung weglassen. |
| `FIX_R029` | B | nein | `ch_level_t1` (`Lv::f_037030`, `Lv::f_037140`) | Manuelle Zauber- und Talentsteigerungen ab Wert 18 sofort abweisen, ohne einen Steigerungsversuch zu verbrauchen (`3W6 > 18` ist unmöglich). |
| `FIX_R030` | B | nein | `fi_ini` (`f_077760`) | Attackewert (`2 * Heldenstufe`) der Spiegelbilder im Magierturm (`d_1bd920 == 2`) bei `18` deckeln. |
| `FIX_R033` | A | nein | `gz_13bb70_t1` (`f_13bc30`, `f_13cc50`) | Keine leere Glasflasche (`0x1f`) beim Benutzen von Gegenstand `0x17` erzeugen; Schaden von *Expurgicum* (`0xa6`) auf das Ziel (`q->f10`) statt auf den Anwender (`q->f14`) anwenden. |
| `FIX_R037` | B | **ja** | `shop` (`f_1094e0`) | Für gekaufte Waren, die wegen voller Inventare nicht verteilt werden konnten, den vollen gezahlten Kaufpreis statt des halbierten Wiederverkaufswerts erstatten. |
| `FIX_R038` | B | nein | `chest` (`f_047420`) | Beim Zurücklegen in Truhen nur stapelbare Gegenstände (`f_0a7950() != 0`) zusammenfassen, damit Einzelstücke ihre individuellen Zustands-/Ladungsdaten behalten. |
| `FIX_R039` | B | nein | `fi_g_tar_t1` (`f_074680`), `fi_g_tar_t2` (`X::f_074b40`) | Kampffeldgrenzen `0..23` für das Zweitfeld zweifeldgroßer Kampfeinheiten prüfen, bevor aus dem Brett-Array gelesen wird. |
| `FIX_R040` | A | nein | `fi_ac_co` (`f_06bdd0`, `f_06c380`, `f_06c930`) | Mindest-Schrittzahl `count >= 1` bei der Geschossflugbahn sichern (verhindert Puffer-Überlauf bei Nahdistanz) und Einheitenlimit `d_1bd924 < 20` bei Beschwörungen prüfen. |
| `FIX_R041` | B | **ja** | `spell` (`f_10ce80`), `gz_110d90` (`f_111930`), `gz_10d6b0_t1` (`f_10f910`) | Zauber mit variablen Kosten erfordern mindestens 1 AE; *Karnifilo* und Untoten-Zauber (`f_10f910`) prüfen die verfügbare AE vor dem Setzen der Zauberwirkung. |
| `FIX_R042` | A | **ja** | `spell3_t1` (`f_110200`) | *Hexenspeichel* vergleicht die verfügbare AE des Zaubernden gegen die Heilungskosten (`amount * 2`) statt gegen den noch auf `-4` stehenden Vorabwert. |
| `FIX_R043` | A | **ja** | `gz_110d90` (`f_111e00`) | *Armatrutz*-Auswahlmenü prüft `(s + 1) * (s + 1) > AE` vor dem Hochzählen, sodass keine unbezahlbare RS-Stufe mehr angeboten wird. |
| `FIX_R044` | A | nein | `gz_110d90` (`f_111a80`) | *Axxeleratus* bricht bei bereits aktivem Zauber sauber mit Kostenkennung `-4` statt `0` ab. |
| `FIX_R045` | A | nein | `gz_112590` (`f_1127e0`) | Auswahlvariable `choice = 0` initialisieren und Zauber sauber mit `-4` abbrechen, wenn weder Gegenstand `0x41` noch `0x19` im Inventar vorhanden ist. |
| `FIX_R047` | B | nein | `spell3_t1` (`f_10fc90`) | *Transversalis* setzt an verbotenen Orten die Abbruchkennung `-4` statt `0`, damit nach der Ortswarnung keine zweite Fehlermeldung folgt. |
| `FIX_R049` | A | nein | `gz_10d6b0_t1` (`f_10dce0`) | *Destructibo* berechnet und prüft die benötigte AE (`5W10 + Permanenz`) **vor** dem Löschen des Gegenstands, damit das Objekt bei AE-Mangel nicht verloren geht. |
| `FIX_R051` | B | nein | `tower1_t2` (`f_12ba70`) | Nach dem Hebelkampf im Magierturm die am Gegenhebel wartende zweite Teilgruppe automatisch mit der Hauptgruppe auf Ebene 20 wiedervereinigen. |
| `FIX_R052` | A | nein | `mine1_t1` (`f_0c0e30`, `Z832_c192`) | Rückgabewert `r = 1` in `f_0c0e30` initialisieren und bei der Lorenfahrt in der Zwergenbinge (`Z832_c192`) auf den Gruppenanführer zurückgreifen, falls alle Helden die GE+8-Probe bestehen, damit Kampf und Schrankenöffnung nicht übersprungen werden. |
| `FIX_R053` | B | nein | `char_opt` (`f_03f890`) | Nach dem Entlassen eines NPCs (`f_0d64a0`) das NPC-Präsenzflag `a` innerhalb der Entlassungsschleife aktualisieren. |
| `FIX_R054` | A | nein | `gz_0c9940_t2` (`f_0cab30`) | Vertauschte *Sinnesschärfe*-Bedingung (`b == 1` statt `!b`) korrigiert, damit der Warnhinweis bei bestandener statt bei misslungener Probe erscheint. |
| `FIX_R055` | A | nein | `street` (`f_11e500`), `gz_11caf0_t12` (`Context11CA493::f_11e350`, `f_11e380`) | Schleife über die Straßenbegegnungen in Riva von `1..20` statt `0..19` führen, damit die 20. Begegnung nicht übersprungen wird. |
| `FIX_R056` | A | nein | `castle_t3` (`f_02c9a0`, `f_02d230`) | Seil-/Hebel-Statusflag `d_1bc82c` im `else`-Zweig auf `0` statt `1` setzen und Index `-1` vor dem Tabellenzugriff `d_1a06a8[idx]` in `f_02d230` abfangen. |
| `FIX_R058` | A | nein | `ship_t1` (`f_0fbd80`) | Zufallsobergrenze `p4` in der Heldenschleife nicht beim ersten Durchlauf mit dem gewürfelten Zufallswert überschreiben. |
| `FIX_R059` | B | nein | `final2` (`f_08e320`, `f_08fcc0`) | Einmal-Trigger-Flag `d_1bdb74 = 1` beim Auslösen von Ereignisfeld `0x385` im Enddungeon setzen. |
| `FIX_R068` | A | nein | `tower3_t2` (`f_130fd0`) | Endlosschleife an den Gangfallen im Magierturm verhindern, wenn außer dem Anführer kein zweiter handlungsfähiger Held in der Gruppe bei Bewusstsein ist. |
| `FIX_R071` | B | nein | `gz_08cb00` (`f_08cd20`), `gz_08dae0_rand910a` (`f_08dae0`) | Vorratszähler `d_1bdb20` bei Ereignis `0x322` **vor** der Nullprüfung dekrementieren, damit das Folge-Flag `0x1f41` beim Aufbrauchen des Vorrats gesetzt wird. |
| `FIX_R072` | A | nein | `gz_126c40` (`f_126f80`) | Kalender-Tagesüberlauf (`p1->b -= 30` statt `30 - p1->b`) und Monatsüberlauf (`p1->c -= 12` statt `-= 1`) bei Zeitaddition korrigieren. |
| `FIX_R074` | B | nein | `dialog_t1` (`f_055650`) | In den Dialogzweigen `case 42` und `case 43` das Nachbar-Flag `d_1bc78c` statt des aus `case 40`/`41` kopierten Flags `d_1bc788` prüfen. |
| `FIX_R076` | B | nein | `gz_0f25c0_t1` (`f_0f2de0`), `sewerag1_neu` (`f_0f5110`) | Flut-Trigger `d_1c01a0 = 1` nach dem Öffnen von Truhe `0x489` in der Kanalisation unbedingt setzen und bei Gegenstandsentnahme `res = 1` zurückgeben. |
| `FIX_R077` | B | nein | `gz_0dc9a0_ta` (`f_0dc9a0`) | Beim Nachrücken freier Gruppenplätze `memmove` statt überlappendem `memcpy` verwenden und aufeinanderfolgende Lücken (`i--`) vollständig aufräumen. |
| `FIX_R084` | A | nein | `diary` (`f_057a00`) | Stichwort-Kennung in Tagebucheinträgen als `unsigned char` (`0..255`) statt `signed char` lesen, damit Einträge ab ID 128 im Tagebuch gefunden werden. |
| `FIX_R092` | A | nein | `lang_cze` (`f_0abc00`, `f_0abc30`) | Absturzträchtigen Nullzeiger-Aufruf `strcat(p2, (char *)0)` bei der Textformatierung entfernen. |

> **Warum fehlen manche R-Nummern zwischen `R001` und `R114`?**
> Insgesamt wurden 115 Fehlerkandidaten (`R001`–`R114`) aus Community-Foren, Patch-Notes und der Katalog-Analyse gegen den rekonstruierten C++-Quelltext von Version 1.12 geprüft. **63 Kandidaten** erwiesen sich als im Code von V1.12 bereits durch Attic behoben (z. B. Windsbraut-Etagenwechsel, Automove-Steuerung, Gilde-Hintereingang), als beabsichtigte DSA-3-Regel (z. B. *Transversalis* nur auf selbst betretenen Feldern), als reine Kartendaten in `RIVA.ALF` (z. B. unpassierbares Regal in der Zwergenbinge) oder als Fehlalarm der statischen Vorab-Analyse. Eine ausführliche Erläuterung für Spieler steht in [`BUGFIXES.md`](../BUGFIXES.md).
