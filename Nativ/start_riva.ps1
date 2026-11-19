param(
    [ValidateSet("wichtig", "original", "alles")]
    [string]$Variante = "wichtig",
    [string]$Spielpfad = "",
    [switch]$KeinIntro,
    [switch]$Probenlog
)

$ErrorActionPreference = "Stop"
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$bat = switch ($Variante) {
    "original" { "Riva_starten_ORIGINAL.bat" }
    "alles"    { if ($Probenlog) { "Riva_starten_ALLE_FIXES_MIT_PROBENLOG.bat" } else { "Riva_starten_ALLE_FIXES.bat" } }
    default    { if ($Probenlog) { "Riva_starten_WICHTIGE_FIXES_MIT_PROBENLOG.bat" } else { "Riva_starten_WICHTIGE_FIXES.bat" } }
}

$argList = @("/c", "`"$(Join-Path $here $bat)`"")
if ($KeinIntro) { $argList += "--kein-intro" }
if ($Spielpfad -ne "") { $argList += "`"$Spielpfad`"" }

$p = Start-Process -FilePath "cmd.exe" -ArgumentList ($argList -join " ") -WorkingDirectory $here -Wait -PassThru -NoNewWindow
exit $p.ExitCode
