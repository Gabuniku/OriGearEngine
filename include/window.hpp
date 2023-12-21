//
// Created by gabuniku on 2023/11/26.
//

#ifndef ORIGEAR_WINDOW_HPP
#define ORIGEAR_WINDOW_HPP


#include <memory>
#include <string>
#include <optional>
#include <SDL2/SDL_video.h>
#include "renderer.hpp"

namespace OGEG {

    class Window {
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> _ptr;
    public:
        Window(const char *title, int w, int h, int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED, uint32_t flag = 0);

        ~Window();

        std::optional<Renderer> CreateRenderer(int index = -1, uint32_t flag = 0);

        void SetTitle(const std::string &title);
    };

} // OGEG

#endif //ORIGEAR_WINDOW_HPP
