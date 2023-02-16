/*
** EPITECH PROJECT, 2022
** flame.cpp
** File description:
** functions
*/

#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include "flame_obj.hpp"

namespace Raylib {

    FlameObj::FlameObj(Engine &engine, MyModel &model, MyTexture2D &texture,
        MyModelAnimation &anim, MyVector3 pos, MyVector3 size) :
        _engine(engine), _model(model), _texture(texture), _anim(anim),
        _pos(pos), _size(size) {
            SetMaterialTexture(&_model.getModel().materials[0],
                MATERIAL_MAP_DIFFUSE, _texture.get_texture_2d());
            _model.getModel().transform = MatrixRotateXYZ(
                (Vector3) {1.6f, 0.0f, 0.0f});
            start();
        }

    FlameObj::~FlameObj() {
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
    }

    void FlameObj::start() {
        push_back_comp<HitBox>(_pos, _size, false, false,
                               *this, _engine, "flame");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void FlameObj::draw() {
        clock_t _time = clock();
        float tmp = float(_time) / CLOCKS_PER_SEC;
        if (tmp - _time_explosion > 1) {
            to_destroy = true;
        }
        if (tmp - _time_anim > 0.05) {
            _anim_frame_counter++;
            UpdateModelAnimation(this->_model.getModel(),
                                 _anim.getModelAnimation()[0],
                                 _anim_frame_counter);
            if (_anim_frame_counter >= _anim.getModelAnimation()[0].frameCount)
                _anim_frame_counter = 0;
        }
        _pos.set_vector_y(-1);
        DrawModel(_model.getModel(), _pos.get_vector(), 2.3f, WHITE);
        _pos.set_vector_y(1);
    }
}
