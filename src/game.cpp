#include "game.h"

int Game::Setup() {
return 0;
}

int Game::Run() {
Setup();
if (sdl_utils_Init("SDL Tutorial", &this->window, &this->renderer, 0)) {
    SDL_Texture* texture = IMG_LoadTexture(this->renderer, "../res/characters.png");
    
    // Sprite source rectangle
    SDL_Rect srcRect = {9, 42, 15, 21};
    // Target rectangle (note that we will paint it at x4 its original size)
    SDL_Rect destRect = {0, 0, srcRect.w * 4, srcRect.h * 4};
    while (1) {
        SDL_RenderClear(this->renderer);
        SDL_RenderCopy(this->renderer, texture, &srcRect, &destRect);
        SDL_RenderPresent(this->renderer);

        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) break;
        } 
    }

    SDL_DestroyTexture(texture);		
}
Exit();
return 0;
}

int Game::Exit() {
    sdl_utils_Quit(this->window, this->renderer);
    return 0;
}