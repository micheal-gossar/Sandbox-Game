#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "sdl_utils.h"


class Game {
public:
SDL_Window *window;
SDL_Renderer *renderer;
// Screen dimension constants


int Setup();
int Run();
int Exit();
private:
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const int BG_R = 128;
const int BG_G = 153;
const int BG_B = 151;
};
#endif