@echo off
REM Startet das frisch aus unserem C++-Quelltext gebaute RIVA.EXE in DOSBox.
REM Das Original-RIVA.EXE im GOG-Ordner wird dabei NICHT benutzt -
REM es kommt nur die selbst kompilierte EXE aus Build\ zum Einsatz!
REM Der GOG-Ordner wird nicht veraendert; Spielstaende landen in Build\Testspielstaende.

setlocal
call "%~dp0SPIELPFAD_SUCHEN.cmd"
if not defined SPIEL (
    pause
    exit /b 1
)
set "GOG=%SPIEL%"
set "VSTORE=%LOCALAPPDATA%\VirtualStore\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania 3"
set "BUILD=%~dp0Build"
set "SAVES=%BUILD%\Testspielstaende"
set "CONF=%BUILD%\dosbox_test.conf"

if not exist "%BUILD%\RIVA.EXE" (
    echo FEHLER: "%BUILD%\RIVA.EXE" fehlt.
    echo Bitte zuerst Bauen\BAUEN.bat ausfuehren!
    pause
    exit /b 1
)

echo Bereite Spielumgebung in "%SAVES%" vor (GOG-Ordner bleibt unangetastet)...
if not exist "%SAVES%" (
    echo Erster Start: kopiere Spieldateien nach "%SAVES%" ^(dauert ca. 10 Sekunden^)...
)
REM Spieldateien aus GOG holen (ohne DOSBOX/MUSIC/cloud_saves und ohne Original-RIVA.EXE); bereits Geaendertes in SAVES nicht ueberschreiben
robocopy "%GOG%" "%SAVES%" /E /XD DOSBOX MUSIC cloud_saves __support /XF RIVA.EXE RIVA.OG webcache.zip /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
REM Vorhandene Spielstaende aus GOG\cloud_saves oder Windows-VirtualStore uebernehmen, ohne neuere Test-Spielstaende zu ueberschreiben
if exist "%GOG%\cloud_saves" (
    robocopy "%GOG%\cloud_saves" "%SAVES%" /E /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
)
if exist "%VSTORE%" (
    robocopy "%VSTORE%" "%SAVES%" /E /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
)

REM DOSBox kann keine Umlaute im Pfad (z. B. "Schatten ueber Riva") - darum die kurze DOS-Form (8.3) verwenden
for %%I in ("%SAVES%") do set "SAVES_D=%%~sI"
for %%I in ("%BUILD%") do set "E_D=%%~sI"
> "%CONF%" echo [autoexec]
>>"%CONF%" echo @echo off
>>"%CONF%" echo mount C "%SAVES_D%"
if exist "%GOG%\game.ins" >>"%CONF%" echo imgmount D "%GOG%\game.ins" -t iso
>>"%CONF%" echo mount E "%E_D%"
>>"%CONF%" echo C:
>>"%CONF%" echo cls
>>"%CONF%" echo echo ==================================================================
>>"%CONF%" echo echo   Starte NEU KOMPILIERTES E:\RIVA.EXE (aus C++-Quelltext gebaut)
>>"%CONF%" echo echo   Spielstaende liegen in Build\Testspielstaende
>>"%CONF%" echo echo ==================================================================
>>"%CONF%" echo E:\RIVA.EXE
>>"%CONF%" echo exit

echo Starte DOSBox mit "%BUILD%\RIVA.EXE" ...
cd /d "%GOG%\DOSBOX"
if exist "..\dosbox_realms3.conf" start "" DOSBox.exe -conf "..\dosbox_realms3.conf" -conf "%CONF%" -noconsole
if not exist "..\dosbox_realms3.conf" start "" DOSBox.exe -conf "%CONF%" -noconsole
