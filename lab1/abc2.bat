@echo off
copy nul klm.klm && (for %%i in (d:\lab1\adas.txt) do (for /l %%j in (1,1,%%~zi) do (
echo:>>klm.klm))) && fc /b d:\lab1\adas.txt klm.klm | find /c ": 41" && del klm.klm
pause