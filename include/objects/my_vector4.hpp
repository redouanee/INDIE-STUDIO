/*
** EPITECH PROJECT, 2022
** my_vector4.hpp
** File description:
** header
*/

#ifndef MY_VECTOR4_HPP
#define MY_VECTOR4_HPP

#include <raylib.h>

namespace Raylib {

    class MyVector4 {
        private:
            struct Vector4 _vector4;
        public:
            MyVector4(int x=0, int y=0, int z=0, int w=0);
            ~MyVector4();
            Vector4 get_vector();
        };
};

#endif
