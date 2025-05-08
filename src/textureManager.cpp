#include "../headers/textureManager.h"

std::unordered_map<textureID, SDL_Texture*, textureID::Hasher> TextureManager::textures;
