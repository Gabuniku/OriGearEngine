//
// Created by gabuniku on 2023/12/03.
//

#ifndef ORIGEAR_RENDERER_HPP
#define ORIGEAR_RENDERER_HPP

#include <memory>
#include <optional>
#include <SDL2/SDL.h>
#include "texture.hpp"
#include "surface.hpp"
#include "util.hpp"

namespace OGEG {

    class Renderer {
    private:
        std::shared_ptr<SDL_Renderer> _ptr;
    public:
        explicit Renderer(SDL_Renderer *ptr);

        ~Renderer();

        std::shared_ptr<SDL_Renderer> ptr();

        std::optional<Texture> CreateTexture(int w, int h, uint32_t format, int access);

        std::optional<Texture> CreateTextureFromSurface(Surface &surface);

        void SetDefaultTarget();

        void SetTarget(Texture &texture);

        void Present();

        void SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

        void SetDrawColor(Color color);

        Color GetDrawColor();

        void Clear();

        void Copy(Texture &texture, int x = 0, int y = 0, bool extend = false);

        void Copy(Texture &texture, Rect &srcrect, Rect &dstrect);

        void DrawLine(int x1, int y1, int x2, int y2);

        void DrawCircle(int x, int y, int radius);

        void FillRect(Rect &rect);


    };

} // OGEG

#endif //ORIGEAR_RENDERER_HPP
