#!/usr/bin/env bash
# Startet DSA 3: Schatten ueber Riva unter Linux in der nativen Linux-DOSBox.
#
# Aufruf:
#   ./Linux/starten.sh                  -> startet wichtig (Standard, Stufe A: sichere Fixes)
#   ./Linux/starten.sh wichtig          -> startet RIVA_FIX_WICHTIG.EXE (Stufe A)
#   ./Linux/starten.sh alles            -> startet RIVA_FIX_ALLES.EXE   (Stufe B)
#   ./Linux/starten.sh original         -> startet RIVA.EXE             (Nachbau)
#   ./Linux/starten.sh wichtig --log    -> startet zusätzlich das Live-Probenlog

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# shellcheck source=gemeinsam.sh
source "$SCRIPT_DIR/gemeinsam.sh"

MODUS="wichtig"
PROBENLOG="${PROBENLOG:-0}"

for arg in "$@"; do
    case "$arg" in
        wichtig|alles|original)
            MODUS="$arg"
            ;;
        --log|--probenlog|-l)
            PROBENLOG="1"
            ;;
        -h|--help)
            echo "Aufruf: $0 [wichtig|alles|original] [--log]"
            echo ""
            echo "  wichtig    Startet ${EXE}_FIX_WICHTIG.EXE (Standard, Stufe A: sichere Fixes)"
            echo "  alles      Startet ${EXE}_FIX_ALLES.EXE   (Stufe B: alle Fixes)"
            echo "  original   Startet ${EXE}.EXE             (aus Quelltext gebauter Nachbau)"
            echo "  --log      Zeigt nebenbei alle Talent-/Zauber-/Kampfproben live im Terminal"
            exit 0
            ;;
        *)
            echo "Unbekannte Option: $arg (Hilfe mit --help)" >&2
            exit 1
            ;;
    esac
done

BUILD="$WURZEL/Build"
case "$MODUS" in
    wichtig)
        QUELL_EXE="$BUILD/${EXE}_FIX_WICHTIG.EXE"
        RUNDIR="$BUILD/Fix_Wichtig"
        SAVES="$BUILD/Testspielstaende_Fix_Wichtig"
        CONF="$BUILD/dosbox_fix_wichtig_linux.conf"
        TITEL="${EXE}_FIX_WICHTIG.EXE (Stufe A: sichere Bugfixes)"
        ;;
    alles)
        QUELL_EXE="$BUILD/${EXE}_FIX_ALLES.EXE"
        RUNDIR="$BUILD/Fix_Alles"
        SAVES="$BUILD/Testspielstaende_Fix_Alles"
        CONF="$BUILD/dosbox_fix_alles_linux.conf"
        TITEL="${EXE}_FIX_ALLES.EXE (Stufe B: alle Bugfixes)"
        ;;
    original)
        QUELL_EXE="$BUILD/${EXE}.EXE"
        RUNDIR="$BUILD"
        SAVES="$BUILD/Testspielstaende"
        CONF="$BUILD/dosbox_test_linux.conf"
        TITEL="${EXE}.EXE (originalgetreuer Nachbau)"
        ;;
esac

if [[ ! -f "$QUELL_EXE" ]]; then
    echo "FEHLER: '$QUELL_EXE' fehlt." >&2
    if [[ "$MODUS" == "original" ]]; then
        echo "Bitte zuerst 'python3 Bauen/bauen.py' ausfuehren!" >&2
    else
        echo "Bitte zuerst './Linux/patchen.sh' ausfuehren!" >&2
    fi
    exit 1
fi

DOSBOX_CMD="$(suche_dosbox || true)"
if [[ -z "$DOSBOX_CMD" ]]; then
    echo "FEHLER: DOSBox wurde nicht gefunden." >&2
    echo "Bitte DOSBox ueber die Paketverwaltung installieren, z.B.:" >&2
    echo "  Debian/Ubuntu/Mint:  sudo apt install dosbox" >&2
    echo "  Fedora:              sudo dnf install dosbox-staging" >&2
    echo "  Arch/Manjaro:        sudo pacman -S dosbox" >&2
    exit 1
fi

suche_spielpfad

mkdir -p "$RUNDIR"
if [[ "$QUELL_EXE" != "$RUNDIR/$ORIG_EXE" ]]; then
    cp -f "$QUELL_EXE" "$RUNDIR/$ORIG_EXE"
fi

echo "Bereite Spielumgebung in '$SAVES' vor (Original-Ordner bleibt unangetastet)..."
if [[ ! -d "$SAVES" ]]; then
    echo "Erster Start: kopiere Spieldateien nach '$SAVES' ..."
    mkdir -p "$SAVES"
fi

