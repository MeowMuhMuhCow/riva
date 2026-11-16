#!/usr/bin/env bash
# Gemeinsame Hilfsfunktionen fuer die Linux-Skripte (patchen.sh, starten.sh)

set -euo pipefail

LINUX_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WURZEL="$(cd "$LINUX_DIR/.." && pwd)"
MERKDATEI="$WURZEL/SPIELPFAD.txt"

# Spiel-Parameter laden (SPIELNAME, ORIG_EXE, EXE, GOGCONF, CDBILD, SUCHPFADE)
# shellcheck source=spiel.conf
source "$LINUX_DIR/spiel.conf"

# Sucht eine Datei in einem Ordner ohne Ruecksicht auf Gross-/Kleinschreibung.
finde_datei_ci() {
    local ordner="$1"
    local name="$2"
    [[ -d "$ordner" ]] || return 1
    if [[ -f "$ordner/$name" ]]; then
        printf '%s\n' "$ordner/$name"
        return 0
    fi
    local gefunden
    gefunden="$(find "$ordner" -maxdepth 1 -type f -iname "$name" -print -quit 2>/dev/null || true)"
    if [[ -n "$gefunden" ]]; then
        printf '%s\n' "$gefunden"
        return 0
    fi
    return 1
}

# Prueft, ob $1 ein gueltiger Spielordner ist (enthaelt ORIG_EXE direkt oder in data/app/).
pruefe_spielpfad() {
    local kandid="$1"
    [[ -n "$kandid" && -d "$kandid" ]] || return 1
    local unter
    for unter in "$kandid" "$kandid/data/noarch/data" "$kandid/data" "$kandid/app" "$kandid/game"; do
        if finde_datei_ci "$unter" "$ORIG_EXE" >/dev/null 2>&1; then
            SPIEL="$(cd "$unter" && pwd)"
            return 0
        fi
    done
    return 1
}

# Ermittelt den Spielordner und speichert ihn in $SPIEL sowie in SPIELPFAD.txt.
suche_spielpfad() {
    SPIEL=""

    # 1. Umgebungsvariable DSA_SPIELPFAD (falls vom Nutzer gesetzt)
    if [[ -n "${DSA_SPIELPFAD:-}" ]] && pruefe_spielpfad "$DSA_SPIELPFAD"; then
        printf '%s\n' "$SPIEL" > "$MERKDATEI"
        return 0
    fi

    # 2. Gespeicherter Pfad in SPIELPFAD.txt
    if [[ -f "$MERKDATEI" ]]; then
        local gesp
        gesp="$(tr -d '\r\n' < "$MERKDATEI")"
        if pruefe_spielpfad "$gesp"; then
            return 0
        fi
    fi

    # 3. Typische Linux-Pfade durchprobieren
    local p
    for p in "${SUCHPFADE[@]}"; do
        if pruefe_spielpfad "$p"; then
            printf '%s\n' "$SPIEL" > "$MERKDATEI"
            return 0
        fi
    done

    # 3b. Falls Original/RIVA.EXE im Projektordner abgelegt wurde
    if pruefe_spielpfad "$WURZEL/Original"; then
        return 0
    fi

    # 4. Grafischer Dialog (zenity / kdialog) oder Terminal-Abfrage
    echo ""
    echo "Der Installationsordner von '$SPIELNAME' (deutsche GOG-Version)"
    echo "wurde nicht automatisch gefunden (dort liegt $ORIG_EXE)."
    local wahl=""
    if [[ -n "${DISPLAY:-}${WAYLAND_DISPLAY:-}" ]]; then
        if command -v zenity >/dev/null 2>&1; then
            wahl="$(zenity --file-selection --directory \
                --title="Bitte den Spielordner von $SPIELNAME waehlen (enthaelt $ORIG_EXE)" 2>/dev/null || true)"
        elif command -v kdialog >/dev/null 2>&1; then
            wahl="$(kdialog --getexistingdirectory "$HOME" \
                --title="Bitte den Spielordner von $SPIELNAME waehlen (enthaelt $ORIG_EXE)" 2>/dev/null || true)"
        fi
    fi

    if [[ -z "$wahl" ]]; then
        echo ""
        read -r -e -p "Bitte Pfad zum Spielordner eingeben (enthaelt $ORIG_EXE): " wahl
        wahl="${wahl/#\~/$HOME}"
    fi

    if [[ -z "$wahl" ]]; then
        echo "Abgebrochen." >&2
        return 1
    fi

    if ! pruefe_spielpfad "$wahl"; then
        echo "" >&2
        echo "FEHLER: In '$wahl' wurde '$ORIG_EXE' nicht gefunden." >&2
        echo "Bitte den Hauptordner der deutschen GOG-Installation angeben." >&2
        return 1
    fi

    printf '%s\n' "$SPIEL" > "$MERKDATEI"
    return 0
}

# Sucht ein installiertes DOSBox (dosbox-staging, dosbox-x oder klassisches dosbox).
suche_dosbox() {
    local cmd
    for cmd in "${DOSBOX_BIN:-}" dosbox dosbox-staging dosbox-x; do
        if [[ -n "$cmd" ]] && command -v "$cmd" >/dev/null 2>&1; then
            printf '%s\n' "$cmd"
            return 0
        fi
    done
    if command -v flatpak >/dev/null 2>&1; then
        if flatpak info io.github.dosbox-staging >/dev/null 2>&1; then
            printf '%s\n' "flatpak run io.github.dosbox-staging"
            return 0
        fi
        if flatpak info com.dosbox.DOSBox >/dev/null 2>&1; then
            printf '%s\n' "flatpak run com.dosbox.DOSBox"
            return 0
        fi
    fi
    return 1
}
