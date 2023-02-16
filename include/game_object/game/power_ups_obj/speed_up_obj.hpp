/*
** EPITECH PROJECT, 2022
** speed_up_obj.hpp
** File description:
** header
*/

#ifndef SPEED_UP_OBJ_HPP
#define SPEED_UP_OBJ_HPP

#include "power_ups_obj.hpp"

namespace Raylib {

    class SpeedUpObj : public PowerUpsObj {
    private:
        MyVector3 _pos;
        MyVector3 _size;
        Engine &_engine;
        MyTexture2D &_texture;

    public:
        SpeedUpObj(MyVector3 pos, MyVector3 size,
            Engine &engine, MyTexture2D &texture);
        ~SpeedUpObj();
        void start();
        void draw();
    };
}

#endif
