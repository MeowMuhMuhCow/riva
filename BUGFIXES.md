# Schatten über Riva — Bugfix-Edition (`RIVA_FIX`)

**Version 1.0 vom 16.11.2026** · inoffizielle **Testversion** · zur deutschen GOG-Fassung V1.12 (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) · **bisher nur Programmstart geprüft – Tester herzlich willkommen!**

> **Wichtiger Hinweis (TESTVERSION – Tester gesucht!):**  
> Alle **52 Fehlerbehebungen** (`31` in Stufe A, `21` zusätzlich in Stufe B) wurden direkt am vollständig bytegleich rekonstruierten C++-Quelltext von Version 1.12 entworfen und statisch geprüft; im Emulator wurde bisher aber **nur der Programmstart getestet**.  
> **Bitte an alle Tester:** Spielt mit `RIVA_FIX_WICHTIG.EXE` oder `RIVA_FIX_ALLES.EXE`, nutzt gerne das **Live-Probenlog** (`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat` bzw. `./Linux/starten.sh wichtig --log`) und meldet Fehler oder ungewöhnliches Verhalten mit Angabe der verwendeten EXE-Fassung, der `R`-Nummer aus dieser Liste und gerne einem Spielstand (`.GAM`)! Jeder der 52 Fixes besitzt einen eigenen Schalter (`FIX_R001` … `FIX_R092`) und lässt sich einzeln ein- oder ausschalten.

**Schatten über Riva** erschien Ende 1996 bei Attic und erhielt 1997 mit dem offiziellen **Patch V1.12** sein letztes Update. Damit wurden zwar etliche Kinderkrankheiten der Erstausgabe behoben, doch viele tieferliegende Programmierfehler im C++-Code blieben über fast 30 Jahre bestehen — darunter verschwundene Waffen beim Schmied (samt *Schwert des Artherion*), ein nach der *Windsbraut* nie mehr abklingender *Dumpfschädel*, beim *Sternenschweif*-Import falsch angelegte magische Stirnreife, verlorene Gegenstände beim *Destructibo*, eine feststeckende Lorenfahrt in der Zwergenbinge und Zauber, die trotz leerer Astralenergie wirken.

Durch die vollständige, bytegleiche Rekonstruktion des Original-Quelltextes konnten wir sämtliche aus den **Crystals-DSA-Foren**, der **DSA-Wiki** und der systematischen Code-Analyse bekannten Fehler direkt im C++-Quelltext von Version 1.12 untersuchen und gezielt beheben.

---

## So geht's

Nötig: Windows (oder Linux mit `python3` + `dosbox`) und **„Realms of Arkania 3 - Shadows over Riva" von GOG** (deutsche Fassung V1.12). Kein Compiler nötig.

