#ifndef TEXTURE_ID_H
#define TEXTURE_ID_H

#include <cstddef>     // For std::size_t
#include <functional>  // For std::hash

class textureID {
public:
    textureID(int id2, int layer2, int ImGuiWindow2)
        : id(id2), layer(layer2), ImGuiWindow(ImGuiWindow2) {}

    // Equality operator (needed for comparisons and hash-based containers)
    bool operator==(const textureID& other) const {
        return id == other.id &&
               layer == other.layer &&
               ImGuiWindow == other.ImGuiWindow;
    }

    // Custom hash struct for unordered_map/set
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

    // Friend classes that need access to private members
    friend class TextureManager;
};

#endif // TEXTURE_ID_H
