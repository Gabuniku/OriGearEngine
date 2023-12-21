//
// Created by gabuniku on 2023/12/09.
//

#include "surface.hpp"

namespace OGEG {
    Surface::Surface(SDL_Surface *ptr) {
        _ptr.reset(ptr, SDL_FreeSurface);
    }


    std::shared_ptr<SDL_Surface> Surface::ptr() { return _ptr; }

    void Surface::Blit(OGEG::Surface &src, OGEG::Rect &srcrect, OGEG::Rect &drect) {
        SDL_Rect srr = srcrect;
        SDL_Rect drr = drect;
        SDL_BlitSurface(_ptr.get(), &srr, src.ptr().get(), &drr);
    }

    std::optional<Surface> CreateRGB(int width, int height, int depth, uint32_t r_mask, uint32_t g_mask, uint32_t b_mask, uint32_t a_mask) {
        SDL_Surface *ptr = SDL_CreateRGBSurface(0, width, height, depth, r_mask, g_mask, b_mask, a_mask);
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Surface(ptr);
    }
} // OGEG