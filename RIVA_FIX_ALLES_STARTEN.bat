@echo off
REM Startet die fehlerbereinigte RIVA_FIX_ALLES.EXE (Stufe B: alle Fixes) in DOSBox.
REM Der GOG-Ordner wird nicht veraendert; Spielstaende landen in Build\Testspielstaende_Fix_Alles.
REM Mit "set PROBENLOG=1" vor dem Aufruf (oder ueber RIVA_FIX_ALLES_MIT_PROBENLOG_STARTEN.bat)
REM wird nebenbei ein Live-Fenster geoeffnet, das alle Talent-, Zauber-, Attribut- und
REM Kampfproben mit Wuerfeln anzeigt.

setlocal
call "%~dp0SPIELPFAD_SUCHEN.cmd"
if not defined SPIEL (
    pause
    exit /b 1
)
set "GOG=%SPIEL%"
set "VSTORE=%LOCALAPPDATA%\VirtualStore\Program Files (x86)\GOG Galaxy\Games\Realms of Arkania 3"
set "BUILD=%~dp0Build"
set "RUNDIR=%BUILD%\Fix_Alles"
set "SAVES=%BUILD%\Testspielstaende_Fix_Alles"
set "CONF=%BUILD%\dosbox_fix_alles.conf"

if not exist "%BUILD%\RIVA_FIX_ALLES.EXE" (
    echo FEHLER: "%BUILD%\RIVA_FIX_ALLES.EXE" fehlt.
    echo Bitte zuerst PATCHEN.bat ^(ohne Compiler^) oder "Bauen\BAUEN.bat alles" ausfuehren!
    pause
    exit /b 1
)

if not exist "%RUNDIR%" mkdir "%RUNDIR%"
copy /y "%BUILD%\RIVA_FIX_ALLES.EXE" "%RUNDIR%\RIVA.EXE" >nul

echo Bereite Spielumgebung in "%SAVES%" vor (GOG-Ordner bleibt unangetastet)...
if not exist "%SAVES%" (
    echo Erster Start: kopiere Spieldateien nach "%SAVES%" ^(dauert ca. 10 Sekunden^)...
)
robocopy "%GOG%" "%SAVES%" /E /XD DOSBOX MUSIC cloud_saves __support /XF RIVA.EXE RIVA.OG webcache.zip /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
if exist "%GOG%\cloud_saves" (
    robocopy "%GOG%\cloud_saves" "%SAVES%" /E /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
)
if exist "%VSTORE%" (
    robocopy "%VSTORE%" "%SAVES%" /E /XC /XN /XO /NFL /NDL /NJH /NJS /NP >nul
)

if "%PROBENLOG%"=="1" (
    if exist "%SAVES%\PROBEN.CSV" del /q "%SAVES%\PROBEN.CSV"
    echo Starte Probenlog-Live-Fenster...
    start "DSA Probenlog" powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0Probenlog\probenlog_fenster.ps1" "%SAVES%\PROBEN.CSV"
)

REM DOSBox kann keine Umlaute im Pfad (z. B. "Schatten ueber Riva") - darum die kurze DOS-Form (8.3) verwenden
for %%I in ("%SAVES%") do set "SAVES_D=%%~sI"
for %%I in ("%RUNDIR%") do set "E_D=%%~sI"
> "%CONF%" echo [autoexec]
>>"%CONF%" echo @echo off
>>"%CONF%" echo mount C "%SAVES_D%"
if exist "%GOG%\game.ins" >>"%CONF%" echo imgmount D "%GOG%\game.ins" -t iso
>>"%CONF%" echo mount E "%E_D%"
>>"%CONF%" echo C:
>>"%CONF%" echo cls
>>"%CONF%" echo echo ==================================================================
>>"%CONF%" echo echo   Starte RIVA_FIX_ALLES.EXE (Stufe B: alle Bugfixes)
>>"%CONF%" echo echo   Spielstaende liegen in Build\Testspielstaende_Fix_Alles
>>"%CONF%" echo echo ==================================================================
>>"%CONF%" echo E:\RIVA.EXE
>>"%CONF%" echo exit

echo Starte DOSBox mit "%BUILD%\RIVA_FIX_ALLES.EXE" ...
cd /d "%GOG%\DOSBOX"
if exist "..\dosbox_realms3.conf" start "" DOSBox.exe -conf "..\dosbox_realms3.conf" -conf "%CONF%" -noconsole
if not exist "..\dosbox_realms3.conf" start "" DOSBox.exe -conf "%CONF%" -noconsole
