//
// Created by gabuniku on 2023/12/09.
//

#ifndef ORIGEAR_SURFACE_HPP
#define ORIGEAR_SURFACE_HPP

#include <optional>
#include <memory>
#include <SDL2/SDL_surface.h>
#include "util.hpp"

namespace OGEG {

    class Surface {
    private:
        std::shared_ptr<SDL_Surface> _ptr;
    public:
        explicit Surface(SDL_Surface *ptr);


        std::shared_ptr<SDL_Surface> ptr();

        void Blit(Surface &src, Rect &srcrect, Rect &drect);

    };

    static std::optional<Surface> CreateRGB(int width, int height, int depth, uint32_t r_mask, uint32_t g_mask, uint32_t b_mask, uint32_t a_mask);

} // OGEG

#endif //ORIGEAR_SURFACE_HPP
