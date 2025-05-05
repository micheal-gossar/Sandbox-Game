@echo off
mkdir "../build/win" 2>NUL
xcopy /E /I "res" "../build/win/res"
g++  src/imgui/imgui_draw.cpp src/imgui/imgui_impl_sdl2.cpp src/imgui/imgui_stdlib.cpp src/imgui/imgui_tables.cpp src/imgui/imgui_widgets.cpp src/imgui/imgui.cpp src/main.cpp src/game.cpp -ID:/Developement/TestGame1/SandboxGame/headers -ID:/Developement/TestGame1/SandboxGame/headers/imgui -IC:\sdl2\include\SDL2 -LC:\sdl2\lib -g -ggdb -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o ../build/win/main

start /d "D:\Developement\TestGame1\build\win" main.exe