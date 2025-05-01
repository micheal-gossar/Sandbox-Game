@echo off
mkdir "../build/win" 2>NUL
xcopy /E /I "res" "../build/win/res"
g++ src/main.cpp -ID:/Developement/TestGame1/SDL-VSCODE-C-CPP/headers -IC:\sdl2\include\SDL2 -LC:\sdl2\lib -g -ggdb -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o ../build/win/main

start /d "D:\Developement\TestGame1\build\win" main.exe