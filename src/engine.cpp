//
// Created by gabuniku on 2023/11/26.
//

#include "engine.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

namespace OGEG {

    OriGearEngine::OriGearEngine() {}

    OriGearEngine::~OriGearEngine() {
        DeInit();
    }

    bool OriGearEngine::Init() {
        return Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    }


    bool OriGearEngine::Init(uint32_t flag) {
        if (SDL_Init(flag) >= 0)
            _init_main = true;

        // init mixer
        if (TTF_Init() >= 0)
            _init_ttf = true;
        return _init_main || _init_ttf;
    }

    bool OriGearEngine::DeInit() {
        if (_init_main) {
            SDL_Quit();
            _init_main = false;
        }
        if (_init_ttf) {
            TTF_Quit();
            _init_ttf = false;
        }
        return true;
    }

}