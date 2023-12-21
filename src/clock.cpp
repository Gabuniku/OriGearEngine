//
// Created by gabuniku on 2023/12/11.
//

#include "clock.hpp"

#include <SDL2/SDL.h>

namespace OGEG {

    Clock::Clock() {}

    Clock::Clock(uint32_t fps) {
        _wait_ms = 1000 / fps;
    }

    void Clock::Wait() {
        Wait(_wait_ms);
    }

    void Clock::Wait(uint32_t fps) {
        uint32_t ms = 1000 / fps;
        _last = SDL_GetTicks();
        while (_last - SDL_GetTicks() < ms) {
            SDL_Delay(1);
        }
    }

} // OGEG