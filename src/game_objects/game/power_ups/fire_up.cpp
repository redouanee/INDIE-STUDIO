/*
** EPITECH PROJECT, 2022
** fire_up.cpp
** File description:
** functions
*/

#include "fire_up_obj.hpp"

namespace Raylib {

    FireUpObj::FireUpObj(MyVector3 pos, MyVector3 size, Engine &engine, MyTexture2D &texture) :
        _pos(pos), _size(size), _engine(engine), _texture(texture) {
        start();
    }

    FireUpObj::~FireUpObj() {
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
    }

    void FireUpObj::start() {
        push_back_comp<HitBox>(_pos, _size, false, false,
            *this, _engine, "fire_up");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void FireUpObj::draw() {
        DrawCubeTexture(_texture.get_texture_2d(), _pos.get_vector(), _size.get_vector().x,
            _size.get_vector().y, _size.get_vector().z, WHITE);
    }
}
