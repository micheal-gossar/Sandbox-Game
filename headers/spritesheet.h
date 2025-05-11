#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL.h>
#include <string>

class Spritesheet {
public:
    Spritesheet(const std::string& textureID, int spriteWidth, int spriteHeight);

    void Update();  // Call once per frame to animate
    void Draw(SDL_Renderer* renderer, int x, int y, int scale = 1);  // Draw current sprite frame
    void SetGridSize(int sheetWidth, int sheetHeight);  // Set size of full sheet in pixels

private:
    std::string m_textureID;
    int m_spriteWidth, m_spriteHeight;
    int m_sheetWidth, m_sheetHeight;
    int m_currentFrame = 0;
    int m_totalFrames = 0;
};

#endif // SPRITESHEET_H
