param(
    [Parameter(Mandatory=$true)][string]$Spiel,
    [Parameter(Mandatory=$true)][string]$Name,
    [Parameter(Mandatory=$true)][string]$Ziel
)

$ErrorActionPreference = "Stop"

$ErwOrigGroesse = 2477899
$ErwOrigMd5 = "fb8f5fc3ba5454c7344c17aaf362de35"

function Hole-MD5([byte[]]$daten) {
    $md5 = [System.Security.Cryptography.MD5]::Create()
    try {
        $hash = $md5.ComputeHash($daten)
        return [BitConverter]::ToString($hash).Replace("-", "").ToLowerInvariant()
    } finally {
        $md5.Dispose()
    }
}

function Lese-U32([byte[]]$b, [int]$pos) {
    return [BitConverter]::ToUInt32($b, $pos)
}

function Wende-Patch-An([byte[]]$orig, [string]$origMd5, [string]$patchPfad, [string]$zielPfad) {
    $p = [System.IO.File]::ReadAllBytes($patchPfad)
    if ($p.Length -lt 64) {
        Write-Host "FEHLER: Ungueltige oder zu kurze Patch-Datei: $patchPfad" -ForegroundColor Red
        return $false
    }
    $magic = [System.Text.Encoding]::ASCII.GetString($p, 0, 4)
    if ($magic -ne "NDP2") {
        Write-Host "FEHLER: Ungueltiges Patch-Format ($magic statt NDP2): $patchPfad" -ForegroundColor Red
        return $false
    }

    $erwGroesse  = [int](Lese-U32 $p 4)
    $zielGroesse = [int](Lese-U32 $p 8)
    $erwMd5      = [BitConverter]::ToString($p, 12, 16).Replace("-", "").ToLowerInvariant()
    $sollMd5     = [BitConverter]::ToString($p, 28, 16).Replace("-", "").ToLowerInvariant()

    if ($orig.Length -ne $erwGroesse -or $origMd5 -ne $erwMd5) {
        Write-Host ""
        Write-Host "FEHLER: Deine '$Name' passt nicht zur erwarteten deutschen GOG-Originalversion (V1.12)!" -ForegroundColor Red
        Write-Host "  Gefunden: $($orig.Length) Bytes, MD5 $origMd5"
        Write-Host "  Erwartet: $erwGroesse Bytes, MD5 $erwMd5"
        Write-Host "Abbruch: Bitte die unveraenderte deutsche Original-RIVA.EXE (Version 1.12) verwenden." -ForegroundColor Red
        return $false
    }

    $anzBloecke = [int](Lese-U32 $p 44)
    $lenHdr     = [int](Lese-U32 $p 48)
    $lenSub     = [int](Lese-U32 $p 52)
    $lenAdds    = [int](Lese-U32 $p 56)
    $lenLits    = [int](Lese-U32 $p 60)
    $erwRaw     = $lenHdr + $lenSub + $lenAdds + $lenLits

    $msIn = New-Object System.IO.MemoryStream($p, 64, ($p.Length - 64))
    $deflate = New-Object System.IO.Compression.DeflateStream($msIn, [System.IO.Compression.CompressionMode]::Decompress)
    $msOut = New-Object System.IO.MemoryStream($erwRaw)
    try {
        $deflate.CopyTo($msOut)
        $raw = $msOut.ToArray()
    } finally {
        $deflate.Dispose()
        $msIn.Dispose()
        $msOut.Dispose()
    }

    if ($raw.Length -ne $erwRaw) {
        Write-Host "FEHLER: Entpackte Patch-Datenlaenge stimmt nicht ($($raw.Length) != $erwRaw)!" -ForegroundColor Red
        return $false
    }

    [int]$hPos = 0
    [int]$sPos = $lenHdr
    [int]$aPos = $lenHdr + $lenSub
    [int]$lPos = $lenHdr + $lenSub + $lenAdds

    $neu = New-Object byte[] $zielGroesse
    [int]$dst = 0
    [int]$lastSrcEnd = 0

    for ([int]$blk = 0; $blk -lt $anzBloecke; $blk++) {
        # lit_len (varint)
        [int]$litLen = 0
        [int]$sh = 0
        while ($true) {
            [int]$b = $raw[$hPos++]
            $litLen = $litLen -bor (($b -band 0x7F) -shl $sh)
            if (($b -band 0x80) -eq 0) { break }
            $sh += 7
        }

        # shift_delta (svarint)
        [int]$u = 0
        $sh = 0
        while ($true) {
            [int]$b = $raw[$hPos++]
            $u = $u -bor (($b -band 0x7F) -shl $sh)
            if (($b -band 0x80) -eq 0) { break }
            $sh += 7
        }
        [int]$shiftDelta = if (($u -band 1) -ne 0) { -(($u + 1) -shr 1) } else { $u -shr 1 }

        # copy_len (varint)
        [int]$copyLen = 0
        $sh = 0
        while ($true) {
            [int]$b = $raw[$hPos++]
            $copyLen = $copyLen -bor (($b -band 0x7F) -shl $sh)
            if (($b -band 0x80) -eq 0) { break }
            $sh += 7
        }

        # sub_cnt (varint)
        [int]$subCnt = 0
        $sh = 0
        while ($true) {
            [int]$b = $raw[$hPos++]
            $subCnt = $subCnt -bor (($b -band 0x7F) -shl $sh)
            if (($b -band 0x80) -eq 0) { break }
            $sh += 7
        }

        if ($litLen -gt 0) {
            [Array]::Copy($raw, $lPos, $neu, $dst, $litLen)
            $dst += $litLen
            $lPos += $litLen
        }

        [int]$src = $lastSrcEnd + $litLen + $shiftDelta
        [Array]::Copy($orig, $src, $neu, $dst, $copyLen)

        [int]$cur = $dst
        for ([int]$sr = 0; $sr -lt $subCnt; $sr++) {
            [int]$tag = $raw[$sPos++]
            [int]$exLen = 0
            [int]$adLen = 0
            if ($tag -ge 64) {
                $adLen = $tag -shr 6
                $exLen = $tag -band 0x3F
            } elseif ($tag -ge 32) {
                $adLen = 4
                $exLen = $tag -band 0x1F
            } elseif ($tag -ge 1) {
                $adLen = $tag
                $sh = 0
                while ($true) {
                    [int]$b = $raw[$sPos++]
                    $exLen = $exLen -bor (($b -band 0x7F) -shl $sh)
                    if (($b -band 0x80) -eq 0) { break }
                    $sh += 7
                }
            } else {
                $sh = 0
                while ($true) {
                    [int]$b = $raw[$sPos++]
                    $exLen = $exLen -bor (($b -band 0x7F) -shl $sh)
                    if (($b -band 0x80) -eq 0) { break }
                    $sh += 7
                }
                $sh = 0
                while ($true) {
                    [int]$b = $raw[$sPos++]
                    $adLen = $adLen -bor (($b -band 0x7F) -shl $sh)
                    if (($b -band 0x80) -eq 0) { break }
                    $sh += 7
                }
            }

            $cur += $exLen
            for ([int]$k = 0; $k -lt $adLen; $k++) {
                $neu[$cur] = [byte](([int]$neu[$cur] + [int]$raw[$aPos]) -band 0xFF)
                $cur++
                $aPos++
            }
        }

        $dst += $copyLen
        $lastSrcEnd = $src + $copyLen
    }

    if ($dst -lt $zielGroesse) {
        [int]$rem = $zielGroesse - $dst
        [Array]::Copy($raw, $lPos, $neu, $dst, $rem)
        $lPos += $rem
    }

    $istMd5 = Hole-MD5 $neu
    if ($neu.Length -ne $zielGroesse -or $istMd5 -ne $sollMd5) {
        Write-Host ""
        Write-Host "FEHLER: Pruefsummenfehler nach dem Patchen von $(Split-Path -Leaf $zielPfad)!" -ForegroundColor Red
        Write-Host "  Ergebnis: $($neu.Length) Bytes, MD5 $istMd5"
        Write-Host "  Erwartet: $zielGroesse Bytes, MD5 $sollMd5"
        Write-Host "Abbruch: Die erzeugte Zieldatei stimmt nicht bitgenau ueberein." -ForegroundColor Red
        return $false
    }

    $zielOrdner = Split-Path -Parent $zielPfad
    if (-not (Test-Path $zielOrdner)) {
        New-Item -ItemType Directory -Path $zielOrdner | Out-Null
    }
    [System.IO.File]::WriteAllBytes($zielPfad, $neu)
    $dateiName = Split-Path -Leaf $zielPfad
    Write-Host "  [OK] $dateiName erzeugt ($($neu.Length) Bytes, MD5 $istMd5)" -ForegroundColor Green
    return $true
}

