//
// Created by gabuniku on 2023/12/03.
//

#include "renderer.hpp"

namespace OGEG {

    Renderer::Renderer(SDL_Renderer *ptr) {
        _ptr.reset(ptr, SDL_DestroyRenderer);
    }

    Renderer::~Renderer() = default;


    std::shared_ptr<SDL_Renderer> Renderer::ptr() {
        return _ptr;
    }

    std::optional<Texture> Renderer::CreateTexture(int w, int h, uint32_t format, int access) {
        SDL_Texture *ptr = SDL_CreateTexture(_ptr.get(), format, access, w, h);
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Texture(ptr);
    }

    std::optional<Texture> Renderer::CreateTextureFromSurface(Surface &surface) {
        SDL_Texture *ptr = SDL_CreateTextureFromSurface(_ptr.get(), surface.ptr().get());
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Texture(ptr);
    }

    void Renderer::SetDefaultTarget() {
        SDL_SetRenderTarget(_ptr.get(), nullptr);
    }

    void Renderer::SetTarget(Texture &texture) {
        SDL_SetRenderTarget(_ptr.get(), texture.ptr().get());
    }

    void Renderer::Present() {
        SDL_RenderPresent(_ptr.get());
    }

    void Renderer::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        SDL_SetRenderDrawColor(_ptr.get(), r, g, b, a);
    }

    void Renderer::SetDrawColor(Color color) {
        SetDrawColor(color.r, color.g, color.b, color.a);
    }

    Color Renderer::GetDrawColor() {
        uint8_t r, g, b, a;
        SDL_GetRenderDrawColor(_ptr.get(), &r, &g, &b, &a);
        return (Color) {r, g, b, a};
    }

    void Renderer::Clear() {
        SDL_RenderClear(_ptr.get());
    }

    void Renderer::Copy(Texture &texture, int x, int y, bool extend) {
        if (extend) {
            SDL_RenderCopy(_ptr.get(), texture.ptr().get(), nullptr, nullptr);
        } else {
            SDL_Rect dst = texture.GetRect();
            dst.x = x;
            dst.y = y;
            SDL_RenderCopy(_ptr.get(), texture.ptr().get(), nullptr, &dst);
        }
    }

    void Renderer::Copy(Texture &texture, Rect &srcrect, Rect &dstrect) {
        SDL_Rect src = srcrect;
        SDL_Rect dst = dstrect;
        SDL_RenderCopy(_ptr.get(), texture.ptr().get(), &src, &dst);
    }

    void Renderer::DrawLine(int x1, int y1, int x2, int y2) {
        SDL_RenderDrawLine(_ptr.get(), x1, y1, x2, y2);
    }

    void Renderer::DrawCircle(int x, int y, int radius) {
        double d1 = radius / 16.0;
        double d2;
        int x_ = radius;
        int y_ = 0;
        while (x_ > y_) {
            // set pixel
            SDL_RenderDrawPoint(_ptr.get(), x + x_, y - y_);
            SDL_RenderDrawPoint(_ptr.get(), x + x_, y + y_);
            SDL_RenderDrawPoint(_ptr.get(), x - x_, y - y_);
            SDL_RenderDrawPoint(_ptr.get(), x - x_, y + y_);
            SDL_RenderDrawPoint(_ptr.get(), x + y_, y - x_);
            SDL_RenderDrawPoint(_ptr.get(), x + y_, y + x_);
            SDL_RenderDrawPoint(_ptr.get(), x - y_, y - x_);
            SDL_RenderDrawPoint(_ptr.get(), x - y_, y + x_);


            y_++;
            d1 += y_;
            d2 = d1 - x_;
            if (d2 >= 0) {
                d1 = d2;
                x_--;
            }
        }
    }

    void Renderer::FillRect(OGEG::Rect &rect) {
        SDL_RenderFillRect(_ptr.get(), &rect);
    }


} // OGEG