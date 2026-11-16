#!/usr/bin/env bash
# Erzeugt die fehlerbereinigten EXE-Dateien (ohne Compiler) unter Linux.
# Gegenstueck zu PATCHEN.bat unter Windows.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# shellcheck source=gemeinsam.sh
source "$SCRIPT_DIR/gemeinsam.sh"

echo "============================================================================"
echo "  DSA 3: $SPIELNAME - Fehlerbereinigte EXE erzeugen (ohne Compiler)"
echo "============================================================================"
echo ""

if ! command -v python3 >/dev/null 2>&1; then
    echo "FEHLER: 'python3' wurde nicht gefunden." >&2
    echo "Bitte Python 3 ueber die Paketverwaltung installieren (z.B. 'sudo apt install python3')." >&2
    exit 1
fi

if [[ $# -ge 1 ]]; then
    DSA_SPIELPFAD="$1"
    export DSA_SPIELPFAD
fi

suche_spielpfad

python3 "$WURZEL/Patch/patchen.py" \
    --spiel "$SPIEL" \
    --name "$ORIG_EXE" \
    --ziel "$WURZEL/Build"

echo ""
echo "============================================================================"
echo "  Fertig! Du kannst das Spiel jetzt direkt starten ueber:"
echo ""
echo "    ./Linux/starten.sh wichtig          (empfohlen: sichere Korrekturen, Stufe A)"
echo "    ./Linux/starten.sh alles            (alle Korrekturen, Stufe B)"
echo "    ./Linux/starten.sh wichtig --log    (mit Live-Probenlog im Terminal)"
echo ""
echo "  Deine Original-Installation in '$SPIEL' wurde NICHT veraendert."
echo "============================================================================"
