//
// Created by gabuniku on 2023/11/26.
//

#ifndef ORIGEAR_TEXTURE_HPP
#define ORIGEAR_TEXTURE_HPP

#include <cstdio>
#include <memory>
#include <SDL2/SDL_render.h>
#include "util.hpp"

namespace OGEG {

    class Texture {
    private:
        std::shared_ptr<SDL_Texture> _ptr;
        int _width, _height;
    public:
        explicit Texture(SDL_Texture *ptr);

        ~Texture();

        std::shared_ptr<SDL_Texture> ptr();

        int GetWidth();

        int GetHeight();

        Rect GetRect();

    };

} // OriGearEngine

#endif //ORIGEAR_TEXTURE_HPP
