/*
** EPITECH PROJECT, 2022
** my_font.hpp
** File description:
** header
*/

#ifndef MY_FONT_HPP
#define MY_FONT_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyFont {
        private:
            Font _font;
        public:
            MyFont(const std::string &filename = "");
            ~MyFont();
            Font get_font(void);
    };
};

#endif
