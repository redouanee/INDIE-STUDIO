/*
** EPITECH PROJECT, 2022
** ray.hpp
** File description:
** header
*/

#ifndef RAY_HPP
#define RAY_HPP

#include <raylib.h>

namespace Raylib {

    class MyRay {
    private:
        struct Ray _ray;
    public:
        MyRay();
        ~MyRay();
        Ray getray();
    };
};

#endif
