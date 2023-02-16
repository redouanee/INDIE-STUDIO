/*
** EPITECH PROJECT, 2022
** my_vector2.hpp
** File descriptions
** header
*/

#ifndef MY_VECTOR2_HPP
#define MY_VECTOR2_HPP

#include <raylib.h>

namespace Raylib {

    class MyVector2 {
        private:
            struct Vector2 _vector2;
        public:
            MyVector2(int x=0, int y=0);
            ~MyVector2();
            Vector2 get_vector();
            void set_vector_x(float x);
            void set_vector_y(float y);
            void set_vector(Vector2 vect);
        };
}
#endif
