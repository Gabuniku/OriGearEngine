//
// Created by gabuniku on 2023/11/26.
//

#include "media/texture.hpp"
#include <SDL2/SDL_image.h>

namespace OGEG {
    Texture::Texture(const char *path) : Destroyable() {
    }

    void Texture::Destroy() {
        if (_ptr != nullptr)
            SDL_DestroyTexture(_ptr);
    }
} // OriGearEngine