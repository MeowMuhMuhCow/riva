@echo off
setlocal
chcp 65001 >nul 2>&1

echo ============================================================================
echo   DSA 3: Schatten ueber Riva - Fehlerbereinigte EXE erzeugen (ohne Compiler)
echo ============================================================================
echo.

set "SPIEL="
if not "%~1"=="" (
    if exist "%~1\RIVA.EXE" (
        set "SPIEL=%~1"
    )
)
if not defined SPIEL (
    if exist "%~dp0Original\RIVA.EXE" (
        set "SPIEL=%~dp0Original"
    )
)
if not defined SPIEL (
    call "%~dp0SPIELPFAD_SUCHEN.cmd"
)
if not defined SPIEL (
    echo.
    pause
    exit /b 1
)

if not exist "%SPIEL%\RIVA.EXE" (
    echo FEHLER: "%SPIEL%\RIVA.EXE" nicht gefunden.
    echo Bitte den Hauptordner der deutschen GOG-Installation waehlen.
    del "%~dp0SPIELPFAD.txt" >nul 2>&1
    pause
    exit /b 1
)

powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0Patch\patchen.ps1" -Spiel "%SPIEL%" -Name RIVA.EXE -Ziel "%~dp0Build"
if errorlevel 1 (
    echo.
    pause
    exit /b 1
)

echo.
echo ============================================================================
echo   Fertig! Du kannst das Spiel jetzt direkt starten ueber:
echo.
echo     RIVA_FIX_WICHTIG_STARTEN.bat   (empfohlen: sichere Korrekturen, Stufe A)
echo     RIVA_FIX_ALLES_STARTEN.bat     (alle Korrekturen, Stufe B)
echo.
echo   Deine Original-Installation wurde NICHT veraendert.
echo ============================================================================
echo.
pause
