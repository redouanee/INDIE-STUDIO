/*
** EPITECH PROJECT, 2022
** shader.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_shader.hpp"

namespace Raylib {

    MyShader::MyShader(const std::string &vsfilename,
        const std::string &fsfilename) {
        this->_shader = LoadShader(vsfilename.c_str(), fsfilename.c_str());
    }

    MyShader::~MyShader() {
        UnloadShader(this->_shader);
    }

    Shader MyShader::get_shader(void)
    {
        return this->_shader;
    }
}
