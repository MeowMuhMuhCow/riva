# Live-Probenlog beim Spielen

In den fehlerbereinigten Versionen (`RIVA_FIX_WICHTIG.EXE` und `RIVA_FIX_ALLES.EXE`) kann optional jede gewürfelte Probe im Spiel in eine kleine Textdatei `PROBEN.CSV` im jeweiligen Spielstands-Ordner geschrieben und live angezeigt werden:

- **Talentproben** (3×W20 auf die drei Eigenschaften, Talentwert, Zuschlag/Erschwernis, übrig gebliebene Punkte, Patzer / glückliche Probe)
- **Zauberproben** (3×W20 auf die drei Eigenschaften, Zauberwert, Zuschlag/Erschwernis incl. Magieresistenz)
- **Eigenschaftsproben** (1×W20 gegen Eigenschaft ± Zuschlag)
- **Kampfproben** (Attacke, Parade, Fernkampf mit W20-Wurf und Zielwert)

Die Original-Version (`RIVA.EXE`, gebaut ohne Fix-Schalter) enthält diesen Code **nicht** und bleibt 100 % byte-identisch zum Original von 1997 (V1.12).

### Protokollierte Proben im Spiel (`FIX_BUGS >= 1`)

Das Live-Probenlog ist über `Quelle/inc/r_plog.h` direkt in den zentralen Würfelfunktionen von *Schatten über Riva* verankert und erfasst:

1. **Eigenschaftsproben (`A`, `PLOG_1W20`)** – `charact1` (`f_044900`):
   - Jede 1W20-Probe eines Helden auf eine der 14 Eigenschaften (`MU` bis `JZ`) inklusive Probenmodifikator, effektivem Eigenschaftswert, gewürfeltem W20 und Punktedifferenz (bzw. `-99` bei gewürfelter 20).
2. **Talentproben & Dreifachproben (`T`, `PLOG_3W20`)** – `charact1` (`f_044c90`, `f_044940`):
   - Alle regulären 3W20-Talentproben (Talente 9 = *Akrobatik* bis 51 = *Sinnesschärfe*) mit den drei geprüften Eigenschaften (`d_1a6ad0`–`d_1a6ad2`), deren aktuellen Werten, dem Talentwert (`f_03ad80`), der Erschwernis/Erleichterung, den drei einzelnen W20-Würfen und den übrigbehaltenen Punkten (`-99` bei Doppel-20-Patzer).
   - Direkte dreifache Eigenschaftsproben (`f_044940`, z. B. bei Großer Meditation oder Stabzaubern).
3. **Zauberproben (`Z`, `PLOG_3W20`)** – `gz_03d3d0` (`Ent::f_03d3d0`):
   - Jede 3W20-Zauberprobe eines Helden (Zauber 1 = *Beherrschung brechen* bis 85 = *Sturmgebrüll*) inklusive Zauberfertigkeitswert (`f_0430f0`), Gesamtmodifikator unter Einschluss der Magieresistenz des Ziel-Monsters (`f_0cfa70`) bzw. Ziel-Helden (`f_0423a0`), den drei Eigenschaften aus der Zaubertabelle (`d_1a7270`), den drei W20-Würfen und dem Endergebnis.
4. **Kampfproben (`AT`, `PA`, `FK`, `PLOG_KAMPF`)**:
   - **Fernkampf Held** (`FK`): `charact1` (`f_044c90`, Talente 7 = *Schusswaffen* und 8 = *Wurfwaffen*) – 1W20 gegen `(KL + GE + KK) / 4 + TaW - Mod` mit Erkennung von Meisterschuss (`1`) und Patzer (`20`).
   - **Nahkampf Held gegen Held** (`AT`, `PA`): `gz_085d60_t1` (`f_086bf0`) – Attacke- und Paradewürfe inklusive Patzerbestätigung.
   - **Nahkampf Held gegen Monster** (`AT`, `PA`): `fight_t1` (`f_087ea0`) – Helden-Attacke (inkl. kritischem Treffer und Patzerbestätigung) sowie Monster-Parade.
   - **Nahkampf Monster gegen Monster** (`AT`, `PA`): `fight_t2` (`f_088a50`) – Attacke- und Paradewürfe beider Monster inklusive Patzerbestätigung.
   - **Nahkampf Monster gegen Held** (`AT`, `PA`): `fight_t2` (`f_089990`) – Monster-Attacke und Helden-Parade inklusive Patzerbestätigung.
   - **Fernkampf Monster gegen Held** (`FK`, `PA`): `gz_0d0350` (`f_0d0df0`) – Fernkampfwurf des Monsters und Ausweichprobe (`(MU + IN + GE) / 4`) des beschossenen Helden.

---

## So startest du das Spiel mit Live-Probenlog

Einfach im Hauptordner eine der beiden Starter-Dateien doppelt anklicken:

- **`RIVA_FIX_WICHTIG_MIT_PROBENLOG_STARTEN.bat`** (Stufe A: sichere Fixes + Live-Fenster)
- **`RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat`** (Stufe B: alle Fixes + Live-Fenster)

Es öffnet sich neben DOSBox ein zweites Konsolenfenster (**„DSA Probenlog"**), in dem jede Probe im selben Moment farbig aufgelistet wird:

```
==============================================================================
  DSA Schatten über Riva – Live-Probenlog
==============================================================================

  [Talent] Thorgrim  Schlösser (KL 12 / IN 13 / GE 14)  TW 7  Mod +2  -> [9, 14, 11]  MISS (Rest -1)
  [Zauber] Eliane    Fulminictus (KL 14 / IN 13 / KK 11)  ZW 9  Mod +3  -> [11, 8, 12]  OK (Rest +5)
  [AT]     Thorgrim  Ziel 15  -> W20 = 7   TREFFER
  [PA]     Thorgrim  Ziel 12  -> W20 = 16  FEHL
```

- **Grün** = Probe gelungen / Treffer
- **Rot** = Probe misslungen / Fehlschlag
- **Gelb** = Kritischer Erfolg (Doppel-/Dreifach-1, glückliche AT/PA)
- **Magenta** = Patzer (Doppel-/Dreifach-20, Waffe/Schild-Patzer)
