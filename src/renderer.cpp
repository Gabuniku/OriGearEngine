//
// Created by gabuniku on 2023/12/03.
//

#include "renderer.hpp"

namespace OGEG {

    Renderer::Renderer(SDL_Renderer *ptr) : Destroyable() {
        _renderer = ptr;
        //_destroy = false;
    }

    Renderer::~Renderer() = default;

    void Renderer::Destroy() {
        SDL_DestroyRenderer(_renderer);
        // if (!_destroy) {
        //     puts("Des");
        //     SDL_DestroyRenderer(_renderer);
        //     _renderer = nullptr;
        //     _destroy = true;
        // }
    }

} // OGEG