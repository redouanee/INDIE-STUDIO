/*
** EPITECH PROJECT, 2022
** my_ray_collision.hpp
** File description:
** header
*/

#ifndef MY_RAY_COLLISION_HPP
#define MY_RAY_COLLISION_HPP

#include <raylib.h>

namespace Raylib {

    class MyRayCollision {
    private:
        struct RayCollision _ray_collision;
    public:
        MyRayCollision();
        ~MyRayCollision();
        RayCollision get_ray_collision();
    };
}

#endif
