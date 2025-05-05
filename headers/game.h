#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../headers/imgui/imgui.h"
#include "../headers/imgui/imgui_impl_sdl2.h"
#include "../headers/imgui/imgui_impl_sdlrenderer2.h"
#include "../headers/imgui/imgui_stdlib.h"

class Game {
public:
SDL_Window *window;
SDL_Renderer *renderer;
float imcolor[4] = { (float)0 / 255, (float)255 / 255, (float)64 / 255, (float)64 / 255 };
// Screen dimension constants


int Setup();
int Run();
int Exit();
int ImGuiSetup();


};
#endif