//
// Created by gabuniku on 2023/12/09.
//

#ifndef ORIGEAR_IMAGE_HPP
#define ORIGEAR_IMAGE_HPP

#include <optional>
#include <SDL2/SDL_image.h>
#include "../surface.hpp"
#include "../texture.hpp"
#include "../renderer.hpp"

namespace OGEG::Image {
    std::optional<Surface> LoadSurfaceImage(const char *filename);

    std::optional<Texture> LoadTextureImage(Renderer &renderer, const char *filename);
}


#endif //ORIGEAR_IMAGE_HPP
