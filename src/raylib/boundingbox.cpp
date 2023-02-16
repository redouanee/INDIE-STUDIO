/*
** EPITECH PROJECT, 2022
** wave.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "my_bounding_box.hpp"

namespace Raylib {

    MyBoundingBox::MyBoundingBox() {}

    MyBoundingBox::~MyBoundingBox() {}

    BoundingBox MyBoundingBox::get_bounding_box() {
        return this->_bounding_box;
    }
}
