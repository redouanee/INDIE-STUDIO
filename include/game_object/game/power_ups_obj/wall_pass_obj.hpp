/*
** EPITECH PROJECT, 2022
** wall_pass_obj.hpp
** File description:
** header
*/

#ifndef WALL_PASS_OBJ_HPP
#define WALL_PASS_OBJ_HPP

#include "power_ups_obj.hpp"

namespace Raylib {

    class WallPassObj : public PowerUpsObj {
    private:
        MyVector3 _pos;
        MyVector3 _size;
        Engine &_engine;
        MyTexture2D &_texture;

    public:
        WallPassObj(MyVector3 pos, MyVector3 size,
            Engine &engine, MyTexture2D &texture);
        ~WallPassObj();
        void start();
        void draw();
    };
}

#endif
