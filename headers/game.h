#ifndef GAME_H
#define GAME_H
#include "../headers/imgui/imgui.h"
#include "../headers/imgui/imgui_impl_sdl2.h"
#include "../headers/imgui/imgui_impl_sdlrenderer2.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "../headers/textureID.h"
#include "../headers/sprite.h"
#include "../headers/textureManager.h"

class Game {
public:
SDL_Window *window;
SDL_Renderer *renderer;
float imcolor[4] = { (float)0 / 255, (float)255 / 255, (float)64 / 255, (float)64 / 255 };
// Screen dimension constants
textureID testImage = textureID(1, 0, 1);
Sprite<int>* player = nullptr;

int Setup();
int Run();
int Exit();


};
#endif