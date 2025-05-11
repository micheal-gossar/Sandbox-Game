#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "textureManager.h"
#include "sprite.h"
#include "spritesheet.h"
#include "textureID.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"
#include "imgui/imgui.h"

class Game {
public:
    // Constructor
    Game(SDL_Renderer* renderer, SDL_Window* window);

    // Destructor
    ~Game();

    // Main game loop
    void Run();

private:
    SDL_Renderer* renderer; 
    SDL_Window* window; // Renderer for drawing textures
    bool isRunning;          // Whether the game is still running
    // Game initialization logic
    void Initialize();

    // Handle events (keyboard, mouse, etc.)
    void HandleEvents();

    // Update game logic
    void Update();

    // Render game objects
    void Render();

    // Clean up resources
    void Cleanup();
};

#endif // GAME_H
