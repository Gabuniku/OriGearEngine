//
// Created by gabuniku on 23/12/09.
//

#ifndef ORIGEAR_ENGINE_HPP
#define ORIGEAR_ENGINE_HPP

#include <string>
#include <memory>

#include "media/media.hpp"
#include "renderer.hpp"
#include "window.hpp"

namespace OGEG {

    class OriGearEngine {
    private:
        bool _init_main = false;
        bool _init_mixer = false;
        bool _init_ttf = false;
    public:

        OriGearEngine();

        ~OriGearEngine();

        bool Init();

        bool Init(uint32_t flag);

        bool DeInit();
    };
}


#endif //ORIGEAR_ENGINE_HPP
