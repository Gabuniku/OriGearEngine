//
// Created by gabuniku on 2023/11/26.
//

#include "core.hpp"

#include <SDL2/SDL.h>

namespace OGEG {

    OriGearEngine::OriGearEngine() {}

    OriGearEngine::~OriGearEngine() {
        DeInit();
    }

    bool OriGearEngine::Init() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            _init = false;
        else
            _init = true;
        return _init;
    }

    bool OriGearEngine::DeInit() {
        Destroy();
        if (_init) {
            SDL_Quit();
            _init = false;
        }
        return true;
    }

    void OriGearEngine::Destroy() {
        if (_renderer) {
            _renderer->Destroy();
            _renderer.reset();
        }
        if (window) {
            window->Destroy();
            window.reset();
        }
    }

    bool OriGearEngine::CreateWindow(const std::string &name, int width, int height) {
        if (!_init)
            return false;
        SDL_Window *win;
        SDL_Renderer *ren;
        if (SDL_CreateWindowAndRenderer(width, height, 0, &win, &ren)) {
            return false;
        }
        window = std::make_shared<Window>(win);
        _renderer = std::make_shared<Renderer>(ren);

        window->SetTitle(name);
        return true;
    }
}