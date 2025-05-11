#include "../headers/textureManager.h"
#include <SDL_image.h>
#include <iostream>

std::map<std::string, SDL_Texture*> TextureManager::s_textures;

bool TextureManager::Load(const std::string& id, const std::string& filename, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(filename.c_str());
    if (!tempSurface) {
        std::cerr << "Failed to load surface: " << IMG_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        return false;
    }

    s_textures[id] = texture;
    return true;
}

void TextureManager::Draw(const std::string& id, SDL_Rect srcRect, SDL_Rect destRect, SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, s_textures[id], &srcRect, &destRect);
}

SDL_Texture* TextureManager::GetTexture(const std::string& id) {
    return s_textures[id];
}

void TextureManager::Cleanup() {
    for (auto& pair : s_textures) {
        SDL_DestroyTexture(pair.second);
    }
    s_textures.clear();
}
