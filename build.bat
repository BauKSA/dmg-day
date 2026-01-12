@echo off
mkdir build
setlocal enabledelayedexpansion
set FILES=

:: Recorre toda la carpeta del proyecto recursivamente y toma todos los .c
for /R . %%f in (*.c) do (
    set FILES=!FILES! %%f
)

"C:\Program Files\GBDK\bin\lcc.exe" -debug -o build/game.gb !FILES!