| Schritt | Aktion |
|---:|---|
| **1** | Das Bugfix-Paket herunterladen (bei GitHub unter **Releases** als `riva_Bugfix_1.0.zip`, oder **Code → Download ZIP**) und irgendwohin entpacken |
| **2** | **`PATCHEN.bat`** doppelklicken (Linux: `./Linux/patchen.sh`). Es findet den GOG-Ordner automatisch (oder fragt danach), prüft deine `RIVA.EXE` (`2.477.899` Bytes, MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) per Prüfsumme und erzeugt aus den kompakten Patches (`RIVA_FIX_WICHTIG.ndp` 149 KB, `RIVA_FIX_ALLES.ndp` 164 KB) beide Bugfix-EXEs (je `2.507.083` Bytes). **Das Original wird nicht verändert** |
| **3** | **`RIVA_FIX_WICHTIG_STARTEN.bat`** (empfohlen, 31 Fixes) oder **`RIVA_FIX_ALLES_STARTEN.bat`** (alle 52 Fixes) doppelklicken — oder mit **Live-Probenlog**: **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`** (Linux: `./Linux/starten.sh wichtig` bzw. `./Linux/starten.sh wichtig --log`) |

---

## 1. Übersicht: Drei Fassungen zur Auswahl

Damit sowohl Puristen als auch Spieler, die sich ein fehlerfreies Abenteuer wünschen, genau ihre bevorzugte Version spielen können, gibt es drei Fassungen:

| Fassung | Datei (`Größe` / `MD5`) | Inhalt | Anzahl Fixes |
|---|---|---|---:|
| **Original 1997 (V1.12)** | `RIVA.EXE`<br>(`2.477.899` B · MD5 `fb8f5fc3ba5454c7344c17aaf362de35`) | **100 % bytegleich** zur letzten offiziellen CD-/Patch-Version 1.12 von 1997 — inklusive aller historischen Bugs. | **0** |
| **WICHTIG (Stufe A)**<br>*(Testversion)* | `RIVA_FIX_WICHTIG.EXE`<br>(`2.507.083` B · MD5 `8e1fb73fcf6cad374aa6d4076f13a64d` · Patch `149 KB`) | Behebt **Abstürze, Hänger, Datenverlust und kaputte Spielmechanik** (Schmied-Waffenverlust, unheilbarer Dumpfschädel, Lorenfahrt, Magierturm-Endlosschleife, Zauber-/Inventarfehler, VESA/DPMI/3D-Engine). **Empfohlen für das klassische Spielgefühl ohne Frust.** | **31** *(davon 2 Exploits: `R042`, `R043`)* |
| **ALLES (Stufe A + B)**<br>*(Testversion)* | `RIVA_FIX_ALLES.EXE`<br>(`2.507.083` B · MD5 `d8dba0e2ecb2ced9b380ea708b8be25f` · Patch `164 KB`) | Enthält alle Korrekturen aus `WICHTIG` **plus 21 weitere Detail-, Anzeige-, Feilschen-, Alchemie- und Randfall-Fixes**. **Empfohlen für das rundum gepflegte Spielerlebnis.** | **52** *(31 A + 21 B, davon 5 Exploits)* |

### Spielstände & Kompatibilität
Alle drei Programmdateien (`RIVA.EXE`, `RIVA_FIX_WICHTIG.EXE`, `RIVA_FIX_ALLES.EXE`) verwenden exakt dasselbe Spielstandsformat (`.GAM`). Du kannst jederzeit zwischen der Original-EXE und den Bugfix-Versionen wechseln, ohne neu anfangen zu müssen.

> **Hinweis zu bereits eingetretenen Datenverlusten:** Wenn eine Waffe beim Schmied bereits im Spielstand durch den Original-Bug überschrieben wurde (`R010`), kann sie aus diesem Spielstand nicht rückwirkend wiederhergestellt werden — lade in diesem Fall einen Spielstand vor dem Besuch des zweiten Schmieds. Ein bereits bestehender *Dumpfschädel* (`R026`) heilt nach dem Wechsel auf die Bugfix-EXE dagegen automatisch im 12-Stunden-Takt weiter aus!

### Klassische Spielervorteile behalten (`--exploits-lassen`)
Unter den **52 Korrekturen** befinden sich **5 Fehler, die im Originalspiel von 1997 einen Vorteil für den Spieler darstellten** (in den Listen unten mit **💰 Exploit** gekennzeichnet):
- **Stufe A (2 Exploits):** `R042` (*Hexenspeichel* heilt ohne ausreichende AE), `R043` (*Armatrutz* bietet 1 Punkt mehr RS an, als die AE erlaubt)
- **Stufe B (3 Exploits):** `R025` (Alchemie-Rezepte über 8 Stunden Dauer lassen sich ohne ausreichende Restzeit brauen), `R037` (im Laden mit vollem Inventar abgelehnte Waren zum Trick-Tauschen nutzen), `R041` (*Karnifilo*, *Skelettarius* und Zauber mit variablen Kosten prüfen die AE unvollständig)

Wer mit allen Absturz- und Logik-Fixes spielen, aber auf diese 5 klassischen Tricks nicht verzichten möchte, baut die EXE einfach mit dem Zusatzschalter `--exploits-lassen`:

```bat
Bauen\BAUEN.bat wichtig --exploits-lassen
Bauen\BAUEN.bat alles   --exploits-lassen
```

*(bzw. unter Linux/WSL: `python3 Bauen/bauen.py wichtig --exploits-lassen` oder `python3 Bauen/bauen.py alles --exploits-lassen`)*

Wie sich auch einzelne Schalter (`FIX_R001` … `FIX_R092`) gezielt ein- oder ausschalten lassen, ist in [`Bauen/FIXES.md`](Bauen/FIXES.md) beschrieben.

---

### Die berühmtesten behobenen Forums-Bugs auf einen Blick

Bevor alle **52 Korrekturen** einzeln aufgeführt werden, hier die bekanntesten Klassiker aus fast 25 Jahren Forendiskussionen:

- **⚔️ Verschwundene Waffen beim Schmied & *Schwert des Artherion* (`R010`, `R011`, `R009` — Stufe A):** Gibt man bei einem Schmied Waffen in Auftrag (oder lässt das zerbrochene *Schwert des Artherion* schmieden) und besucht anschließend den *anderen* Schmied in Riva, überschreibt das Originalspiel die Schmied-Kennung des ersten Schmieds mit `-1` — alle dort abgegebenen Waffen sind für immer verschwunden (`R010`). Zudem bricht die Abholprüfung beim ersten noch nicht fertigen Auftrag komplett ab, sodass bereits fertige Waffen dahinter nicht ausgehändigt werden (`R011`), und beim Entnehmen des letzten Gegenstands aus einer Bestandsliste droht ein Nullzeiger-Absturz (`R009`).
- **🤒 Unheilbarer *Dumpfschädel* nach der *Windsbraut* (`R026` — Stufe A):** Nach dem Ausbruch von *Dumpfschädel* auf dem Piratenschiff klingen die Symptome zwar ab, aber die abgezogenen Körperkraft- und Gewandtheitspunkte kehren im Originalspiel nie zurück und der Held gilt dauerhaft als krank. Grund war ein einziger Klammerfehler im C++-Code (`(!stunden) % 12` statt `!(stunden % 12)`), durch den die 12-Stunden-Nachheilung niemals ausgelöst wurde.
- **👑 *Sternenschweif*-Import legt den *Stirnreif* (MR +2) auf die Brust statt auf den Kopf (`R015` — Stufe A):** Beim Import einer Heldengruppe aus *Sternenschweif* legt die Konvertierungsroutine den blauen *Stirnreif* (`0xd9`, Magieresistenz +2) versehentlich auf den Brust-Slot (`8`) statt auf den Kopf-Slot (`0`), prüft aber eine Zeile tiefer auf dem Kopf-Slot, ob der Bonus aktiviert werden soll.
- **✨ Magie-Pannen bei *Destructibo*, *Hexenspeichel*, *Armatrutz*, *Karnifilo* & *Axxeleratus* (`R041`–`R045`, `R049` — Stufe A/B):** Beim Entzaubern mit *Destructibo* zerstört das Originalspiel zuerst den Gegenstand und prüft erst danach, ob der Magier überhaupt genug Astralenergie (`5W10 + Permanenz`) besitzt (`R049`). Umgekehrt ließ sich mit *Hexenspeichel* (`R042`), *Armatrutz* (`R043`) und *Karnifilo* (`R041`) zaubern, obwohl die AE nicht ausreichte.
- **🛒 Feilschen, Preisüberlauf & Rückerstattung im Laden (`R027`, `R028`, `R037` — Stufe B):** Beim Feilschen verspricht der Händler im Dialogtext mehr als 30 % Rabatt, zieht aber intern nur 30 % ab (`R027`), fordert selbst bei 0 % Rabatt einen zusätzlichen Erschwernispunkt (`R028`) und erstattet für gekaufte Waren, die wegen voller Rucksäcke nicht verteilt werden können, nur den halben Wiederverkaufswert statt des gerade gezahlten Kaufpreises (`R037`).
- **📈 Verlorene Steigerungsversuche ab Talent-/Zauberwert 18 (`R029` — Stufe B):** Da beim Steigern mit `3W6` maximal eine 18 gewürfelt werden kann, ist eine manuelle Steigerung über 18 hinaus unmöglich — das Originalspiel lässt den Versuch trotzdem zu und zieht einen kostbaren Steigerungsversuch ab.
- **🪞 Übermächtige Spiegelbilder & vergessene Teilgruppe im Magierturm (`R030`, `R051` — Stufe B):** Im Spiegelkampf des Magierturms wird der Attackewert der Doppelgänger (`2 × Heldenstufe`) nicht bei 18 gedeckelt (`R030`), und nach dem Sieg im Hebelkampf wird die am Gegenhebel zurückgelassene Teilgruppe nicht automatisch mit auf Ebene 20 teleportiert (`R051`).
- **⛏️ Feststeckende Lorenfahrt in der Zwergenbinge (`R052` — Stufe A):** Bestehen bei der Lorenfahrt alle Helden die erschwerte Gewandtheitsprobe (`GE + 8`), hat die Auswertungsfunktion kein Ziel für den Sturzschaden und überspringt versehentlich auch den nachfolgenden Kampf sowie das Öffnen der Schranke.

---

## 2. Behobene Fehler in `RIVA_FIX_WICHTIG.EXE` (Stufe A — 31 Fixes)

Stufe A umfasst alle Korrekturen gegen Programmabstürze, Speicherfehler, verlorene Gegenstände und blockierte Quests oder Spielmechaniken.

---

### R001 — Absturz beim Programmstart durch uninitialisierte DPMI-Registerstruktur
- **Was im Spiel passiert:** Beim Starten des Spiels oder beim Umschalten des Grafik-/Speichermodus unter DOS/DPMI kann das Spiel mit einem Schutzverletzungsfehler abstürzen, weil der DPMI-Interrupt `0x31` mit zufälligen Müllwerten auf dem Stack aufgerufen wird.
- **Ursache im Code:** Vor dem Aufruf von `int386x(0x31, ...)` in `gz_13bb70_t2` (`f_13d5d0` und `f_13d920`) wurden beim Nullsetzen der 12-Byte-Registerstruktur `d_1c109c` die Parameter für Füllwert und Länge in `memset(&d_1c109c, 12, 0)` vertauscht, sodass 0 Bytes gelöscht wurden.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** Offizieller Patch 1.12 Punkt 1 („Abstürze beim Starten beseitigt“ — im Code von V1.12 war der vertauschte `memset`-Aufruf dennoch verblieben); siehe [Crystals-DSA-Foren: Patch-Historie / Bekannte Bugs](https://www.crystals-dsa-foren.de/showthread.php?tid=322).

---

### R002 — Grafikfehler oder schwarzer Bildschirm auf VESA-Karten mit zwei Speicherfenstern
- **Was im Spiel passiert:** Auf SVGA-/VESA-Grafikkarten, die neben dem primären Speicherfenster A (`WinASegment`) auch ein zweites Fenster B (`WinBSegment`) unterstützen, greift die Bildschirmausgabe ins Leere oder zeigt Bildstörungen; schlägt zudem die VESA-ModeInfo-Abfrage fehl, teilt die Bank-Initialisierung durch Null.
- **Ursache im Code:** In `uvesa` (`f_13efd0`) schaltet der Bankwechsel (`Bank907::set`) stets das VESA-Fenster A (`BL = 0`) um, während die Zieladresse bei gesetztem Statusbit 1 fälschlich über das Segment von Fenster B (`d_1c1108->sa << 4` statt `s8 << 4`) berechnet wurde; zusätzlich stand in `gz_13bb70_t2` (`f_13d740`) ein redundanter doppelter `memset`-Aufruf vor der VESA-Abfrage, und in `svga1_neu` (`f_11e760`) fehlte vor der Division `step = d / f_13e680()` die Prüfung auf `r != 0`, `d_1c1108 != 0` und `f_13e680() != 0`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** Offizieller Patch 1.12 Punkt 2 („Probleme mit diversen VESA-Treibern beseitigt“).

---

### R003 — Zufälliges Verhalten der CD-Audio-Abfrage ohne geöffnetes CD-Laufwerk
- **Was im Spiel passiert:** Ist kein CD-Laufwerk geöffnet oder wird ohne eingelegte Musik-CD gespielt, kann die Statusabfrage der CD-Musik zufällige Werte liefern und unnötige Treiberbefehle auslösen.
- **Ursache im Code:** In `cdaudio_t1` (`CD::f_02ed35`) war die lokale Rückgabevariable `int r` nicht initialisiert und wurde bei `open == 0` unbeschrieben vom Stack zurückgegeben.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** Offizieller Patch 1.12 Punkt 3 („Probleme mit diversen CD-ROM-Treibern beseitigt“).

---

### R004 — Uninitialisierte letzte 4 Nutzdatenbytes und Tabellen-Unterlauf in der Heap-Speicherverwaltung
- **Was im Spiel passiert:** Bei jeder Speicheranforderung über den zentralen Heap-Allokator bleiben die letzten 4 Bytes des angeforderten Speicherblocks uninitialisiert (statt wie beabsichtigt genullt); sind außerdem alle 2.500 Tracking-Slots belegt, schreibt die Verwaltung vor den Anfang der Überwachungstabelle `d_1bc614`.
- **Ursache im Code:** In `alloc_t1` (`f_014540`) rief die Funktion `memset(blk, 0, size)` auf die Blockstartadresse `blk` (in die direkt danach die 4-Byte-Wächtermarke `"GUYS"` geschrieben wird) statt auf den Nutzdatenbeginn `(char *)blk + 4` auf, und verwendete den Rückgabewert `i = slot()` ohne Prüfung auf `i >= 0` als Index `d_1bc614 + i`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R005 — Zu kleiner Lesepuffer und veralteter Index beim Laden aus `.ALF`-Archiven
- **Was im Spiel passiert:** Beim Nachladen großer Datenblöcke aus den Archivdateien (`RIVA.ALF` / `DATA.ALF`) kann ein zu klein bemessener Puffer überlaufen oder ein veralteter Gruppenindex im Cache stehen bleiben.
- **Ursache im Code:** In `alfdisk` (`AL::f_0137e0`) lief die Schleife zur Bestimmung der maximalen Modulgröße `mx` über die Anzahl der `.MOD`-Zeilen (`s40`) statt über alle Archivmodule (`ngrp`), und in `AL::f_013a80` wurde der aktive Modulindex `c3e` aktualisiert, obwohl der zugehörige Puffer `p7e` dort gar nicht neu geladen wird.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R006 — Absturz durch Dangling-Pointer und Array-Überlauf in der ACE-Animations-Engine
- **Was im Spiel passiert:** Schlägt das Laden einer `.ACE`-Animation fehl oder enthält eine Animationssequenz ungewöhnlich viele Einträge, kann das Spiel beim Aufräumen mit einem Speicherfehler abstürzen.
- **Ursache im Code:** In `ace_t1` (`Ace::f_0110f0`) wurde der Zeiger `rec` nach `delete rec` im Fehlerpfad nicht auf `0` gesetzt und deshalb zurückgegeben, und in `Ace::f_010a90` sowie `f_0110f0` fehlte vor dem Schreiben in das 100-Elemente-Array `tab` die Obergrenzenprüfung `< 100`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R008 — Verzerrte nicht-quadratische 3D-Texturen und fehlerhafte Mipmap-Verkleinerung
- **Was im Spiel passiert:** Rechteckige (nicht-quadratische) Texturen in der 3D-Ansicht von Stadt und Dungeons werden gestaucht oder abgeschnitten dargestellt, und bei starker Texturverkleinerung (ab Stufe 3) geraten die Folgebilder animierter Texturen durcheinander.
- **Ursache im Code:** In `import_saveload` (`f_160790`) wurde beim Anlegen der 3D-Textur versehentlich die Breite in die Höhe kopiert (`d->h = d->w = w` statt `d->h = h`), und im `default`-Zweig für Verkleinerungsstufen ab 3 wurde der Schleifenzähler `shrink` direkt heruntergezählt (sodass er für weitere Animationsphasen auf `0` stand) und einmal zu oft halbiert.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R009 — Absturz beim Entnehmen des letzten Gegenstands aus einer Bestandsliste
- **Was im Spiel passiert:** Wird beim Händler, Schmied oder in einem Warenlager der allerletzte verbleibende Gegenstand aus der Bestandsliste entnommen, greift das Spiel auf einen Nullzeiger zu (unter DOS wird dabei in Adresse `0x00000004` geschrieben).
- **Ursache im Code:** Beim Aushängen des ersten Listenelements (`i == 0`) in `stock_neu` (`Stock::f_11c580`) setzte die Funktion `head->prev = n->prev`, ohne zuvor zu prüfen, ob `head` nach dem Entfernen des einzigen Elements `0` geworden ist (in diesem Fall muss stattdessen `tail = 0` gesetzt werden).
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Schmied / Warenlager](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=11319#pid11319)

---

### R010 — Alle abgegebenen Waffen beim ersten Schmied verschwinden beim Besuch des zweiten Schmieds (*Schwert des Artherion*!)
- **Was im Spiel passiert:** Gibt man bei einem der beiden Schmiede in Riva Waffen zur Reparatur ab (oder lässt dort das legendäre *Schwert des Artherion* schmieden) und spricht später den **anderen** Schmied an, sind sämtliche beim ersten Schmied hinterlegten Waffen spurlos und unwiederbringlich verschwunden.
- **Ursache im Code:** Beim Öffnen des Schmied-Menüs liest `smith` (`f_10b0c0`) die temporäre Datei `0x401a0002` in einer Schleife bis zum Dateiende ein, wobei die Dateiende-Prüfung die gerade gelesene Schmied-Kennung `x` des anderen Schmieds mit `-1` überschreibt und anschließend diesen Wert `-1` statt der echten Schmied-ID wieder in die Datei zurückschreibt.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Schmied verschluckt Waffen / Schwert des Artherion](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=11302#pid11302)

---

### R011 — Fertige Waffen beim Schmied werden nicht ausgehändigt, solange ein früherer Auftrag noch dauert
- **Was im Spiel passiert:** Hat man beim selben Schmied mehrere Waffen hintereinander abgegeben und ist ein weiter vorn in der Liste stehender Auftrag noch nicht fertig, händigt der Schmied auch alle dahinter stehenden, längst fertiggestellten Waffen nicht aus.
- **Ursache im Code:** In `poolconv` (`f_0e0400`) brach die Schleife über das Auftragsarray beim ersten noch nicht abgelaufenen Zeittimer mit `break` komplett ab, statt diesen Auftrag mit `continue` zu überspringen und die restlichen Einträge weiterzuprüfen; außerdem wurde das temporäre Übergabearray `tab` am Funktionsende nicht freigegeben.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Schmied rückt Waffen nicht heraus](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=11319#pid11319)

---

### R012 — Absturz beim Abbrechen der Gruppenteilung
- **Was im Spiel passiert:** Wählt man das Teilen der Heldengruppe an, bricht die Auswahl der abzuspaltenen Helden jedoch ohne Ergebnis ab, kann das Spiel sofort abstürzen.
- **Ursache im Code:** In `gz_040280` (`f_041220`) wurde der Rückgabezeiger `p1` der Gruppenauswahl ohne Nullzeiger-Prüfung direkt an `f_0de7f0(p1)` übergeben, obwohl `p1` bei Abbruch `0` ist.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R015 — Importierter *Stirnreif* (MR +2) aus *Sternenschweif* landet auf dem Brust-Slot statt auf dem Kopf
- **Was im Spiel passiert:** Importiert man eine Heldengruppe aus *Sternenschweif*, die den blauen magischen *Stirnreif* (Gegenstand `0xd9`, Magieresistenz +2) trägt, liegt der Stirnreif nach dem Import auf dem Brust-/Hals-Slot statt auf dem Kopf-Slot und verleiht beim Import keinen MR-Bonus.
- **Ursache im Code:** In `import` (`f_0a2e30`) verschob die Slot-Konvertierung den *Stirnreif* (`0xd9`) versehentlich auf Slot `8` (Brust) statt auf Slot `0` (Kopf), während die direkt nachfolgende Bonus-Prüfung auf Slot `0` nachsah, ob dort `0xd9` liegt; zudem war `0xd7` in der Bedingung doppelt eingetragen.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Stirnreif / Import aus Sternenschweif](https://www.crystals-dsa-foren.de/showthread.php?tid=50)

---

### R016 — Speicherzugriffsfehler beim Öffnen der Automap ohne Gruppe auf der aktuellen Karte
- **Was im Spiel passiert:** Wird die Automap für eine Karte aufgerufen, auf der sich gerade keine aktive Heldengruppe befindet, liest das Spiel vor dem Anfang des Gruppen-Arrays aus fremdem Speicher.
- **Ursache im Code:** In `amap_t12` (`AMap::f_0156f0`) blieb der Suchindex `cur` bei `-1`, wenn keine Gruppe auf der Karte `id` stand, und wurde anschließend ungeprüft als Array-Index `sl[cur]` (`sl[-1]`) verwendet.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R021 — Verlorene Giftladungen beim Stapeln von Projektilen & falsche Pluralform beim Gegenstandstausch
- **Was im Spiel passiert:** Legt man im Inventar vergiftete Pfeile, Bolzen oder Wurfwaffen auf einen noch unvergifteten Stapel gleichen Typs (Gesamtmenge ≤ 99), erhält der kombinierte Stapel zwar die Giftmarkierung, aber `0` Giftladungen (das Gift ist sofort wirkungslos); außerdem prüft die Fehlermeldung beim unzulässigen Tausch zweier Gegenstände die Stapelbarkeit des falschen Gegenstands.
- **Ursache im Code:** In `gz_032ab0` (`f_032ab0`, Z. 254) fehlte beim Zusammenführen ohne 99er-Überlauf nach `if (kind3 == kind2) n2 += n3;` der `else`-Zweig `else n2 = n3;` (der im Überlaufzweig wenige Zeilen darüber vorhanden war), und in `gz_0350b0_t1` (`f_0352c0`, Z. 328) stand durch Copy-Paste `d_1c2c40[item_from]->f_0a7950()` statt `d_1c2c40[item_to]->f_0a7950()`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R026 — Unheilbarer *Dumpfschädel* nach der *Windsbraut* (Körperkraft und Gewandtheit kehren nie zurück)
- **Was im Spiel passiert:** Auf dem Piratenschiff *Windsbraut* erkranken die Helden häufig an *Dumpfschädel* (Körperkraft −2, Gewandtheit −2). Selbst wenn die Krankheit später geheilt wird oder von selbst in die Abklingphase wechselt, steigen die verlorenen Attributspunkte nie wieder an und der Status „krank“ verschwindet das ganze restliche Spiel über nicht mehr.
- **Ursache im Code:** In der stündlichen Krankheits-Routine `gz_038ba0_t1` (`f_039cf0`) fehlten bei der Prüfung, ob volle 12 Stunden vergangen sind, die Klammern um die Modulo-Rechnung: `(!f_043600(p1, i)) % 12 != 0` negierte zuerst die Stundenzahl zu `0` (für jede Krankheitsdauer `> 0`), sodass `0 % 12` immer `0` ergab und der 12-Stunden-Regenerationszweig niemals betreten wurde.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Dumpfschädel auf der Windsbraut heilt nie](https://www.crystals-dsa-foren.de/showthread.php?tid=204)

---

### R033 — *Expurgicum* schädigt den Anwender statt des Ziels und Gegenstand `0x17` hinterlässt eine Glasflasche
- **Was im Spiel passiert:** Wird das alchemistische Mittel *Expurgicum* (`0xa6`) angewendet, zieht das Spiel den Schaden vom benutzenden Helden statt vom ausgewählten Ziel ab; außerdem entsteht beim Benutzen von Gegenstand `0x17` fälschlich eine leere Glasflasche (`0x1f`) im Inventar.
- **Ursache im Code:** In `gz_13bb70_t1` (`f_13cc50`) wurde für *Expurgicum* der Schadensaufruf `f_044890` versehentlich auf den Anwenderzeiger `q->f14` statt auf den Zielzeiger `q->f10` ausgeführt, und in `f_13bc30` war Gegenstand `0x17` in die Liste der Tränke eingetragen, die beim Verbrauch eine leere Flasche (`0x1f`) erzeugen.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R040 — Absturz bei Geschossen auf kürzeste Distanz und Überlauf bei mehr als 20 Kampfeinheiten
- **Was im Spiel passiert:** Feuert eine Kampfeinheit im Rundenkampf ein Geschoss oder einen Zauber auf ein unmittelbar benachbartes Feld ab oder werden durch Beschwörungen mehr als 20 Einheiten gleichzeitig erzeugt, kann das Spiel abstürzen oder Speicher überschreiben.
- **Ursache im Code:** In `fi_ac_co` (`f_06bdd0` und `f_06c380`) ergab die ganzzahlige Division `count = n / 10` bei sehr kurzer Flugbahn `0`, worauf ein Puffer der Größe `0` reserviert, aber trotzdem im ersten Schritt beschrieben wurde; in `f_06c930` fehlte vor dem Eintragen einer neuen Kampfeinheit die Prüfung auf das Array-Maximum `d_1bd924 < 20`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R042 — *Hexenspeichel* heilt auch ohne ausreichende Astralenergie 💰 Exploit
- **Was im Spiel passiert:** Beim Zauber *Hexenspeichel* kann der Spieler beliebig viele Lebenspunkte heilen, selbst wenn der Zaubernde fast keine Astralenergie mehr übrig hat (die AE fällt anschließend auf 0, die volle Heilung wird aber trotzdem gewährt).
- **Ursache im Code:** In `spell3_t1` (`f_110200`) verglich die AE-Prüfung die verfügbare Astralenergie des Zaubernden versehentlich mit dem noch auf `-4` stehenden Kostenslot `W(p1, 0)` statt mit den tatsächlichen Heilungskosten `amount * 2`, bevor diese in `W(p1, 0)` eingetragen wurden.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** **Ja 💰** *(mit `--exploits-lassen` abschaltbar)*
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Zaubern ohne genug AE](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=6835#pid6835)

---

### R043 — *Armatrutz* bietet im Auswahlmenü 1 Punkt mehr Rüstungsschutz an, als die AE bezahlen kann 💰 Exploit
- **Was im Spiel passiert:** Beim Zauber *Armatrutz* (Kosten: `RS²` Astralpunkte) erlaubt das Auswahlmenü stets eine Stufe Rüstungsschutz mehr, als der Magier mit seiner aktuellen Astralenergie eigentlich bezahlen kann (z. B. RS +4 für 16 AE bei nur 10 vorhandener AE).
- **Ursache im Code:** In `gz_110d90` (`f_111e00`) prüfte die Schleife zur Ermittlung des maximal wählbaren RS-Bonus `s * s > AE` erst **nachdem** `s` im vorherigen Durchlauf bereits erhöht worden war, statt vorab `(s + 1) * (s + 1) > AE` zu testen.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** **Ja 💰** *(mit `--exploits-lassen` abschaltbar)*
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Zaubern ohne genug AE](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=6835#pid6835)

---

### R044 — Doppelte Fehlermeldung und verbrauchter Zauberzug bei bereits aktivem *Axxeleratus*
- **Was im Spiel passiert:** Zaubert man *Axxeleratus* auf einen Helden, der bereits unter der Wirkung von *Axxeleratus* steht, gibt das Spiel nach dem Hinweis noch eine zweite unpassende Fehlermeldung aus.
- **Ursache im Code:** In `gz_110d90` (`f_111a80`) setzte der Abbruchzweig bei bereits aktivem *Axxeleratus* die Kostenkennung `S(p1, 0)` auf `0` (Misslungen) statt auf `-4` (Zauberabbruch ohne Probe).
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R045 — Uninitialisierter Stackwert beim Gegenstandszauber ohne passenden Gegenstand im Inventar
- **Was im Spiel passiert:** Wird der Gegenstandszauber (`f_1127e0`) gesprochen, obwohl der Zaubernde weder Fackel (`0x41`) noch Laterne (`0x19`) im Inventar trägt, liest die Funktion eine uninitialisierte lokale Variable vom Stack und bricht nicht sauber ab.
- **Ursache im Code:** In `gz_112590` (`f_1127e0`) war die Auswahlvariable `short choice` nicht mit `0` initialisiert und im `else`-Zweig (kein passender Gegenstand vorhanden) fehlte die Abbruchkennung `*(short *)p1 = -4`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R049 — *Destructibo* vernichtet den Gegenstand selbst dann, wenn die Astralenergie nicht ausreicht
- **Was im Spiel passiert:** Wendet man den Entzauberungs-Spruch *Destructibo* auf einen magischen Gegenstand an und würfelt das Spiel höhere AE-Kosten (`5W10 + Permanenz`) aus, als der Magier besitzt, schlägt der Zauber wegen AE-Mangels fehl — der Gegenstand ist aber trotzdem unwiederbringlich aus dem Inventar gelöscht!
- **Ursache im Code:** In `gz_10d6b0_t1` (`f_10dce0`) zerstörte die Funktion zuerst den Gegenstand über `f_033530` und würfelte und prüfte erst **danach** die benötigten Astralpunkte `p->s0`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R052 — Lorenfahrt in der Zwergenbinge überspringt Kampf und Schrankenöffnung, wenn alle Helden die GE-Probe bestehen
- **Was im Spiel passiert:** Bei der Lorenfahrt in der Zwergenbinge müssen alle Helden eine um 8 erschwerte Gewandtheitsprobe ablegen. Besteht ausgerechnet die gesamte Gruppe diese schwere Probe, werden der anschließende Kampf und das Öffnen der Schranke übersprungen und die Lorenfahrt hängt fest.
- **Ursache im Code:** In `mine1_t1` (`Z832_c192`) lieferte die Filterfunktion `f_0c2f00` nur dann einen Heldenzeiger `t != 0`, wenn mindestens ein Held die GE+8-Probe verpatzt hatte, und band fälschlich auch den Folgekampf (`0x37`) und das Öffnen der Schranke (`0x191`) an `if (t)`; zudem war in `f_0c0e30` der Rückgabewert `r` nicht initialisiert.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse und Forenberichte zur Zwergenbinge gefunden)*

---

### R054 — *Sinnesschärfe*-Warnung bei einer Falle erscheint nur bei misslungener statt bei bestandener Probe
- **Was im Spiel passiert:** An einer Gefahrenstelle im Dungeon erhalten die Helden den rettenden Warnhinweis nur dann, wenn ihre *Sinnesschärfe*-Probe **misslingt**, während aufmerksame Helden bei bestandener Probe ohne jede Warnung hineinlaufen.
- **Ursache im Code:** In `gz_0c9940_t2` (`f_0cab30`) war die Bedingung nach der *Sinnesschärfe*-Probe `f_03bd00` invertiert (`if (!b)` statt `if (b == 1)`).
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R055 — Die 20. Straßenbegegnung in Riva wird niemals ausgelöst oder zurückgesetzt
- **Was im Spiel passiert:** Bei der Auswahl und Verwaltung der 20 Straßenbegegnungen im Stadtgebiet von Riva wird der 20. Eintrag in der Begegnungstabelle durch einen Schleifenfehler nie gezählt und nie zurückgesetzt.
- **Ursache im Code:** Sowohl in `street` (`f_11e500`) als auch in den Zwillingsfunktionen `Context11CA493::f_11e350` und `Context11CA493::f_11e380` in `gz_11caf0_t12` liefen die Schleifen von `0` bis `19` (`< 20`) statt über die 1-basierten Einträge `1` bis `20` (`<= 20`) des Arrays `d_1c0a3c`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R056 — Seil-/Hebel-Schalter im Schlossturm lässt sich nicht zurückschalten und liest bei Index `-1` vor dem Array
- **Was im Spiel passiert:** In den oberen Ebenen des Schlossturms (`castle_t3`) bleibt ein Seil-/Hebelzustand nach dem ersten Betätigen dauerhaft auf `1` hängen, und bei nicht gefundenem Raumeintrag (`-1`) liest das Spiel vor dem Anfang einer Koordinatentabelle.
- **Ursache im Code:** In `castle_t3` (`f_02c9a0`) wies sowohl der `if`- als auch der `else`-Zweig `d_1bc82c = 1` zu (statt im `else`-Zweig `0`), und in `f_02d230` fehlte vor dem Zugriff auf `d_1a06a8[idx]` die Prüfung `if (idx != -1)`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R058 — Zufallsschaden auf dem Schiff verringert sich mit jedem getroffenen Helden
- **Was im Spiel passiert:** Erleidet die Heldengruppe auf dem Schiff (`ship_t1`) gruppenweiten Zufallsschaden, bekommt der erste Held den vollen Zufallsbereich ab, während für jeden folgenden Helden die Obergrenze immer weiter schrumpft (oft bis auf 1 Punkt).
- **Ursache im Code:** In `ship_t1` (`f_0fbd80`) speicherte die Heldenschleife das Zufallsergebnis `f_1457e0(p4)` direkt in der Parameter-Variablen `p4` und überschrieb damit schon beim ersten Helden die übergebene Schadensobergrenze.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R068 — Endlosschleife an den Gangfallen im Magierturm, wenn nur noch der Anführer bei Bewusstsein ist
- **Was im Spiel passiert:** Wird auf der dritten Ebene des Magierturms (`tower3_t2`) eine der Sicherheitsfallen untersucht, während in einer mehrköpfigen Gruppe außer dem Anführer alle übrigen Gruppenmitglieder bewusstlos oder tot sind, friert das Spiel in einer Endlosschleife ein.
- **Ursache im Code:** In `tower3_t2` (`f_130fd0`, Z. 847–860) prüfte das Spiel nur die Gesamtgruppengröße `f_0db9a0(d_1c0004) > 1` und würfelte danach in `do { r = f_038ba0(d_1c0004); } while (f_0d4a60(r) == 0 || r == q);` so lange zufällige Gruppenmitglieder aus, bis ein zweiter handlungsfähiger Held (`f_0d4a60(r) != 0 && r != q`) gefunden ist — existiert keiner (`f_039c50(d_1c0004, q) == 0`), endet die Schleife nie.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R072 — Kalender-Überlauf bei Monats- und Jahreswechsel rechnet falsch
- **Was im Spiel passiert:** Überschreitet eine Zeitaddition (z. B. längere Reise, Haft oder Wartezeit) das Monatsende (30 Tage) oder das Jahresende (12 Monate), springt das Spieldatum auf falsche Tages- oder Monatswerte.
- **Ursache im Code:** In `gz_126c40` (`f_126f80`) rechnete der Tagesüberlauf `p1->b = 30 - p1->b` (negativer Wert statt `p1->b -= 30`) und der Jahresüberlauf zog vom Monat nur `1` statt `12` ab (`p1->c -= 1` statt `p1->c -= 12`).
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R084 — Tagebucheinträge mit Stichwort-Nummern ab 128 werden nicht gefunden
- **Was im Spiel passiert:** Spätere Tagebucheinträge und Gesprächsnotizen, deren interne Stichwort-Kennung zwischen 128 und 255 liegt, können beim Nachschlagen im Tagebuch nicht mehr zugeordnet werden.
- **Ursache im Code:** In `diary` (`f_057a00`) wurde das Stichwort-Byte des Tagebucheintrags als vorzeichenbehaftetes `signed char` (`-128..127`) statt als `unsigned char` (`0..255`) ausgelesen und mit der positiven Such-ID verglichen.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R092 — Sinnloser Nullzeiger-Aufruf `strcat(p2, 0)` in der Textformatierung
- **Was im Spiel passiert:** Beim Zusammensetzen bestimmter mehrteiliger Ausgabetexte ruft das Spiel `strcat` mit einem Nullzeiger als Quellstring auf, was je nach Speicherinhalt an Adresse `0` Müllzeichen anhängt oder abstürzt.
- **Ursache im Code:** In `lang_cze` (`f_0abc00` und `f_0abc30`) stand am Ende der String-Verkettung ein überflüssiger Aufruf `strcat(p2, (char *)0)`.
- **Stufe:** A (`WICHTIG` + `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

