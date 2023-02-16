/*
** EPITECH PROJECT, 2022
** my_bounding_box.hpp
** File description:
** header
*/

#ifndef MY_BOUNDING_BOX_HPP
#define MY_BOUNDING_BOX_HPP

#include <raylib.h>

namespace Raylib {

    class MyBoundingBox {
    private:
        struct BoundingBox _bounding_box;
    public:
        MyBoundingBox();
        ~MyBoundingBox();
        BoundingBox get_bounding_box();
    };
}

#endif
