#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <unordered_map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "textureID.h"

class TextureManager {
public:
    static bool Load(SDL_Renderer* renderer, const textureID& id, const std::string& path) {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) return false;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!texture) {
            std::cout << "Texture " << id.id << " failed." << std::endl;
            return false;
        }

        textures[id] = texture;
        return true;
    }

    static SDL_Texture* Get(const textureID& id) {
        auto it = textures.find(id);
        return it != textures.end() ? it->second : nullptr;
    }

    static void Cleanup() {
        for (auto& [id, texture] : textures) {
            SDL_DestroyTexture(texture);
        }
        textures.clear();
    }

private:
    static std::unordered_map<textureID, SDL_Texture*, textureID::Hasher> textures;
};

#endif
