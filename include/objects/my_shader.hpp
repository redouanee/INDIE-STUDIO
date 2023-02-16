/*
** EPITECH PROJECT, 2022
** my_shader.hpp
** File description:
** header
*/

#ifndef MY_SHADER_HPP
#define MY_SHADER_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyShader {
        private:
            struct Shader _shader;
        public:
            MyShader(const std::string &vsfilename, const std::string &fsfilename);
            ~MyShader();
            Shader get_shader(void);
    };
};

#endif
