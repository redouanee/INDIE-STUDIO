/*
** EPITECH PROJECT, 2022
** brick_obj.hpp
** File description:
** header
*/

#ifndef BRICK_OBJ_HPP
#define BRICK_OBJ_HPP

#include <fstream>
#include <iostream>
#include "blocks_obj.hpp"

namespace Raylib {

    class BrickObj : public BlocksObj {
    private:
        Engine &_engine;
        MyTexture2D &_texture;
        MyVector3 _pos;
        MyVector3 _size;
    public:
        BrickObj(MyVector3 pos, MyVector3 size,
            Engine &engine, MyTexture2D &texture);
        ~BrickObj();

        void start();
        void draw();
        void save_game_obj(std::ofstream &save_file);
    };
}

#endif
