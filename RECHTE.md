# Rechtliche Hinweise & Lizenz

## 1. Was dieses Repository enthält – und was nicht

Dieses Repository ist ein **nicht-kommerzielles Forschungs-, Dokumentations- und Erhaltungsprojekt** (Clean-Room-Rekonstruktion / Reverse Engineering zu Zwecken der Interoperabilität, Fehlerbehebung und Software-Archäologie).

### Nicht enthalten (und durch `.gitignore` technisch ausgeschlossen):
- **Keine Original-Spieldateien:** Weder `RIVA.EXE` noch Archive (`.ALF`), Grafiken, Musik (`MUSIC/*.OGG`), Videos, Sprachausgabe, CD-Abbilder (`game.ins` / `game.gog`) oder sonstige Assets des Spiels sind enthalten.
- **Kein historischer Compiler:** Weder Watcom C/C++ 10.6 (`WPP386.EXE`, `WCC386.EXE`, `WASM.EXE`, `WLINK.EXE`) noch dessen Laufzeitbibliotheken (`CLIB3R.LIB`, `PLIB3R.LIB`, `MATH387R.LIB`) oder der DOS/4GW-Extender sind enthalten.
- **Kein DOSBox-Binärpaket.**

Um das Projekt zum Bauen oder Spielen zu nutzen, ist zwingend eine **eigene, rechtmäßig erworbene Kopie** der deutschen Version von *Das Schwarze Auge: Schatten über Riva* (z. B. über [GOG.com](https://www.gog.com/de/game/realms_of_arkania_1_2_3)) erforderlich.

---

## 2. Marken- und Urheberrechte am Originalspiel

- *Das Schwarze Auge* (DSA) ist eine eingetragene Marke der **Ulisses Spiele GmbH** (bzw. ihrer jeweiligen Lizenzgeber).
- *Das Schwarze Auge: Schatten über Riva* (*Realms of Arkania III: Shadows over Riva*) wurde 1996 von **Attic Entertainment Software** entwickelt.
- Dieses Projekt steht in keiner offiziellen Verbindung zu den Marken- oder Rechteinhabern.

---

## 3. Lizenz der eigenen Werkzeuge und Skripte

Die für dieses Projekt neu geschriebenen Build-, Patch-, Start- und Analyse-Skripte in den Ordnern `Bauen/`, `Patch/`, `Linux/`, `Probenlog/` und `Werkzeuge/` stehen unter der **MIT-Lizenz** (siehe [`Werkzeuge/LICENSE`](Werkzeuge/LICENSE)).