# Spieldateien aus dem GOG-Ordner holen (ohne DOSBOX/MUSIC/cloud_saves und ohne Original-EXE),
# bereits geaenderte Dateien (z.B. Spielstaende) in $SAVES niemals ueberschreiben.
if command -v rsync >/dev/null 2>&1; then
    rsync -a --ignore-existing \
        --exclude='DOSBOX/' --exclude='dosbox/' \
        --exclude='MUSIC/' --exclude='music/' \
        --exclude='cloud_saves/' \
        --exclude='__support/' --exclude='webcache.zip' \
        --exclude="$ORIG_EXE" --exclude="${EXE}.OG" \
        "$SPIEL/" "$SAVES/"
    if [[ -d "$SPIEL/cloud_saves" ]]; then
        rsync -a --ignore-existing "$SPIEL/cloud_saves/" "$SAVES/"
    fi
else
    for eintrag in "$SPIEL"/*; do
        [[ -e "$eintrag" ]] || continue
        basis="$(basename "$eintrag")"
        case "${basis^^}" in
            DOSBOX|MUSIC|CLOUD_SAVES|__SUPPORT|WEBCACHE.ZIP|"${ORIG_EXE^^}"|"${EXE^^}.OG")
                continue
                ;;
        esac
        cp -rn "$eintrag" "$SAVES/" 2>/dev/null || true
    done
    if [[ -d "$SPIEL/cloud_saves" ]]; then
        for eintrag in "$SPIEL/cloud_saves"/*; do
            [[ -e "$eintrag" ]] || continue
            cp -rn "$eintrag" "$SAVES/" 2>/dev/null || true
        done
    fi
fi

# CD-Abbild (game.ins) im Spielordner suchen und fuer Linux-DOSBox vorbereiten:
# In GOGs game.ins stehen Backslashes (MUSIC\Track02.OGG). Da Linux-Dateisysteme
# Backslashes nicht als Pfadtrenner akzeptieren, erzeugen wir bei Bedarf eine
# bereinigte Kopie mit normalen Schraegstrichen im Spielordner.
CDBILD_PFAD="$(finde_datei_ci "$SPIEL" "$CDBILD" || true)"
if [[ -z "$CDBILD_PFAD" && -d "$SPIEL/.." ]]; then
    CDBILD_PFAD="$(finde_datei_ci "$(cd "$SPIEL/.." && pwd)" "$CDBILD" || true)"
fi
if [[ -n "$CDBILD_PFAD" ]] && grep -q '\\' "$CDBILD_PFAD" 2>/dev/null; then
    CDBILD_LINUX="$(dirname "$CDBILD_PFAD")/${CDBILD%.ins}_linux.ins"
    if [[ ! -f "$CDBILD_LINUX" || "$CDBILD_PFAD" -nt "$CDBILD_LINUX" ]]; then
        sed 's/\\/\//g' "$CDBILD_PFAD" > "$CDBILD_LINUX"
    fi
    CDBILD_PFAD="$CDBILD_LINUX"
fi

# Basis-Konfiguration (Zyklen, Soundblaster, Grafik) aus GOGs dosbox_realms3.conf
# ohne deren [autoexec]-Abschnitt uebernehmen
BASIS_CONF="$BUILD/dosbox_basis_linux.conf"
GOGCONF_PFAD="$(finde_datei_ci "$SPIEL" "$GOGCONF" || true)"
if [[ -n "$GOGCONF_PFAD" ]]; then
    awk 'BEGIN{ig=0} /^\[autoexec\]/{ig=1} !ig{print}' "$GOGCONF_PFAD" \
        | tr -d '\r' > "$BASIS_CONF"
else
    cat > "$BASIS_CONF" <<'EOF'
[sdl]
fullscreen=false
output=opengl
[cpu]
core=auto
cputype=auto
cycles=max
[mixer]
rate=44100
[sblaster]
sbtype=sb16
sbbase=220
irq=7
dma=1
hdma=5
EOF
fi

{
    echo "[autoexec]"
    echo "@echo off"
    echo "mount C \"$SAVES\""
    if [[ -n "$CDBILD_PFAD" ]]; then
        echo "imgmount D \"$CDBILD_PFAD\" -t iso"
    fi
    echo "mount E \"$RUNDIR\""
    echo "C:"
    echo "cls"
    echo "echo =================================================================="
    echo "echo   Starte $TITEL"
    echo "echo   Spielstaende liegen in $(basename "$SAVES")"
    echo "echo =================================================================="
    echo "E:\\$ORIG_EXE"
    echo "exit"
} > "$CONF"

LOG_PID=""
cleanup() {
    if [[ -n "$LOG_PID" ]] && kill -0 "$LOG_PID" 2>/dev/null; then
        kill "$LOG_PID" 2>/dev/null || true
    fi
}
trap cleanup EXIT

if [[ "$PROBENLOG" == "1" ]]; then
    rm -f "$SAVES/PROBEN.CSV" "$SAVES/proben.csv"
    echo "Starte Live-Probenlog hier im Terminal..."
    python3 "$WURZEL/Probenlog/probenlog.py" "$SAVES/PROBEN.CSV" &
    LOG_PID="$!"
fi

echo "Starte DOSBox ($DOSBOX_CMD) mit '$QUELL_EXE' ..."
# shellcheck disable=SC2086
$DOSBOX_CMD -conf "$BASIS_CONF" -conf "$CONF"
