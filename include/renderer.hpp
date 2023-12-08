//
// Created by gabuniku on 2023/12/03.
//

#ifndef ORIGEAR_RENDERER_HPP
#define ORIGEAR_RENDERER_HPP

#include "abs/destroyable.hpp"
#include <memory>
#include <SDL2/SDL.h>

namespace OGEG {

    class Renderer : public Destroyable {
    private:
        SDL_Renderer *_renderer = nullptr;
    public:
        explicit Renderer(SDL_Renderer *ptr);

        ~Renderer();

        void Destroy() override;
    };

} // OGEG

#endif //ORIGEAR_RENDERER_HPP
