# Live-Anzeige fuer PROBEN.CSV (DSA 3: Schatten ueber Riva)
# Liest neue Zeilen aus der CSV-Datei und gibt sie farbig formatiert aus.

param(
    [Parameter(Mandatory=$true)]
    [string]$CsvPfad
)

$Host.UI.RawUI.WindowTitle = "DSA Schatten ueber Riva - Live-Probenlog"
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

$AttrNamen = @(
    "MU", "KL", "CH", "FF", "GE", "IN", "KK",
    "AG", "HA", "RA", "GG", "TA", "NG", "JZ"
)

$TalentNamen = @(
    "Waffenlos", "Hiebwaffen", "Stichwaffen", "Schwerter", "Äxte",
    "Speere", "Zweihänder", "Schusswaffen", "Wurfwaffen", "Akrobatik",
    "Klettern", "Körperbeh.", "Reiten", "Schleichen", "Schwimmen",
    "Selbstbeh.", "Tanzen", "Verstecken", "Zechen", "Bekehren",
    "Betören", "Feilschen", "Gassenwissen", "Lügen", "Menschenkenntnis",
    "Schätzen", "Fährtensuchen", "Fesseln", "Orientierung", "Pflanzenkunde",
    "Tierkunde", "Wildnisleben", "Alchimie", "Alte Sprachen", "Geographie",
    "Geschichte", "Götter/Kulte", "Kriegskunst", "Lesen", "Magiekunde",
    "Sprachen", "Abrichten", "Fahrzeuge", "Falschspiel", "Heilk. Gift",
    "Heilk. Krankh.", "Heilk. Wunden", "Musizieren", "Schlösser", "Taschendiebstahl",
    "Gefahreninstinkt", "Sinnesschärfe"
)

$ZauberNamen = @(
    "-",
    "Beherrschung brechen", "Destructibo", "Gardianum", "Illusionen zerstören", "Verwandlung beenden",
    "Band und Fessel", "Bannbaladin", "Böser Blick", "Große Gier", "Große Verwirrung",
    "Herr über das Tierreich", "Horriphobus", "Magischer Raub", "Respondami", "Sanftmut",
    "Somnigravis", "Zwingtanz",
    "Furor Blut", "Geister bannen", "Geister rufen", "Heptagon", "Krähenruf", "Skelettarius",
    "Elementar beschwören", "Nihilogravo", "Solidirid",
    "Axxeleratus", "Foramen", "Motoricus", "Spurlos", "Transversalis", "Über Eis",
    "Balsam", "Hexenspeichel", "Klarum Purum", "Ruhe Körper", "Tiere heilen",
    "Adleraug", "Analüs", "Eigenschaften seid gelesen", "Exposami", "Odem Arcanum", "Penetrizzel", "Sensibar",
    "Chamaelioni", "Duplicatus", "Harmlose Gestalt", "Hexenknoten",
    "Blitz dich find", "Ecliptifactus", "Eisenrost", "Fulminictus", "Ignifaxius", "Plumbumbarum", "Radau", "Saft Kraft", "Scharfes Auge",
    "Hexenblick", "Nekropathia",
    "Adler Wolf", "Arcano Psychostabilis", "Armatrutz", "CH steigern", "Feuerbann", "FF steigern", "GE steigern", "IN steigern", "KK steigern", "KL steigern", "MU steigern", "Mutabili", "Paralü", "Salander", "See und Fluss", "Visibili",
    "Abvenenum", "Aeolitus", "Brenne toter Stoff", "Claudibus", "Dunkelheit", "Erstarre", "Flim Flam", "Schmelze", "Silentium", "Sturmgebrüll"
)

function AttrName([int]$idx) {
    if ($idx -ge 0 -and $idx -lt $AttrNamen.Count) { return $AttrNamen[$idx] }
    return "A$idx"
}

function TalentName([int]$idx) {
    if ($idx -ge 0 -and $idx -lt $TalentNamen.Count) { return $TalentNamen[$idx] }
    return "Talent #$idx"
}

function ZauberName([int]$idx) {
    if ($idx -ge 0 -and $idx -lt $ZauberNamen.Count) { return $ZauberNamen[$idx] }
    return "Zauber #$idx"
}

function ModText([int]$m) {
    if ($m -gt 0) { return "+$m" }
    return "$m"
}

