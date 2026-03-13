@echo off
setlocal enabledelayedexpansion

:: 1. Preparar carpetas
if not exist build mkdir build
if not exist build\obj mkdir build\obj

echo --- COMPILANDO OBJETOS ---

:: 2. Compilar cada .c a un archivo .o (objeto) individualmente
for /R %%f in (*.c) do (
    echo Compilando: %%~nxf
    "C:\Program Files\GBDK\bin\lcc.exe" -debug -c -o "build\obj\%%~nf.o" "%%f"
)

echo.
echo --- LINKEANDO ROM ---

"C:\Users\Bau_M\OneDrive\Desktop\GameDev\Gameboy\Config\rgbds\rgbasm.exe" -DGBDK -o build/obj/hUGEDriver.obj -i include/huge/ include/huge/hUGEDriver.asm
python "C:\Users\Bau_M\OneDrive\Desktop\GameDev\Gameboy\dmg-day\tools\rgb2sdas.py" -o build/obj/hUGEDriver.o build/obj/hUGEDriver.obj

:: 3. Crear la lista de objetos generados
set OBJS=
for %%g in (build\obj\*.o) do (
    set OBJS=!OBJS! "%%g"
)

:: 4. Linkeo final (aca es mucho mas dificil superar el limite de caracteres)
"C:\Program Files\GBDK\bin\lcc.exe" -debug -Wl-yt1 -Wl-yo8 -o build/game.gb !OBJS!

if %errorlevel% equ 0 (
    echo.
    echo [OK] ROM generada con exito en build/game.gb
) else (
    echo.
    echo [ERROR] El linkeo fallo.
    pause
)