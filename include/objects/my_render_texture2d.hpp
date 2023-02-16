/*
** EPITECH PROJECT, 2022
** my_render_texture2d.hpp
** File description:
** header
*/

#ifndef MY_RENDER_TEXTURE2D_HPP
#define MY_RENDER_TEXTURE2D_HPP

#include <raylib.h>

namespace Raylib {

    class MyRenderTexture2d {
        private:
            RenderTexture2D _render_texture_2d;
        public:
            MyRenderTexture2d(int width, int height);
            ~MyRenderTexture2d();
            RenderTexture2D get_render_texture_2d(void);
    };
};

#endif
