@echo off
rem ===========================================================================
rem  Riva_starten_ALLE_FIXES_MIT_PROBENLOG.bat - wie
rem  Riva_starten_ALLE_FIXES.bat, dazu das Live-Probenlog:
rem  jede Probe (Eigenschaft, Talent, Zauber, Attacke, Parade, Fernkampf)
rem  erscheint live in einem zweiten Fenster und wird in PROBEN.CSV
rem  im Spielordner (bzw. bei Schreibschutz in Spielstaende\PROBEN.CSV)
rem  mitgeschrieben. Alte Logs wandern mit Datum nach Probenlogs\.
rem  Hinterher ansehen: Probenlog\Probenlog_Riva.html
rem ===========================================================================
setlocal
set "PROBENLOG=1"
set "PORT_EXE_NAME=RIVA_PORT_ALLES.EXE"
call "%~dp0Riva_starten_WICHTIGE_FIXES.bat" %*
endlocal
