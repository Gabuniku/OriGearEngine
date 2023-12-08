//
// Created by gabuniku on 2023/11/26.
//

#ifndef ORIGEAR_CORE_HPP
#define ORIGEAR_CORE_HPP

#include <string>
#include <memory>

#include "media/media.hpp"
#include "renderer.hpp"
#include "window.hpp"

namespace OGEG {

    class OriGearEngine {
    private:
        bool _init = false;
        std::shared_ptr<Renderer> _renderer;
    public:

        std::shared_ptr<Window> window;

        OriGearEngine();

        ~OriGearEngine();

        bool Init();

        bool DeInit();

        void Destroy();

        bool CreateWindow(const std::string &name, int width, int height);

    };
}


#endif //ORIGEAR_CORE_HPP
