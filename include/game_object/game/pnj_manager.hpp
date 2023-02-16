/*
** EPITECH PROJECT, 2022
** pnj_manager.hpp
** File description:
** header
*/

#ifndef PNJ_MANAGER_HPP
#define PNJ_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <raylib.h>
#include <raymath.h>
#include "raylib.hpp"
#include "game_object.hpp"
#include "hit_box.hpp"
#include "animation.hpp"
#include "my_model.hpp"
#include "my_texture2d.hpp"

namespace Raylib {

    class PnjObj : public IGameObj {
    public:
        PnjObj();
        virtual ~PnjObj();

        virtual void start() = 0;
        virtual void draw() = 0;
    };

    class Player : public PnjObj {
    private:
        Engine &_engine;
        MyModel &_model;
        int _id;
        MyTexture2D &_texture;
        MyModelAnimation &_anim;
        int _anim_frame_counter = 0;
        MyVector3 _pos;
        MyVector3 _size;
        float _time_anim = float(clock()) / CLOCKS_PER_SEC;
        int _fire_up = 0;

    public:

        Player(Engine &engine, MyModel &model, MyTexture2D &texture, int id,
            MyModelAnimation &anim, MyVector3 pos, MyVector3 size);
        ~Player();
        void start();
        void draw();
        void save_game_obj(std::ofstream &save_file);
        int get_id() const;
    };

    class Bot : public PnjObj {
    private:
        Engine &_engine;
        MyModel &_model;
        MyTexture2D &_texture;
        MyModelAnimation &_anim;
        int _anim_frame_counter = 0;
        MyVector3 _pos;
        int _id;
        MyVector3 _size;
        float _time_anim = float(clock()) / CLOCKS_PER_SEC;
    public:
        Bot(Engine &engine, MyModel &model, MyTexture2D &texture, int id,
            MyModelAnimation &anim, MyVector3 pos);
        ~Bot();
        void start();
        void draw();
        void save_game_obj(std::ofstream &save_file);
        int get_id() const;
    };
}

#endif
