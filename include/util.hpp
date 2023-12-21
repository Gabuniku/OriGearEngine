//
// Created by gabuniku on 23/12/09.
//

#ifndef ORIGEAR_UTIL_HPP
#define ORIGEAR_UTIL_HPP

#include <cstdint>
#include <SDL2/SDL.h>

namespace OGEG {

    typedef SDL_Rect Rect;

    typedef struct color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        color(const uint32_t &uint32) {
            r = uint32 >> 24;
            g = (uint32 & 0x00FF0000) >> 16;
            b = (uint32 & 0x0000FF00) >> 8;
            a = uint32 & 0xFF;
        }

        color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

        explicit operator uint32_t() const {
            return (r << 24) | (g << 16) | (b << 8) | a;
        }

        operator SDL_Color() const {
            return (SDL_Color) {r, g, b, a};
        }

    } Color;

    inline void Delay(uint32_t ms) {
        SDL_Delay(ms);
    };

}

#endif //ORIGEAR_UTIL_HPP
