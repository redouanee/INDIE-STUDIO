/*
** EPITECH PROJECT, 2022
** vector3.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_vector3.hpp"

namespace Raylib {

    MyVector3::MyVector3(float x, float y, float z) {
        _vector3.x = x;
        _vector3.y = y;
        _vector3.z = z;
    }

    MyVector3::~MyVector3() {}

    void MyVector3::set_vector_x(float x) {
        _vector3.x += x;
    }

    void MyVector3::set_vector_y(float y) {
        _vector3.y += y;
    }

    void MyVector3::set_vector_z(float z) {
        _vector3.z += z;
    }

    Vector3 MyVector3::get_vector(void) const{
        return _vector3;
    }
}
