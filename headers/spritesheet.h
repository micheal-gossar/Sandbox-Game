#ifndef SPRITESHEET_H
#define SPRITESHEET_H
#include <SDL.h>
#include "textureID.h"
#include "sprite.h"
#include <vector>

class Spritesheet {
    Spritesheet(SDL_Surface s, int l, int nR, int nC, int pX, int pY, SDL_Renderer* r):
    spritesheet(s),layer(l),numOfRows(nR),numOfCollums(nC),pixelX(pX),pixelY(pY),renderer(r){

    };
    ~Spritesheet() {};

private:
std::vector<Sprite<int>> sprites;
    int numOfRows;
    int numOfCollums;
    int pixelX;
    int pixelY;
    int layer;
    SDL_Renderer* renderer;
    SDL_Surface spritesheet;
};
#endif