# Startet genau eine Windows-EXE, wartet, beendet bei Zeitlimit nur diese PID.
# Kein tasklist.exe, kein taskkill.exe, kein FreeConsole.
param(
    [Parameter(Mandatory = $true)][string]$Exe,
    [int]$Seconds = 180,
    [string]$WorkDir = "",
    [Parameter(ValueFromRemainingArguments = $true)][string[]]$GameArgs
)
$ErrorActionPreference = "Stop"
if (-not $WorkDir) { $WorkDir = Split-Path -Parent $Exe }
$quoted = foreach ($a in $GameArgs) {
    if ($a -match '[\s"]') { '"' + ($a -replace '"', '\"') + '"' } else { $a }
}
$si = New-Object System.Diagnostics.ProcessStartInfo
$si.FileName = $Exe
$si.Arguments = ($quoted -join " ")
$si.UseShellExecute = $false
$si.CreateNoWindow = $true
$si.RedirectStandardInput = $true
$si.WorkingDirectory = $WorkDir
# WALKTO wartet dynamisch; sein Zeitbedarf fehlt in der statischen Replay-Zeitsumme.
# Den internen Schutz deshalb an das explizite, aeussere Testlimit binden.
$si.EnvironmentVariables["RIVA_WATCHDOG_MS"] = [string]([Math]::Max(1000, $Seconds * 1000 - 1000))
$si.EnvironmentVariables["RIVA_AUDIO_LOG"] = "1"
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $si
[void]$p.Start()
$p.StandardInput.Close()
if (-not $p.WaitForExit($Seconds * 1000)) {
    try { $p.Kill() } catch {}
    try { [void]$p.WaitForExit(4000) } catch {}
    Write-Output "TIMEOUT"
    exit 124
}
Write-Output ("EXIT " + $p.ExitCode)
exit $p.ExitCode
