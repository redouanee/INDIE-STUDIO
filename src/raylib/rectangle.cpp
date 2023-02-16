/*
** EPITECH PROJECT, 2022
** rectangle.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_rectangle.hpp"

namespace Raylib {

    MyRectangle::MyRectangle() {}

    MyRectangle::~MyRectangle() {}

    void MyRectangle::set_rectangle(float x, float y, float width, float height) {
        _rectangle.x = x;
        _rectangle.y = y;
        _rectangle.height = height;
        _rectangle.width = width;
    }

    void MyRectangle::set_rectangle_y(float y) {
        _rectangle.y = y;
    }

    Rectangle MyRectangle::get_rectangle(void)
    {
        return this->_rectangle;
    }
}
