#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <string>
#include <map>

class TextureManager {
public:
    static bool Load(const std::string& id, const std::string& filename, SDL_Renderer* renderer);
    static void Draw(const std::string& id, SDL_Rect srcRect, SDL_Rect destRect, SDL_Renderer* renderer);
    static SDL_Texture* GetTexture(const std::string& id);
    static void Cleanup();

private:
    static std::map<std::string, SDL_Texture*> s_textures;
};

#endif // TEXTUREMANAGER_H
