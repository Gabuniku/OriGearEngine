//
// Created by gabuniku on 2023/12/03.
//

#ifndef ORIGEAR_RENDERER_HPP
#define ORIGEAR_RENDERER_HPP

#include <memory>
#include <SDL2/SDL.h>

namespace OGEG {

    class Renderer {
    private:
        bool _destroy = true;
        SDL_Renderer *_renderer = nullptr;
    public:
        Renderer(SDL_Renderer *ptr);
        ~Renderer();

        void Destroy();
    };

} // OGEG

#endif //ORIGEAR_RENDERER_HPP
