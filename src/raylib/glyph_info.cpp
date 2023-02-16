/*
** EPITECH PROJECT, 2022
** glyph_info.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_glyph_info.hpp"

namespace Raylib {

    MyGlyphInfo::MyGlyphInfo(const std::string &file_data, int data_size,
        int font_size, std::vector<int> &font_chars, int glyph_count, int type)
    {
        LoadFontData(reinterpret_cast<const unsigned char*>(file_data.c_str()),
            data_size, font_size, font_chars.data(), glyph_count, type);
    }

    MyGlyphInfo::~MyGlyphInfo()
    {
    }

    void MyGlyphInfo::on_destroy(int glyph_count) {
        UnloadFontData(&this->_glyph_info, glyph_count);
    }

    GlyphInfo MyGlyphInfo::get_glyph_info(void)
    {
        return this->_glyph_info;
    }
};
