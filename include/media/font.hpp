//
// Created by gabuniku on 2023/12/21.
//

#ifndef ORIGEAR_FONT_HPP
#define ORIGEAR_FONT_HPP


#include <memory>
#include <string>
#include <optional>

#include<SDL2/SDL_ttf.h>

#include "../surface.hpp"
#include "../util.hpp"


namespace OGEG {

    class Font {
    private:
        std::shared_ptr<TTF_Font> _ptr;
    public:
        explicit Font(TTF_Font *ptr);

        std::optional<Surface> RenderBlended(const std::string &text, Color color = {255, 255, 255, 255});

        std::optional<Rect> GetSize(const std::string &text);

        void SetNormal(bool enable = true);
        void SetBold(bool enable = true);
        void SetItalic(bool enable = true);
        void SetUnderline(bool enable = true);
        void SetStrikethrough(bool enable = true);
    };

    std::optional<Font> LoadFont(const std::string &file, int pt_size);

} // OGEG

#endif //ORIGEAR_FONT_HPP