$origPfad = Join-Path $Spiel $Name
if (-not (Test-Path $origPfad)) {
    Write-Host "FEHLER: '$origPfad' nicht gefunden!" -ForegroundColor Red
    Write-Host "Abbruch: Bitte den Hauptordner der deutschen GOG-Installation waehlen." -ForegroundColor Red
    exit 1
}

$origBytes = [System.IO.File]::ReadAllBytes($origPfad)
$origMd5 = Hole-MD5 $origBytes
Write-Host "Originaldatei: $origPfad"
Write-Host "  Groesse: $($origBytes.Length) Bytes, MD5: $origMd5"

if ($origBytes.Length -ne $ErwOrigGroesse -or $origMd5 -ne $ErwOrigMd5) {
    Write-Host ""
    Write-Host "FEHLER: Deine '$Name' passt nicht zur erwarteten deutschen GOG-Originalversion (V1.12)!" -ForegroundColor Red
    Write-Host "  Gefunden: $($origBytes.Length) Bytes, MD5 $origMd5"
    Write-Host "  Erwartet: $ErwOrigGroesse Bytes, MD5 $ErwOrigMd5"
    Write-Host "Abbruch: Bitte die unveraenderte deutsche Original-RIVA.EXE (Version 1.12) verwenden." -ForegroundColor Red
    exit 1
}

Write-Host ""

$patchOrdner = $PSScriptRoot
$patches = @(Get-ChildItem -Path $patchOrdner -Filter "*.ndp" | Sort-Object Name)
if ($patches.Count -eq 0) {
    Write-Host "FEHLER: In '$patchOrdner' wurden keine .ndp-Patchdateien gefunden!" -ForegroundColor Red
    exit 1
}

foreach ($patch in $patches) {
    $zielName = [System.IO.Path]::GetFileNameWithoutExtension($patch.Name) + ".EXE"
    $zielPfad = Join-Path $Ziel $zielName
    $ok = Wende-Patch-An $origBytes $origMd5 $patch.FullName $zielPfad
    if (-not $ok) {
        exit 1
    }
}
