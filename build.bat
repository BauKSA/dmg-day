@echo off
setlocal enabledelayedexpansion

set LOG_FILE=build\logs.txt
if not exist build mkdir build
if not exist build\obj mkdir build\obj
if exist %LOG_FILE% del %LOG_FILE%

echo --- COMPILANDO OBJETOS ---
:: Compilamos y guardamos salida en el log
(
    for /R %%f in (*.c) do (
        echo Compilando: %%~nxf
        "C:\Program Files\GBDK\bin\lcc.exe" -debug -c -o "build\obj\%%~nf.o" "%%f"
    )
) >> %LOG_FILE% 2>&1

echo --- GENERANDO LISTA DE OBJETOS ---
set OBJS=
for %%g in (build\obj\*.o) do (
    set OBJS=!OBJS! "%%g"
)

echo --- LINKEANDO ROM ---
:: Ejecutamos el linkeo FUERA del bloque de paréntesis para capturar el error real
"C:\Program Files\GBDK\bin\lcc.exe" -debug -Wl-yt1 -Wl-yo8 -o "build\game.gb" %OBJS%

if %errorlevel% equ 0 (
    echo.
    echo [OK] ROM generada con exito en build\game.gb
) else (
    echo.
    echo [ERROR] El linker fallo con codigo %errorlevel%.
    echo Revisa %LOG_FILE% o los mensajes arriba.
    pause
)