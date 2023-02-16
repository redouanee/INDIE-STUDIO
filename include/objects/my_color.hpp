/*
** EPITECH PROJECT, 2022
** my_color.hpp
** File descriptions
** header
*/

#ifndef MY_COLOR_HPP
#define MY_COLOR_HPP

#include <raylib.h>

namespace Raylib {

    class MyColor {
        private:
            struct Color _color;
        public:
            MyColor(int r=255, int g=255, int b=255, int a=255);
            ~MyColor();
            void set_color(int r, int g, int b);
            Color get_color(void);
    };
}

#endif
