@echo off
REM Sucht den Installationsordner von DSA 3 - Schatten ueber Riva (GOG)
REM und legt ihn in der Umgebungsvariable SPIEL ab.
REM Merkt sich die Auswahl in SPIELPFAD.txt neben diesem Skript.

set "SPIEL="
set "MERKDATEI=%~dp0SPIELPFAD.txt"

REM 1. Gespeicherten Pfad pruefen
if exist "%MERKDATEI%" (
    set /p GESP=<"%MERKDATEI%"
    call :pruefe "%GESP%"
    if defined SPIEL goto :eof
)

REM 2. Typische GOG-Pfade durchprobieren
for %%P in (
    "%ProgramFiles(x86)%\GOG Galaxy\Games\Realms of Arkania 3"
    "%ProgramFiles%\GOG Galaxy\Games\Realms of Arkania 3"
    "C:\GOG Games\Realms of Arkania 3"
    "D:\GOG Games\Realms of Arkania 3"
    "%ProgramFiles(x86)%\GOG Galaxy\Games\Realms of Arkania - Shadows over Riva"
    "%ProgramFiles%\GOG Galaxy\Games\Realms of Arkania - Shadows over Riva"
    "C:\GOG Games\Realms of Arkania - Shadows over Riva"
    "D:\GOG Games\Realms of Arkania - Shadows over Riva"
) do (
    if not defined SPIEL call :pruefe "%%~P"
)
if defined SPIEL goto :speichern

REM 3. Nicht automatisch gefunden -> Ordner-Auswahldialog oeffnen
echo.
echo Der Installationsordner von "Schatten ueber Riva" (GOG) wurde nicht
echo automatisch an den ueblichen Stellen gefunden.
echo Bitte im folgenden Fenster den Spielordner auswaehlen
echo (dort liegen RIVA.EXE und der Unterordner DOSBOX).
echo.

for /f "usebackq delims=" %%I in (`powershell -NoProfile -STA -Command ^
    "Add-Type -AssemblyName System.Windows.Forms;" ^
    "$d = New-Object System.Windows.Forms.FolderBrowserDialog;" ^
    "$d.Description = 'Bitte den Ordner von DSA 3 - Schatten ueber Riva (GOG) auswaehlen (enthaelt RIVA.EXE und DOSBOX)';" ^
    "$d.ShowNewFolderButton = $false;" ^
    "if ($d.ShowDialog() -eq 'OK') { [Console]::Out.WriteLine($d.SelectedPath) }"`) do (
    set "WAHL=%%I"
)

if not defined WAHL (
    echo Auswahl abgebrochen.
    goto :eof
)

REM Falls der Benutzer versehentlich den Unterordner DOSBOX gewaehlt hat, eine Ebene hoch
if exist "%WAHL%\DOSBox.exe" (
    for %%U in ("%WAHL%\..") do set "WAHL=%%~fU"
)

call :pruefe "%WAHL%"
if not defined SPIEL (
    echo.
    echo In "%WAHL%" wurde kein DOSBOX\DOSBox.exe gefunden.
    echo Bitte beim naechsten Start den Hauptordner der GOG-Installation waehlen.
    goto :eof
)

:speichern
>"%MERKDATEI%" echo %SPIEL%
goto :eof

:pruefe
if "%~1"=="" goto :eof
if exist "%~1\DOSBOX\DOSBox.exe" (
    set "SPIEL=%~1"
)
goto :eof
