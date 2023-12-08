//
// Created by gabuniku on 23/12/09.
//

#ifndef ORIGEAR_UTIL_HPP
#define ORIGEAR_UTIL_HPP

#include <cstdint>
#include <SDL2/SDL.h>

namespace OGEG {
    inline void Delay(uint32_t ms){
        SDL_Delay(ms);
    };
}

#endif //ORIGEAR_UTIL_HPP
