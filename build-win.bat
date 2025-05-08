@echo off
setlocal enabledelayedexpansion

:: === Paths ===
set SRC_DIR=src
set BUILD_DIR=..\\build\\win
set INCLUDE_DIRS=-ID:\Developement\TestGame1\SandboxGame\headers -ID:\Developement\TestGame1\SandboxGame\headers\imgui -IC:\sdl2\include\SDL2
set LIB_DIRS=-LC:\sdl2\lib
set LIBS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
set CXXFLAGS=-g -ggdb -c

:: === Create build directory ===
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

:: === Clean and copy resources ===
if exist "%BUILD_DIR%\res" (
    echo Deleting old res folder...
    rmdir /S /Q "%BUILD_DIR%\res"
)
echo Copying res folder...
xcopy /E /I "res" "%BUILD_DIR%\res"

:: === Clean old .o and .done files ===
del /Q "%BUILD_DIR%\*.o" >nul 2>&1
del /Q "%BUILD_DIR%\*.done" >nul 2>&1

:: === Compile all .cpp files in parallel with tracking ===
echo Compiling sources in parallel...
set OBJ_FILES=
for /R "%SRC_DIR%" %%F in (*.cpp) do (
    set "SRC_FILE=%%F"
    set "OBJ_FILE=%%~nF.o"
    set "DONE_FILE=%%~nF.done"

    echo Starting compilation for %%F...
    start /b cmd /c "g++ %CXXFLAGS% %INCLUDE_DIRS% "%%F" -o "%BUILD_DIR%\%%~nF.o" && echo done > "%BUILD_DIR%\%%~nF.done""
    set OBJ_FILES=!OBJ_FILES! "%BUILD_DIR%\%%~nF.o"
)

:: === Wait for all compilation tasks to finish ===
echo Waiting for compilation to complete...
:wait_loop
set ALL_DONE=true
for /R "%SRC_DIR%" %%F in (*.cpp) do (
    if not exist "%BUILD_DIR%\%%~nF.done" (
        set ALL_DONE=false
    )
)
if "!ALL_DONE!" == "false" (
    timeout /t 1 >nul
    goto wait_loop
)

:: === Link all object files ===
echo Linking...
g++ %OBJ_FILES% -o "%BUILD_DIR%\main.exe" %LIB_DIRS% %LIBS%

:: === Run ===
echo Launching application...
start /d "%BUILD_DIR%" main.exe
