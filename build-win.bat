@echo off
setlocal

:: === Navigate to project root if not already ===
cd /d "%~dp0"

echo [1/4] Cleaning previous build...
make clean

echo [2/4] Building project...
make
IF %ERRORLEVEL% NEQ 0 (
    echo ❌ Build failed!
    pause
    exit /b 1
)

:: === Check if res/ exists and copy it ===
IF EXIST build\main.exe (
    echo [3/4] Copying resource folder to build...
    xcopy /E /I /Y res build\res >nul
)

echo [4/4] Opening build folder...
explorer build

echo ✅ Build completed successfully.
endlocal
pause
