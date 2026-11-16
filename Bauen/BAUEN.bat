@echo off
setlocal
chcp 65001 >nul 2>&1
cd /d "%~dp0"
title DSA 3: Schatten ueber Riva - Bau aus dem rekonstruierten C++-Quelltext %1

echo ============================================================================
echo   DSA 3: Schatten ueber Riva - Nachbau aus dem rekonstruierten C++-Quelltext
echo ============================================================================
echo.

REM --- Python 3 suchen (Bauen\python\python.exe, python, py -3) ---
set "PYTHON="
if exist "%~dp0python\python.exe" set "PYTHON="%~dp0python\python.exe""
if defined PYTHON goto :py_ok

where python >nul 2>&1
if not errorlevel 1 (
    python -c "import sys; sys.exit(0 if sys.version_info >= (3, 9) else 1)" >nul 2>&1
    if not errorlevel 1 set "PYTHON=python"
)
if defined PYTHON goto :py_ok

where py >nul 2>&1
if not errorlevel 1 (
    py -3 -c "import sys; sys.exit(0 if sys.version_info >= (3, 9) else 1)" >nul 2>&1
    if not errorlevel 1 set "PYTHON=py -3"
)
if defined PYTHON goto :py_ok

echo FEHLER: Python 3 wurde nicht gefunden.
echo Bitte Python 3 installieren ^(https://www.python.org/downloads/^)
echo und beim Setup den Haken bei "Add Python to PATH" setzen.
echo.
pause
exit /b 1
:py_ok

REM --- DOSBox suchen (fuer den Watcom-Linker WLINK 10.6) ---
set "DOSBOX="
if exist "%~dp0DOSBox\DOSBox.exe" set "DOSBOX=%~dp0DOSBox\DOSBox.exe"
if not defined DOSBOX (
    call "%~dp0..\SPIELPFAD_SUCHEN.cmd"
    if defined SPIEL (
        if exist "%SPIEL%\DOSBOX\DOSBox.exe" set "DOSBOX=%SPIEL%\DOSBOX\DOSBox.exe"
    )
)
if not defined DOSBOX (
    for %%p in (
        "%ProgramFiles(x86)%\GOG Galaxy\Games\Realms of Arkania 3\DOSBOX\DOSBox.exe"
        "%ProgramFiles%\GOG Galaxy\Games\Realms of Arkania 3\DOSBOX\DOSBox.exe"
        "C:\GOG Games\Realms of Arkania 3\DOSBOX\DOSBox.exe"
        "D:\GOG Games\Realms of Arkania 3\DOSBOX\DOSBox.exe"
        "%ProgramFiles(x86)%\DOSBox-0.74-3\DOSBox.exe"
        "%ProgramFiles%\DOSBox-0.74-3\DOSBox.exe"
    ) do (
        if not defined DOSBOX if exist "%%~p" set "DOSBOX=%%~p"
    )
)

REM --- Bauskript starten ---
if defined DOSBOX (
    %PYTHON% -X utf8 "%~dp0bauen.py" --dosbox "%DOSBOX%" %*
) else (
    %PYTHON% -X utf8 "%~dp0bauen.py" %*
)
set "RC=%ERRORLEVEL%"

echo.
if "%RC%"=="0" (
    if /i "%~1"=="wichtig" (
        echo Fertig! Fehlerbereinigte Stufe A: ..\Build\RIVA_FIX_WICHTIG.EXE
        echo Starten mit: RIVA_FIX_WICHTIG_STARTEN.bat
    ) else if /i "%~1"=="alles" (
        echo Fertig! Fehlerbereinigte Stufe B: ..\Build\RIVA_FIX_ALLES.EXE
        echo Starten mit: RIVA_FIX_ALLES_STARTEN.bat
    ) else (
        echo Fertig! Originalgetreue EXE: ..\Build\RIVA.EXE
        echo Starten mit: RIVA_STARTEN.bat
    )
) else (
    echo Bau fehlgeschlagen oder abgebrochen ^(Code %RC%^) - Protokoll: ..\Build\bau.log
)
echo.
pause
exit /b %RC%
