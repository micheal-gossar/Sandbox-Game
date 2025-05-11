// sprite.cpp

#include "../headers/sprite.h"
#include <SDL.h>

// Constructor
Sprite::Sprite(float startX, float startY, int spriteWidth, int spriteHeight, float startSpeed)
    : x(startX), y(startY), width(spriteWidth), height(spriteHeight), speed(startSpeed) {}

// Update method to move the sprite based on its speed and deltaTime
void Sprite::Update(float deltaTime) {
    // Move the sprite by 'speed' pixels per second
    x += speed * deltaTime;
}

// Draw method to render the sprite to the screen
void Sprite::Draw(SDL_Renderer* renderer, SDL_Texture* texture) {
    SDL_Rect srcRect = { 0, 0, width, height };  // Source rectangle for sprite (can be modified for sprite sheet)
    SDL_Rect destRect = { static_cast<int>(x), static_cast<int>(y), width, height };  // Destination rectangle

    // Copy the texture to the renderer with the srcRect and destRect
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
