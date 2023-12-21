//
// Created by gabuniku on 2023/12/09.
//

#include "media/image.hpp"

namespace OGEG::Image {
    std::optional<Surface> LoadSurfaceImage(const char *filename) {
        SDL_Surface *ptr = IMG_Load(filename);
        if (ptr == nullptr)
            return std::nullopt;
        return Surface(ptr);
    }

    std::optional<Texture> LoadTextureImage(Renderer &renderer, const char *filename) {
        SDL_Texture *ptr = IMG_LoadTexture(renderer.ptr().get(), filename);
        if (ptr == nullptr)
            return std::nullopt;
        return Texture(ptr);
    }
}