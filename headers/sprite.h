#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "textureID.h"
#include "textureManager.h"

template <class T>
class Sprite {
public:
    Sprite(SDL_Renderer* renderer, const textureID& texID)
        : textureIDValue(texID)
    {
        texture = TextureManager::Get(texID);
    }

    void Draw(SDL_Renderer* renderer, int x, int y) {
        if (!texture) return;

        SDL_Rect dst = { x, y, width, height };
        SDL_RenderCopy(renderer, texture, nullptr, &dst);
    }

    void SetSize(int w, int h) {
        width = w;
        height = h;
    }

private:
    textureID textureIDValue;
    SDL_Texture* texture = nullptr;
    int width = 64;
    int height = 64;
};


#endif
