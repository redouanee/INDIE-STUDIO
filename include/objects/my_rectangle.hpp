/*
** EPITECH PROJECT, 2022
** my_rectangle.hpp
** File descriptions
** header
*/

#ifndef MY_RECTANGLE_HPP
#define MY_RECTANGLE_HPP

#include <raylib.h>

namespace Raylib {

    class MyRectangle {
    private:
        struct Rectangle _rectangle;
    public:
        MyRectangle();
        ~MyRectangle();
        void set_rectangle(float x, float y, float width, float height);
        void set_rectangle_y(float y);
        Rectangle get_rectangle(void);
    };
}

#endif
