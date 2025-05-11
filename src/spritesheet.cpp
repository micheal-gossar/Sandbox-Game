#include "../headers/spritesheet.h"
#include "../headers/textureManager.h"

Spritesheet::Spritesheet(const std::string& textureID, int spriteWidth, int spriteHeight)
    : m_textureID(textureID), m_spriteWidth(spriteWidth), m_spriteHeight(spriteHeight) {}

void Spritesheet::SetGridSize(int sheetWidth, int sheetHeight) {
    m_sheetWidth = sheetWidth;
    m_sheetHeight = sheetHeight;
    int cols = sheetWidth / m_spriteWidth;
    int rows = sheetHeight / m_spriteHeight;
    m_totalFrames = cols * rows;
}

void Spritesheet::Update() {
    m_currentFrame = (m_currentFrame + 1) % m_totalFrames;
}

void Spritesheet::Draw(SDL_Renderer* renderer, int x, int y, int scale) {
    int cols = m_sheetWidth / m_spriteWidth;

    int frameX = (m_currentFrame % cols) * m_spriteWidth;
    int frameY = (m_currentFrame / cols) * m_spriteHeight;

    SDL_Rect srcRect = { frameX, frameY, m_spriteWidth, m_spriteHeight };
    SDL_Rect destRect = { x, y, m_spriteWidth * scale, m_spriteHeight*scale };

    TextureManager::Draw(m_textureID, srcRect, destRect, renderer);
}
