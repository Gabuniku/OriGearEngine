//
// Created by gabuniku on 2023/11/26.
//

#include "window.hpp"

namespace OGEG {
    Window::Window(SDL_Window *ptr) {
        _window = ptr;
        _destroy = false;
    }

    Window::~Window() {
        Destroy();
    }

    void Window::Destroy() {
        if (!_destroy) {
            SDL_DestroyWindow(_window);
            _window = nullptr;
            _destroy = true;
        }
    }

    void Window::SetTitle(const std::string &title) {
        SDL_SetWindowTitle(_window, title.c_str());
    }

} // OGEG