/*
** EPITECH PROJECT, 2022
** my_glyph_info.hpp
** File description:
** header
*/

#ifndef MY_GLYPH_INFO_HPP
#define MY_GLYPH_INFO_HPP

#include <raylib.h>
#include <iostream>
#include <vector>

namespace Raylib {

    class MyGlyphInfo {
        private:
            struct GlyphInfo _glyph_info;
        public:
            MyGlyphInfo(const std::string &file_data, int data_size, int font_size,
                std::vector<int> &font_chars, int glyph_count, int type);
            ~MyGlyphInfo();
            void on_destroy(int glyph_count);
            GlyphInfo get_glyph_info(void);
    };
};

#endif
