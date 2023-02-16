/*
** EPITECH PROJECT, 2022
** vector2.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_vector2.hpp"

namespace Raylib {

    MyVector2::MyVector2(int x, int y) {
        this->_vector2.x = x;
        this->_vector2.y = y;
    }

    MyVector2::~MyVector2() {}

    void MyVector2::set_vector_x(float x) {
        _vector2.x = x;
    }

    void MyVector2::set_vector_y(float y) {
        _vector2.y = y;
    }

    void MyVector2::set_vector(Vector2 vect) {
        _vector2 = vect;
    }

    Vector2 MyVector2::get_vector(void) {
        return this->_vector2;
    }
}
