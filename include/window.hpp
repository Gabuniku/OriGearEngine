//
// Created by gabuniku on 2023/11/26.
//

#ifndef ORIGEAR_WINDOW_HPP
#define ORIGEAR_WINDOW_HPP


#include <memory>
#include <string>
#include <SDL2/SDL_video.h>

namespace OGEG {

    class Window {
    private:
        bool _destroy = true;
        SDL_Window *_window = nullptr;
    public:
        Window(SDL_Window *ptr);

        ~Window();

        void Destroy();

        void SetTitle(const std::string &title);
    };

} // OGEG

#endif //ORIGEAR_WINDOW_HPP
