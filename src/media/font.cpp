//
// Created by gabuniku on 2023/12/21.
//

#include "media/font.hpp"

namespace OGEG {

    std::optional<Font> LoadFont(const std::string &file, int pt_size) {
        TTF_Font *ptr = TTF_OpenFont(file.c_str(), pt_size);
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Font(ptr);
    }

    Font::Font(TTF_Font *ptr) {
        _ptr.reset(ptr, TTF_CloseFont);
    }


    std::optional<Surface> Font::RenderBlended(const std::string &text, Color color) {
        SDL_Surface *ptr = TTF_RenderUTF8_Blended(_ptr.get(), text.c_str(), color);
        if (ptr == nullptr) {
            return std::nullopt;
        }
        return Surface(ptr);
    }

    std::optional<Rect> Font::GetSize(const std::string &text) {
        int w, h;
        if (TTF_SizeText(_ptr.get(), text.c_str(), &w, &h) == -1) {
            return std::nullopt;
        }
        return Rect{0, 0, w, h};
    }

    void Font::SetNormal(bool enable) {
        int flag = TTF_GetFontStyle(_ptr.get());
        if(enable)
            flag |= TTF_STYLE_NORMAL;
        else
            flag &= ~TTF_STYLE_NORMAL;
        TTF_SetFontStyle(_ptr.get(),flag);
    }

    void Font::SetBold(bool enable) {
        int flag = TTF_GetFontStyle(_ptr.get());
        if(enable)
            flag |= TTF_STYLE_BOLD;
        else
            flag &= ~TTF_STYLE_BOLD;
        TTF_SetFontStyle(_ptr.get(),flag);
    }

    void Font::SetItalic(bool enable) {
        int flag = TTF_GetFontStyle(_ptr.get());
        if(enable)
            flag |= TTF_STYLE_ITALIC;
        else
            flag &= ~TTF_STYLE_ITALIC;
        TTF_SetFontStyle(_ptr.get(),flag);
    }

    void Font::SetUnderline(bool enable) {
        int flag = TTF_GetFontStyle(_ptr.get());
        if(enable)
            flag |= TTF_STYLE_UNDERLINE;
        else
            flag &= ~TTF_STYLE_UNDERLINE;
        TTF_SetFontStyle(_ptr.get(),flag);
    }

    void Font::SetStrikethrough(bool enable) {
        int flag = TTF_GetFontStyle(_ptr.get());
        if(enable)
            flag |= TTF_STYLE_STRIKETHROUGH;
        else
            flag &= ~TTF_STYLE_STRIKETHROUGH;
        TTF_SetFontStyle(_ptr.get(),flag);
    }
} // OGEG