#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>

// The Sprite class represents a 2D sprite, with position, size, and speed.
class Sprite {
public:
    // Constructor to initialize the sprite with optional parameters for position, size, and speed
    Sprite(float startX = 0.0f, float startY = 0.0f, int spriteWidth = 32, int spriteHeight = 32, float startSpeed = 1.0f);

    // Update the sprite's position based on its speed and the time elapsed (deltaTime)
    void Update(float deltaTime);

    // Draw the sprite to the screen at its current position
    void Draw(SDL_Renderer* renderer, SDL_Texture* texture);

private:
    // Position of the sprite
    float x, y;

    // Size of the sprite
    int width, height;

    // Speed of the sprite
    float speed;
};

#endif // SPRITE_H
