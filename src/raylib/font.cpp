/*
** EPITECH PROJECT, 2022
** font.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_font.hpp"

namespace Raylib {

    MyFont::MyFont(const std::string &filename)
    {
        this->_font = LoadFont(filename.c_str());
    }

    MyFont::~MyFont() {
        UnloadFont(this->_font);
    }

    Font MyFont::get_font(void)
    {
        return this->_font;
    }
};
