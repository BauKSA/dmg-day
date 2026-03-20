@echo off
setlocal enabledelayedexpansion

:: Definimos la ruta del log para no repetirla
set LOG_FILE=build\logs.txt

:: 1. Preparar carpetas (esto lo dejamos fuera del log o lo incluimos, según prefieras)
if not exist build mkdir build
if not exist build\obj mkdir build\obj

:: Borramos el log anterior si existe para empezar de cero
if exist %LOG_FILE% del %LOG_FILE%

:: --- INICIO DEL BLOQUE DE LOG ---
(
    echo --- COMPILANDO OBJETOS ---

    :: 2. Compilar cada .c
    for /R %%f in (*.c) do (
        echo Compilando: %%~nxf
        "C:\Program Files\GBDK\bin\lcc.exe" -debug -c -o "build\obj\%%~nf.o" "%%f"
    )

    echo.
    echo --- LINKEANDO ROM ---

    ::"C:\Users\Bau_M\OneDrive\Desktop\GameDev\Gameboy\Config\rgbds\rgbasm.exe" -DGBDK -o build/obj/hUGEDriver.obj -i include/huge/ include/huge/hUGEDriver.asm
    ::python "C:\Users\Bau_M\OneDrive\Desktop\GameDev\Gameboy\dmg-day\tools\rgb2sdas.py" -o build/obj/hUGEDriver.o build/obj/hUGEDriver.obj

    :: 3. Crear la lista de objetos
    set OBJS=
    for %%g in (build\obj\*.o) do (
        set OBJS=!OBJS! "%%g"
    )

    :: 4. Linkeo final
    "C:\Program Files\GBDK\bin\lcc.exe" -debug -Wl-yt1 -Wl-yo8 -o build/game.gb !OBJS!

) > %LOG_FILE% 2>&1
:: --- FIN DEL BLOQUE DE LOG ---

:: Verificación de errores (queda fuera del bloque para que lo veas en la consola real)
if %errorlevel% equ 0 (
    echo.
    echo [OK] ROM generada con exito. Revisa %LOG_FILE% para detalles.
) else (
    echo.
    echo [ERROR] El proceso fallo. Revisa %LOG_FILE% para ver los errores de lcc o python.
    pause
)