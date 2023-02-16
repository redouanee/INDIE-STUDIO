/*
** EPITECH PROJECT, 2022
** my_texture2d.hpp
** File description:
** header
*/

#ifndef MY_TEXTURE2D_HPP
#define MY_TEXTURE2D_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyTexture2D {
        private:
        Texture2D _texture2d;
    public:
        MyTexture2D(const std::string &filename = "");
        ~MyTexture2D();
        void set_texture(Texture2D texture);
        void set_texture_grather(float width, float height);
        void set_texture_width(float width);
        Texture2D get_texture_2d();
    };
};

#endif
