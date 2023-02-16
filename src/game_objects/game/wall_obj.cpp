/*
** EPITECH PROJECT, 2022
** wall.cpp
** File description:
** functions
*/

#include <raylib.h>
#include <fstream>
#include <iostream>
#include "wall_obj.hpp"
#include "button.hpp"

namespace Raylib {

    WallObj::WallObj(MyVector3 pos, MyVector3 size, Engine &engine, MyTexture2D &texture) :
        _pos(pos), _size(size), _engine(engine), _texture(texture) {
        start();
    }

    WallObj::~WallObj() {
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
    }

    void WallObj::start() {
        push_back_comp<HitBox>(_pos, _size, false, false,
            *this, _engine, "wall");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void WallObj::draw() {
        DrawCubeTexture(_texture.get_texture_2d(), _pos.get_vector(), _size.get_vector().x,
            _size.get_vector().y, _size.get_vector().z, WHITE);
    }

    void WallObj::save_game_obj(std::ofstream &save_file) {
        save_file << "W";
    }
}
