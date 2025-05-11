#ifndef TEXTURE_ID_H
#define TEXTURE_ID_H

#include <cstddef>
#include <functional>

class textureID {
public:
    textureID(int id2, int layer2, int ImGuiWindow2)
        : id(id2), layer(layer2), ImGuiWindow(ImGuiWindow2) {}

    bool operator==(const textureID& other) const {
        return id == other.id && layer == other.layer && ImGuiWindow == other.ImGuiWindow;
    }

    struct Hasher {
        std::size_t operator()(const textureID& tid) const {
            return std::hash<int>()(tid.id)
                 ^ (std::hash<int>()(tid.layer) << 1)
                 ^ (std::hash<int>()(tid.ImGuiWindow) << 2);
        }
    };

private:
    int id;
    int layer;
    int ImGuiWindow;
    friend class TextureManager;
};

#endif // TEXTURE_ID_H
