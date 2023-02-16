/*
** EPITECH PROJECT, 2022
** my_vector3.hpp
** File description:
** header
*/

#ifndef MY_VECTOR3_HPP
#define MY_VECTOR3_HPP

#include <raylib.h>

namespace Raylib {

    class MyVector3 {
    private:
        struct Vector3 _vector3;
    public:
        MyVector3(float x=0, float y=0, float z=0);
        ~MyVector3();

        void set_vector_x(float x);
        void set_vector_z(float z);
        void set_vector_y(float y);
        Vector3 get_vector() const;
    };
};

#endif
