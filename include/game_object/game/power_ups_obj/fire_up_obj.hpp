/*
** EPITECH PROJECT, 2022
** fire_up_obj.hpp
** File description:
** header
*/

#ifndef FIRE_UP_OBJ_HPP
#define FIRE_UP_OBJ_HPP

#include "power_ups_obj.hpp"

namespace Raylib {

    class FireUpObj : public PowerUpsObj {
    private:
        MyVector3 _pos;
        MyVector3 _size;
        Engine &_engine;
        MyTexture2D &_texture;

    public:
        FireUpObj(MyVector3 pos, MyVector3 size,
            Engine &engine, MyTexture2D &texture);
        ~FireUpObj();
        void start();
        void draw();
    };
}

#endif
