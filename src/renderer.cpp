//
// Created by gabuniku on 2023/12/03.
//

#include "renderer.hpp"

namespace OGEG {

    Renderer::Renderer(SDL_Renderer *ptr) {
        _renderer = ptr;
        _destroy = false;
    }

    Renderer::~Renderer() {
       // Destroy();
    }

    void Renderer::Destroy() {
        if (!_destroy) {
            SDL_DestroyRenderer(_renderer);
            _renderer = nullptr;
            _destroy = true;
            puts("Destroy Renderer");
        }
    }

} // OGEG