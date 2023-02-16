/*
** EPITECH PROJECT, 2022
** flame_obj.hpp
** File description:
** header
*/

#ifndef FLAME_OBJ_HPP
#define FLAME_OBJ_HPP

#include <raylib.h>
#include <raymath.h>
#include "raylib.hpp"
#include "game_object.hpp"
#include "animation.hpp"
#include "my_model.hpp"
#include "my_texture2d.hpp"

namespace Raylib {

    class FlameObj : public IGameObj {
    private:
        Engine &_engine;
        MyModel &_model;
        MyTexture2D &_texture;
        MyModelAnimation &_anim;
        int _anim_frame_counter = 0;
        MyVector3 _pos;
        MyVector3 _size;
        float _time_anim = float(clock()) / CLOCKS_PER_SEC;
        float _time_explosion = float(clock()) / CLOCKS_PER_SEC;

    public:
        FlameObj(Engine &engine, MyModel &model, MyTexture2D &texture,
            MyModelAnimation &anim, MyVector3 pos, MyVector3 size);
        ~FlameObj();
        void start();
        void draw();
    };
}

#endif
