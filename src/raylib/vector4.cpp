/*
** EPITECH PROJECT, 2022
** vector4.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_vector4.hpp"

namespace Raylib {

    MyVector4::MyVector4(int x, int y, int z, int w) {
        this->_vector4.x = x;
        this->_vector4.y = y;
        this->_vector4.z = z;
        this->_vector4.w = w;
    }

    MyVector4::~MyVector4() {}

    Vector4 MyVector4::get_vector(void) {
        return this->_vector4;
    }
}
