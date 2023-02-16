/*
** EPITECH PROJECT, 2022
** wall_obj.hpp
** File description:
** header
*/

#ifndef WALL_OBJ_HPP
#define WALL_OBJ_HPP

#include "blocks_obj.hpp"

namespace Raylib {

    class WallObj : public BlocksObj {
    private:
        MyVector3 _pos;
        MyVector3 _size;
        Engine &_engine;
        MyTexture2D &_texture;

    public:
        WallObj(MyVector3 pos, MyVector3 size,
            Engine &engine, MyTexture2D &texture);
        ~WallObj();

        void start();
        void draw();
        void save_game_obj(std::ofstream &save_file);
    };
}

#endif