## 3. Zusätzliche Korrekturen in `RIVA_FIX_ALLES.EXE` (Stufe B — 21 Fixes)

Stufe B enthält über alle Stufe-A-Korrekturen hinaus 21 weitere Verbesserungen für Feilschen, Alchemie, Charaktersteigerung, Kämpfe, Dialoge und Dungeon-Ereignisse.

---

### R007 — Fehlende Kapazitätsprüfung im ACE-Variablenregister
- **Was im Spiel passiert:** Werden in einer komplexen `.ACE`-Animationssequenz mehr Variablen registriert als im dynamischen Array vorgesehen, schreibt die Engine über das Ende des Puffers hinaus.
- **Ursache im Code:** In `ace_t2a1` (`f_011730`) wurde `p2->arr[p2->n]` beschrieben und `p2->n` erhöht, ohne zuvor `p2->n < p2->cap` zu prüfen.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R013 — Doppelte Ortsprüfung bei der Lebensenergie-Regeneration und im Talentmenü
- **Was im Spiel passiert:** Bei der Sonderprüfung für die Lebensenergie-Regeneration sowie beim Aufbau des Talent-Auswahlmenüs auf bestimmten Karten (`0x30000` / `0x30001`) wird die zweite Karte durch einen Kopierfehler ignoriert.
- **Ursache im Code:** Sowohl in `charact1` (`f_044890`) als auch im Zwilling `ch_skill` (`f_03ac50`) stand durch Copy-Paste zweimal hintereinander `d_1c2a80 == 0x30000 || d_1c2a80 == 0x30000` statt `0x30000 || 0x30001`.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R014 — Fehlende Untergrenzenprüfung für Porträtslots und nicht zurückgesetzte Einmal-Flags im Schloss
- **Was im Spiel passiert:** Beim Zurücksetzen des Schlosses (`gz_028190`) bleiben zwei Einmal-Ereignisflags erhalten, und bei einer Mausposition links des ersten Porträtslots dekrementiert die Rückwärtsschleife über `d_1a48f4` ohne Untergrenze `> 0`.
- **Ursache im Code:** In `gz_028190` (`f_028190`) sowie im Zwilling `carrier` (`Car::f_027750`) fehlte die Untergrenzenprüfung `s > 0` bzw. `i > 0` vor dem Dekrement über `d_1a48f4`, und in `f_0281d0` wurden die beiden 1-Byte-Flags `d_1bc81c` und `d_1bc81d` beim Reset nicht auf `0` gesetzt.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R017 — Neue Automap-Notiz überschreibt bestehende Notiz, wenn alle Nachbarfelder voll sind
- **Was im Spiel passiert:** Setzt man auf der Automap einen Notizpunkt an eine Stelle, deren 3×3 Nachbarfelder bereits alle mit Markierungen belegt sind, überschreibt das Spiel stillschweigend eine der bestehenden Notizen.
- **Ursache im Code:** In `amap_t345` (`ContextAMap5::f_019fd0`) wurde nach erfolgloser 3×3- Nachbarschaftssuche (`found == 0`) der zuletzt getestete Index `r` nicht auf `-1` zurückgesetzt, sondern trotzdem an `f_01b320` übergeben.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R025 — Alchemie-Braudauer wird in Tagen statt Stunden geprüft, Array-Unterlauf bei Abbruch & leere Gruppe bei Rezept `0x153` 💰 Exploit
- **Was im Spiel passiert:** Bricht man im Alchemie-Menü die Rezeptauswahl sofort ab (`Auswahl 0`), liest das Spiel vor dem Arrayanfang; wählt man ein aufwendiges Rezept (über 8 Stunden Braudauer), lässt es sich selbst dann noch starten, wenn bis zum Ablauf der verfügbaren Ruhezeit gar nicht mehr genug Stunden übrig sind; braut außerdem ein einzelner Held in einer 1-Personen-Teilgruppe das Scherzrezept `0x153` (*Geldscheißer*), verlässt er die Gruppe und hinterlässt eine leere, unspielbare Gruppe.
- **Ursache im Code:** In `alchemy` (`f_012dd0`) griff `work.tab[sel - 1]` bei `sel == 0` ungeprüft auf Index `-1` zu, und bei der Zeitprüfung wurde die bereits in Stunden gespeicherte Rezeptdauer `d_1a68f4[k].d` nochmals durch `24` geteilt; in `gz_0132a0` (`f_0133b0`) wurde beim Rezept `0x153` `f_0dcd30` ohne Prüfung auf `f_0db9a0(d_1c0004) > 1` aufgerufen.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** **Ja 💰** *(mit `--exploits-lassen` abschaltbar)*
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R027 — Händler verspricht beim Feilschen im Text mehr als 30 % Rabatt und schneidet große Beträge ab
- **Was im Spiel passiert:** Gibt man beim Feilschen mit sehr hohem *Feilschen*-Talentwert z. B. 45 % Rabatt ein und besteht die Probe, stimmt der Händler im Dialogtext begeistert den „45 Prozent“ zu, zieht vom Kaufpreis aber nur die intern erlaubten 30 % ab; bei sehr großen Einkaufssummen läuft außerdem die 16-Bit-Rabattberechnung über.
- **Ursache im Code:** In `gz_1099f0_t1` (`f_109a50`) wurde der ausgehandelte Prozentsatz erst **nach** dem Eintragen in den Textslot `o.slots[4]` mit `f_0bd350(t, 0, 30)` auf 30 % gedeckelt, und das Ergebnis `(r * price) / 100` wurde bei der Rückgabe auf `short` (16 Bit) abgeschnitten.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Feilschen-Anzeige über 30 %](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=9496#pid9496)

---

### R028 — Erschwernis +1 beim Feilschen trotz 0 % Rabattforderung und Schutz vor negativen Preisen
- **Was im Spiel passiert:** Selbst wenn man beim Feilschen im Laden „0 %“ eingibt (also gar keinen Preisnachlass verlangt), wird die *Feilschen*-Probe um +1 erschwert und der Händler kann bei mehreren Fehlversuchen wütend das Geschäft schließen.
- **Ursache im Code:** In `gz_040280` (`f_040cb0`) wurde auf den Probenaufschlag pauschal `+ 1` addiert, auch wenn die geforderte Prozentzahl `p4 == 0` war; zusätzlich fehlte in `shop` (`f_1094e0`, `f_109800`) eine untere Schranke `if (price < 0) price = 0`.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Feilschen / Preise](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=6832#pid6832)

---

### R029 — Manuelle Talent- und Zaubersteigerung verbraucht bei Wert 18 sinnlos Steigerungsversuche
- **Was im Spiel passiert:** Hat ein Held bei einem Talent oder Zauber bereits den Wert 18 erreicht und klickt der Spieler beim Stufenaufstieg im manuellen Modus (ohne automatisches Auswürfeln) nochmals darauf, schlägt die Probe garantiert fehl (`3W6 > 18` ist unmöglich), zieht aber trotzdem einen wertvollen Steigerungsversuch ab.
- **Ursache im Code:** Während die automatische Steigerung ab Wert 18 sperrt, fehlte in den manuellen Steigerungsfunktionen `Lv::f_037030` (Zauber) und `Lv::f_037140` (Talente) in `ch_level_t1` vor dem Abzug des Versuchs die Prüfung auf `< 18`.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Steigerungsversuche bei 18](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=12071#pid12071)

---

### R030 — Spiegelbilder im Magierturm haben einen ungedeckelten Attackewert (`2 × Heldenstufe`)
- **Was im Spiel passiert:** Betritt eine hochstufige Heldengruppe (ab Stufe 10) den Spiegelkampf im Magierturm, treffen die gegnerischen Spiegelbilder mit einem Attackewert von 20 oder mehr (statt maximal 18 nach DSA-Regel) fast jeden Schlag automatisch.
- **Ursache im Code:** In `fi_ini` (`f_077760`) setzte das Spiel die Attacke der Spiegelbilder bei `d_1bd920 == 2` auf `2 * Heldenstufe`, ohne den Wert wie bei normalen Kampfwerten bei `18` zu deckeln.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Spiegelkampf im Magierturm](https://www.crystals-dsa-foren.de/showthread.php?tid=4441)

---

### R037 — Bei vollem Inventar im Laden wird nur der halbe Kaufpreis erstattet 💰 Exploit
- **Was im Spiel passiert:** Kauft man im Laden mehr Gegenstände ein, als in die Rucksäcke der Helden passen, und bricht den Verteilbildschirm ab, erstattet der Händler für die nicht übernommenen Waren nur den **halben** Wiederverkaufswert statt des gerade bezahlten Einkaufspreises (im Zusammenspiel mit dem Stapel-/Tauschbildschirm ließ sich das Verhalten zudem für Inventar-Tricks ausnutzen).
- **Ursache im Code:** In `shop` (`f_1094e0`) wurde für die im Übergabepool verbliebenen Restwaren `f_0dfdd0` aufgerufen, das den Bestandswert am Ende pauschal durch 2 teilt (Händler-Ankaufspreis), statt den vollen gezahlten Betrag (bis maximal zur Kaufsumme) zurückzuerstatten.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** **Ja 💰** *(mit `--exploits-lassen` abschaltbar)*
- **Forumsbezug:** [Crystals-DSA-Foren: Laden / Warenverteilung bei vollem Inventar](https://www.crystals-dsa-foren.de/showthread.php?tid=221)

---

### R038 — Nicht stapelbare Gegenstände verlieren beim Zusammenlegen in Truhen ihre individuellen Eigenschaften
- **Was im Spiel passiert:** Legt man in eine Truhe einen zweiten gleichartigen, aber eigentlich nicht stapelbaren Gegenstand (z. B. eine zweite Waffe, Rüstung oder einen Stab mit eigener Ladungszahl/Beschädigung), verschmilzt die Truhe beide zu einem Stapel und überschreibt die individuellen Zustandsdaten des zweiten Stücks.
- **Ursache im Code:** In `chest` (`f_047420`) prüfte die Truhenroutine beim Einlegen nur auf gleiche Gegenstands-ID (`r40`), fragte aber nicht über `d_1c2c40[r40]->f_0a7950()` ab, ob der Gegenstand überhaupt stapelbar ist.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Truhen-Inventar und Gegenstandszustand](https://www.crystals-dsa-foren.de/showthread.php?tid=46&pid=6689#pid6689)

---

### R039 — Zweifeldgroße Gegner prüfen bei der Wegsuche am Kampffeldrand außerhalb des 24×24-Bretts
- **Was im Spiel passiert:** Bewegt sich im Rundenkampf eine zweifeldgroße Kreatur (z. B. ein großes Monster oder Tier) direkt am Rand des 24×24-Kampffelds, liest die Wegsuche für das zweite Körperfeld außerhalb des Spielfeld-Arrays.
- **Ursache im Code:** Sowohl in `fi_g_tar_t1` (`f_074680`) als auch im Zwilling `fi_g_tar_t2` (`X::f_074b40`, Makros `FREI`, `FREIQ`, `FREIA`, `FREIG`) wurde für das hintere Feld `(nx2, ny2)` bzw. `(px, py)` einer Zweifeld-Einheit zuerst aus dem Kampffeld-Array gelesen und erst danach geprüft, ob die Koordinaten überhaupt zwischen `0` und `23` liegen.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R041 — Zauber mit variablen Kosten, *Karnifilo* und Untoten-Zauber prüfen die AE unvollständig 💰 Exploit
- **Was im Spiel passiert:** Zauber mit variabler Kostenberechnung lassen sich auch mit 0 AE anwählen; beim *Karnifilo Raserei* wird die Wirkung bereits auf das Ziel gelegt, bevor geprüft wird, ob die AE ausreicht, und bei Untoten-Zaubern (`f_10f910`) wird das Erfolgsflag `d_1c0424` vor der AE-Prüfung gesetzt.
- **Ursache im Code:** In `spell` (`f_10ce80`) fehlte bei variablen Spruchkosten (`v == -1`) die Mindestprüfung auf `>= 1` AE, in `gz_110d90` (`f_111930`, *Karnifilo*) fehlte vor dem Setzen der Timer die Prüfung `f_0429a0(caster) < S(p1, 0)`, und in `gz_10d6b0_t1` (`f_10f910`) wurde `d_1c0424 = 1` vor statt nach der Spruch- und AE-Prüfung zugewiesen.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** **Ja 💰** *(mit `--exploits-lassen` abschaltbar)*
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Zaubern ohne genug AE](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=6835#pid6835)

---

### R047 — Doppelte Fehlermeldung beim Zaubern von *Transversalis* an verbotenen Orten
- **Was im Spiel passiert:** Versucht man an einem Ort, an dem *Transversalis Teleport* gesperrt ist, zu teleportieren, erscheint nach der Orts-Fehlermeldung noch eine zweite allgemeine Zauber-Fehlermeldung.
- **Ursache im Code:** In `spell3_t1` (`f_10fc90`) setzte der Abbruchzweig für gesperrte Karten `W(p1, 0) = 0` statt der Abbruchkennung `-4`.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R051 — Zurückgelassene Teilgruppe am Gegenhebel im Magierturm wird nach dem Kampf nicht wiedervereinigt
- **Was im Spiel passiert:** Im Magierturm muss die Gruppe geteilt werden, um zwei Hebel zu bedienen. Wenn die aktive Teilgruppe nach dem Hebelkampf automatisch auf Ebene 20 teleportiert wird, bleibt die zweite Teilgruppe allein am Gegenhebel auf der alten Ebene zurück und muss mühsam von Hand nachgeführt werden.
- **Ursache im Code:** In `tower1_t2` (`f_12ba70`) versetzte das Ereignis nach dem Sieg nur die aktive Hauptgruppe `d_1c0004` nach Ebene 20, ohne die am zweiten Hebel wartende Teilgruppe `f_12c050()` über `f_0415c0` wieder mit der Hauptgruppe zusammenzuführen.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Gruppenteilung bei den Hebeln im Magierturm](https://www.crystals-dsa-foren.de/showthread.php?tid=82)

---

### R053 — Veralteter NPC-Zähler beim Entlassen mehrerer Gruppenmitglieder im Tempel
- **Was im Spiel passiert:** Entlässt man in der Gruppenverwaltung zunächst den begleitenden NPC und direkt im selben Durchlauf weitere Helden aus der Gruppe, rechnet die Schleifenbedingung für die Mindestgruppengröße noch mit dem bereits entlassenen NPC.
- **Ursache im Code:** In `char_opt` (`f_03f890`) wurde das Flag `a` (ob ein NPC in der Gruppe ist) nur einmal vor der `while`-Schleife abgefragt und nach dem Entlassen des NPCs über `f_0d64a0()` nicht aktualisiert.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Bugliste Schatten über Riva — Helden/NPC entlassen](https://www.crystals-dsa-foren.de/showthread.php?tid=322&pid=31865#pid31865)

---

### R059 — Einmal-Ereignis auf Feld `0x385` im Enddungeon setzt sein Auslöse-Flag nicht
- **Was im Spiel passiert:** Ein eigentlich einmaliges Ereignis auf Feld `0x385` im Enddungeon (`final2`) wird bei jedem erneuten Betreten des Feldes wieder ausgelöst.
- **Ursache im Code:** In `final2` (`f_08e320` und `f_08fcc0`) prüfte das Spiel zwar `if (!d_1bdb74)`, setzte `d_1bdb74` im Ereignisblock aber niemals auf `1`.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R071 — Folge-Ereignis `0x1f41` beim Aufbrauchen eines Vorrats (`0x322` / `0x182`) wird nie ausgelöst
- **Was im Spiel passiert:** Nimmt man bei Ereignis `0x322` (`gz_08cb00`) oder `f_08dae0` (`gz_08dae0_rand910a`) die letzten verbleibenden Stücke des Vorrats `0x182` an sich, wird das dafür vorgesehene Folge-Flag `0x1f41` nicht beim Erreichen von 0 gesetzt.
- **Ursache im Code:** Sowohl in `gz_08cb00` (`f_08cd20`, `case 0x322`) als auch im Zwilling `gz_08dae0_rand910a` (`f_08dae0`) prüfte das Spiel zuerst `if (d_1bdb20 == 0)` und zog erst **danach** die entnommene Menge von `d_1bdb20` ab.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R074 — Kopierfehler in den Dialogbedingungen `case 42` und `case 43`
- **Was im Spiel passiert:** Zwei Dialogzweige (`case 42` und `case 43`) reagieren auf dieselbe Statusvariable wie `case 40`/`41`, statt das eigentlich zugehörige Nachbar-Flag abzufragen.
- **Ursache im Code:** In `dialog_t1` (`f_055650`) wurde in `case 42` und `case 43` durch Copy-Paste `d_1bc788` statt des direkt benachbarten Flags `d_1bc78c` geprüft.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

### R076 — Flut-Timer nach dem Öffnen von Truhe `0x489` in der Kanalisation startet nie
- **Was im Spiel passiert:** Öffnet und plündert man die gesicherte Truhe auf Feld `0x489` in der Kanalisation, sollte eigentlich der Flut-Timer (`d_1c01a0 = 1`) anlaufen — im Originalspiel gab die Truhenfunktion jedoch stets `0` an den Aufrufer zurück.
- **Ursache im Code:** In `gz_0f25c0_t1` (`f_0f2de0`) stand `if (f_0f5110(p1)) d_1c01a0 = 1;`, obwohl die Truhenfunktion `f_0f5110` in `sewerag1_neu` bei Gegenstandsentnahme (`hit == 1`) zwar `d_1c01a0 = 1` setzte, ihre lokale Rückgabevariable `res` aber auf `0` beließ. Sowohl Aufrufer (`gz_0f25c0_t1`) als auch Truhenfunktion (`sewerag1_neu`) sind nun korrigiert.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** [Crystals-DSA-Foren: Truhe und Wasserstand in der Kanalisation](https://www.crystals-dsa-foren.de/showthread.php?tid=2240)

---

### R077 — Überlappendes `memcpy` und übersprungene Doppellücken beim Nachrücken der Gruppenplätze
- **Was im Spiel passiert:** Werden mehrere nebeneinanderliegende Heldenplätze in der Gruppe frei, rückt die Kompaktierungsfunktion beim ersten Durchlauf nur einen Platz nach und kopiert überlappende Speicherbereiche mit `memcpy`.
- **Ursache im Code:** In `gz_0dc9a0_ta` (`f_0dc9a0`) wurden die nachfolgenden Helden-Slots mit `memcpy` statt `memmove` um einen Slot nach vorn kopiert und der Schleifenindex `i` wurde nach dem Nachrücken nicht dekrementiert (`i--`), sodass ein direkt anschließender zweiter leerer Slot übersprungen wurde.
- **Stufe:** B (nur in `ALLES`) · **Spielervorteil (Exploit):** Nein
- **Forumsbezug:** — *(durch Code-Analyse gefunden)*

---

## 4. Bekannte Foren-Themen, die bewusst nicht im EXE-Code geändert wurden

Bei der Prüfung aller 115 Kandidaten (`R001`–`R114`) aus den Foren und der statischen Analyse wurden **63 Punkte** bewusst **nicht** als Code-Fix eingestuft (`KEIN`):

1. **In Version 1.12 bereits durch Attic behoben:** Viele berühmte Fehler aus der Verkaufsversion V1.00/V1.03 von 1996 — etwa der Absturz beim Etagenwechsel auf der *Windsbraut* (`R057`), das Hängenbleiben der Automove-Steuerung (`R008`/`R018`), der verschlossene Hintereingang der Gilde (`R061`) oder das mehrfache Auslösen des Bardenlieds in der Taverne (`R080`) — sind im rekonstruierten Code von V1.12 bereits sauber gepatcht.
2. **Reine Karten- oder Archivdaten in `RIVA.ALF` (kein EXE-Code):** Einige bekannte Eigenheiten wie das aus nur einer Richtung durchschreitbare **Regal in der Zwergenbinge** ([Crystals-DSA-Foren: Regal in der Binge](https://www.crystals-dsa-foren.de/showthread.php?tid=2550), `R067`) oder einzelne Wandflags in den Kartendaten liegen nicht in der `RIVA.EXE`, sondern in den binären Leveldaten des `.ALF`-Archivs. Da die Bugfix-Edition ausschließlich die Programmdatei ersetzt und `RIVA.ALF` unverändert lässt, bleiben die Original-Kartendaten unangetastet.
3. **Bewusste DSA-3-Regeln oder Spieldesign:** Manche oft als Bug gemeldeten Effekte sind im Code ausdrücklich als Regel umgesetzt — etwa dass *Transversalis Teleport* nur auf bereits **selbst betretene** Felder funktioniert und nicht auf bloß gekauften Stadtplänen (`R047`-Design), dass magische oder geweihte Waffen wie das *Schwert des Artherion* im Kampf einen festen Bruchtestfaktor von `0` besitzen (`R035`) oder dass *Bannbaladin* und *Horriphobus* nicht gegen Tiere/Monster wirken (`R046`).

---

## 5. Rückmeldungen & Hinweise für Tester (Testversion 1.0)

Die beiden Bugfix-Fassungen (`RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE`) sind **Testversionen**: Technisch und statisch sind alle 52 Änderungen, Segmente und Relokationen vollständig geprüft, im Spiel wurde vorab aber **nur der Programmstart getestet**.

**So hilfst du beim Testen:**
- Spiele mit **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`** oder **`RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat`** (bzw. unter Linux mit `./Linux/starten.sh wichtig --log`), damit nebenbei im **Live-Probenlog** (`PROBEN.CSV`) alle Talent-, Zauber-, Eigenschafts- und Kampfproben sichtbar sind.
- Wenn dir beim Spielen ein Fehler auffällt oder sich eine Korrektur an einer Stelle unerwartet verhält, melde dich gerne im **Crystals-DSA-Forum** oder eröffne ein Issue im Repository — am besten mit Angabe der verwendeten EXE-Fassung (`WICHTIG` / `ALLES`), der **`R`-Nummer** (falls bekannt) und einem passenden Spielstand (`.GAM` aus `Build\Testspielstaende_Fix_*`).
