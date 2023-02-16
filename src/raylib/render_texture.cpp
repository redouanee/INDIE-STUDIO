/*
** EPITECH PROJECT, 2022
** render_texture.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_render_texture2d.hpp"

namespace Raylib {

    MyRenderTexture2d::MyRenderTexture2d(int width, int height)
    {
        this->_render_texture_2d = LoadRenderTexture(width, height);
    }

    MyRenderTexture2d::~MyRenderTexture2d()
    {
        UnloadRenderTexture(this->_render_texture_2d);
    }

    RenderTexture2D MyRenderTexture2d::get_render_texture_2d(void)
    {
        return this->_render_texture_2d;
    }
}
