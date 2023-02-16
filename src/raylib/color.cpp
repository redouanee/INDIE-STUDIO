/*
** EPITECH PROJECT, 2022
** color.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_color.hpp"

namespace Raylib {

    MyColor::MyColor(int r, int g, int b, int a) {
       _color.r = r;
       _color.g = g;
       _color.b = b;
       _color.a = a;
    }

    MyColor::~MyColor() {
    }

    void MyColor::set_color(int r, int g, int b) {
        _color.r = r;
        _color.g = g;
        _color.b = b;
    }

    Color MyColor::get_color(void)
    {
        return this->_color;
    }
}
