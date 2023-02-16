/*
** EPITECH PROJECT, 2022
** brick.cpp
** File description:
** functions
*/

#include <fstream>
#include <iostream>
#include "brick_obj.hpp"

namespace Raylib {

    BrickObj::BrickObj(MyVector3 pos, MyVector3 size, Engine &engine, MyTexture2D &texture) :
        _pos(pos), _size(size), _engine(engine), _texture(texture) {
        start();
    }

    BrickObj::~BrickObj()
    {
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
    }

    void BrickObj::start() {
        push_back_comp<HitBox>(_pos, _size, false, false,
            *this, _engine, "brick");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void BrickObj::draw() {
        DrawCubeTexture(_texture.get_texture_2d(), _pos.get_vector(), _size.get_vector().x,
                        _size.get_vector().y, _size.get_vector().z, WHITE);
    }

    void BrickObj::save_game_obj(std::ofstream &file)
    {
        file << "B";
    }
}