function Format-Zeile([string]$zeile) {
    $t = $zeile.Split(';')
    if ($t.Count -lt 2) { return }
    $typ = $t[0]
    $held = if ($t[1].Trim() -ne "") { $t[1].Trim() } else { "(Held)" }

    if ($typ -eq "T" -and $t.Count -ge 14) {
        $nr = [int]$t[2]
        $tw = [int]$t[3]
        $mod = [int]$t[4]
        $a1 = AttrName ([int]$t[5]); $v1 = $t[6]; $w1 = $t[7]
        $a2 = AttrName ([int]$t[8]); $v2 = $t[9]; $w2 = $t[10]
        $a3 = AttrName ([int]$t[11]); $v3 = $t[12]; $w3 = $t[13]
        $erg = [int]$t[14]
        $name = TalentName $nr
        $info = "[Talent] {0,-10} {1,-16} ({2} {3}/{4} {5}/{6} {7}) TW {8,2} Mod {9,3} -> [{10,2}, {11,2}, {12,2}] " -f `
            $held, $name, $a1, $v1, $a2, $v2, $a3, $v3, $tw, (ModText $mod), $w1, $w2, $w3
        Write-Host -NoNewline $info
        if ($erg -eq 99) {
            Write-Host "GLÜCKLICH (Doppel-1!)" -ForegroundColor Yellow
        } elseif ($erg -le -98) {
            Write-Host "PATZER (Doppel-20!)" -ForegroundColor Magenta
        } elseif ($erg -gt 0) {
            $rest = $erg - 1
            Write-Host "OK (Rest +$rest)" -ForegroundColor Green
        } else {
            Write-Host "MISS" -ForegroundColor Red
        }
    }
    elseif ($typ -eq "Z" -and $t.Count -ge 14) {
        $nr = [int]$t[2]
        $zw = [int]$t[3]
        $mod = [int]$t[4]
        $a1 = AttrName ([int]$t[5]); $v1 = $t[6]; $w1 = $t[7]
        $a2 = AttrName ([int]$t[8]); $v2 = $t[9]; $w2 = $t[10]
        $a3 = AttrName ([int]$t[11]); $v3 = $t[12]; $w3 = $t[13]
        $erg = [int]$t[14]
        $name = ZauberName $nr
        $info = "[Zauber] {0,-10} {1,-20} ({2} {3}/{4} {5}/{6} {7}) ZW {8,2} Mod {9,3} -> [{10,2}, {11,2}, {12,2}] " -f `
            $held, $name, $a1, $v1, $a2, $v2, $a3, $v3, $zw, (ModText $mod), $w1, $w2, $w3
        Write-Host -NoNewline $info
        if ($erg -eq 99) {
            Write-Host "GLÜCKLICH (Doppel-1!)" -ForegroundColor Yellow
        } elseif ($erg -le -98) {
            Write-Host "PATZER (Doppel-20!)" -ForegroundColor Magenta
        } elseif ($erg -gt 0) {
            $rest = $erg - 1
            Write-Host "OK (Rest +$rest)" -ForegroundColor Green
        } else {
            Write-Host "MISS" -ForegroundColor Red
        }
    }
    elseif ($typ -eq "A" -and $t.Count -ge 7) {
        $a = AttrName ([int]$t[2])
        $wert = [int]$t[3]
        $mod = [int]$t[4]
        $w = [int]$t[5]
        $erg = [int]$t[6]
        $ziel = $wert - $mod
        $info = "[Attr]   {0,-10} {1} {2,2} (Mod {3,3}, Ziel <={4,2}) -> W20 = {5,2}  " -f `
            $held, $a, $wert, (ModText $mod), $ziel, $w
        Write-Host -NoNewline $info
        if ($erg -gt 0) {
            Write-Host "OK (Diff +$erg)" -ForegroundColor Green
        } else {
            Write-Host "MISS (Diff $erg)" -ForegroundColor Red
        }
    }
    elseif (($typ -eq "AT" -or $typ -eq "PA" -or $typ -eq "FK") -and $t.Count -ge 6) {
        $ziel = [int]$t[2]
        $mod = [int]$t[3]
        $w = [int]$t[4]
        $erg = [int]$t[5]
        $info = "[{0,-2}]     {1,-10} Ziel {2,2} (Mod {3,3}) -> W20 = {4,2}  " -f `
            $typ, $held, $ziel, (ModText $mod), $w
        Write-Host -NoNewline $info
        if ($erg -ge 2) {
            Write-Host "KRITISCHER TREFFER!" -ForegroundColor Yellow
        } elseif ($erg -eq 1) {
            Write-Host "OK" -ForegroundColor Green
        } elseif ($erg -le -1) {
            Write-Host "PATZER!" -ForegroundColor Magenta
        } else {
            Write-Host "FEHL" -ForegroundColor Red
        }
    }
}

Clear-Host
Write-Host "==============================================================================" -ForegroundColor Cyan
Write-Host "  DSA Schatten über Riva – Live-Probenlog" -ForegroundColor Cyan
Write-Host "  Datei: $CsvPfad" -ForegroundColor DarkGray
Write-Host "  (Wartet auf die erste Probe im Spiel... Beenden mit Strg+C)" -ForegroundColor DarkGray
Write-Host "==============================================================================" -ForegroundColor Cyan
Write-Host ""

$pos = 0
$enc = [System.Text.Encoding]::GetEncoding(437)

while ($true) {
    if (Test-Path $CsvPfad) {
        try {
            $fs = New-Object System.IO.FileStream($CsvPfad, [System.IO.FileMode]::Open, [System.IO.FileAccess]::Read, [System.IO.FileShare]::ReadWrite)
            if ($fs.Length -lt $pos) {
                $pos = 0
            }
            if ($fs.Length -gt $pos) {
                $fs.Seek($pos, [System.IO.SeekOrigin]::Begin) | Out-Null
                $sr = New-Object System.IO.StreamReader($fs, $enc)
                $neu = $sr.ReadToEnd()
                $pos = $fs.Position
                $sr.Close()
                foreach ($z in ($neu -split "`r?`n")) {
                    if ($z.Trim() -ne "") {
                        Format-Zeile $z.Trim()
                    }
                }
            } else {
                $fs.Close()
            }
        } catch {
            # Datei gerade von DOSBox gesperrt -> kurz warten
        }
    }
    Start-Sleep -Milliseconds 200
}
