@echo off
setlocal enabledelayedexpansion

:: 1. Definir rutas absolutas para que no se pierda al cambiar de carpeta
set GBDK_LCC="C:\Program Files\GBDK\bin\lcc.exe"
set PROJECT_DIR=%~dp0
set OBJ_DIR=%PROJECT_DIR%build\obj
set ROM_OUT=%PROJECT_DIR%build\game.gb

:: 2. Limpieza y preparación
if exist build rmdir /s /q build
mkdir build\obj

echo [1/3] Compilando cada archivo .c...
for /R %%f in (*.c) do (
    echo Compilando: %%~nxf
    %GBDK_LCC% -debug -c -o "build\obj\%%~nf.o" "%%f"
)

echo [2/3] Entrando a la carpeta de objetos para acortar la ruta...
pushd "%OBJ_DIR%"

:: 3. Generar la lista de objetos con rutas relativas (cortitas)
set REL_OBJS=
for %%g in (*.o) do (
    set REL_OBJS=!REL_OBJS! %%g
)

echo [3/3] Linkeando ROM desde build\obj...
%GBDK_LCC% -debug -Wl-yt1 -Wl-yo8 -o "%ROM_OUT%" !REL_OBJS!

:: 4. Volver a la carpeta original
popd

if exist "build\game.gb" (
    echo.
    echo === EXITO: ROM GENERADA EN build\game.gb ===
) else (
    echo.
    echo === FALLO: El linker no pudo crear la ROM ===
    pause
)