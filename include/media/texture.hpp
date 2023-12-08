//
// Created by gabuniku on 2023/11/26.
//

#ifndef ORIGEAR_TEXTURE_HPP
#define ORIGEAR_TEXTURE_HPP

#include <cstdio>
#include <SDL2/SDL_render.h>
#include "../abs/destroyable.hpp"

namespace OGEG {

    class Texture : public Destroyable {
    private:
        SDL_Texture *_ptr;
    public:
        explicit Texture(const char *path);

        void Destroy() override;
    };

} // OriGearEngine

#endif //ORIGEAR_TEXTURE_HPP
