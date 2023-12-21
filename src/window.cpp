//
// Created by gabuniku on 2023/11/26.
//

#include "window.hpp"

namespace OGEG {
    Window::Window(const char *title, int w, int h, int x, int y, uint32_t flag) : _ptr(nullptr, SDL_DestroyWindow) {
        _ptr.reset(SDL_CreateWindow(title, x, y, w, h, flag));
    }

    Window::~Window() = default;

    std::optional<Renderer> Window::CreateRenderer(int index, uint32_t flag) {
        SDL_Renderer *ptr = SDL_CreateRenderer(_ptr.get(), index, flag);
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Renderer(ptr);
    }

    void Window::SetTitle(const std::string &title) {
        SDL_SetWindowTitle(_ptr.get(), title.c_str());
    }

} // OGEG