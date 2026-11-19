@echo off
setlocal
if not defined PORT_EXE_NAME set "PORT_EXE_NAME=RIVA_PORT.EXE"
call "%~dp0Riva_starten_WICHTIGE_FIXES.bat" %*
endlocal
