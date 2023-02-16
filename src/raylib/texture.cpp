/*
** EPITECH PROJECT, 2022
** texture.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_texture2d.hpp"

namespace Raylib {

    MyTexture2D::MyTexture2D(const std::string &filename) {
        this->_texture2d = LoadTexture(filename.c_str());
    }

    MyTexture2D::~MyTexture2D() {
        UnloadTexture(this->_texture2d);
    }

    void MyTexture2D::set_texture_width(float width)
    {
        _texture2d.width = width;
    }

    void MyTexture2D::set_texture(Texture2D texture)
    {
        _texture2d = texture;
    }

    void MyTexture2D::set_texture_grather(float width, float height) {
        _texture2d.height = height;
        _texture2d.width = width;
    }

    Texture2D MyTexture2D::get_texture_2d() {
        return this->_texture2d;
    }
}
