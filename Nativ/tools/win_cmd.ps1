# Ein gewarteter cmd.exe ohne eigenes Konsolenfenster.
# Aufruf aus WSL: powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File win_cmd.ps1 -CmdFile ... -WorkDir ...
param(
    [Parameter(Mandatory = $true)][string]$CmdFile,
    [string]$WorkDir = "C:\Windows\Temp\riva_port_build",
    [int]$Seconds = 180
)
$ErrorActionPreference = "Stop"
$cmd = [System.IO.File]::ReadAllText($CmdFile).Trim()
$mingw = "C:\Program Files (x86)\Embarcadero\Dev-Cpp\TDM-GCC-64\bin"
$env:PATH = $mingw + ";" + $env:PATH
$si = New-Object System.Diagnostics.ProcessStartInfo
$si.FileName = "cmd.exe"
$si.Arguments = "/d /s /c " + $cmd
$si.UseShellExecute = $false
$si.CreateNoWindow = $true
$si.RedirectStandardInput = $true
$si.WorkingDirectory = $WorkDir
$p = New-Object System.Diagnostics.Process
$p.StartInfo = $si
[void]$p.Start()
$p.StandardInput.Close()
if (-not $p.WaitForExit($Seconds * 1000)) {
    try { $p.Kill() } catch {}
    try { [void]$p.WaitForExit(4000) } catch {}
    Write-Output "COMPILER_TIMEOUT"
    exit 124
}
exit $p.ExitCode
