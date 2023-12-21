//
// Created by gabuniku on 2023/11/26.
//

#include "texture.hpp"
#include <SDL2/SDL_image.h>

namespace OGEG {
    Texture::Texture(SDL_Texture *ptr) {
        int w, h;
        SDL_QueryTexture(ptr, nullptr, nullptr, &w, &h);
        _width = w;
        _height = h;
        _ptr.reset(ptr, SDL_DestroyTexture);
    }

    std::shared_ptr<SDL_Texture> Texture::ptr() {
        return _ptr;
    }

    int Texture::GetWidth() {
        return _width;
    }

    int Texture::GetHeight() {
        return _height;
    }

    Rect Texture::GetRect() {
        return (Rect) {0, 0, _width, _height};
    }


    Texture::~Texture() = default;

} // OriGearEngine