/*
** EPITECH PROJECT, 2022
** pnj_manager.cpp
** File description:
** functions
*/

#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "pnj_manager.hpp"

namespace Raylib {

    PnjObj::PnjObj() {}

    PnjObj::~PnjObj() {}

/////////////////////////////////////////////////////////////////////////////////

    Player::~Player()
    {
        printf("PLAYER DESTROYED\n");
        exit(12);
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
        _engine.set_player_alive(-1);
    }

    Player::Player(Engine &engine, MyModel &model, MyTexture2D &texture, int id,
        MyModelAnimation &anim, MyVector3 pos, MyVector3 size) :
        _engine(engine), _model(model), _texture(texture), _id(id), _anim(anim),
        _pos(pos), _size(size) {
        SetMaterialTexture(&_model.getModel().materials[0],
            MATERIAL_MAP_DIFFUSE, _texture.get_texture_2d());
        _model.getModel().transform = MatrixRotateXYZ(
            (Vector3) {1.6f, 0.0f, 0.0f});
        start();
    }

    void Player::start() {
        push_back_comp<HitBox>(_pos, _size, false, false, _id,
                               *this, _engine, "player");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void Player::draw() {
        clock_t _time = clock();
        float tmp = float(_time) / CLOCKS_PER_SEC;
        auto &hitbox = get_object<HitBox>();
        if (hitbox.get_is_moving()) {
            if (tmp - _time_anim > 0.05) {
                _anim_frame_counter++;
                UpdateModelAnimation(this->_model.getModel(),
                                     _anim.getModelAnimation()[0],
                                     _anim_frame_counter);
                if (_anim_frame_counter >= _anim.getModelAnimation()[0].frameCount)
                    _anim_frame_counter = 0;
            }
        }
        else {
            _anim_frame_counter = 10;
            UpdateModelAnimation(this->_model.getModel(),
                                 _anim.getModelAnimation()[0],
                                 _anim_frame_counter);
        }
        if (hitbox._direction == UP) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 3.15f, 0.0f});
        }
        if (hitbox._direction == DOWN) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 0.0f, 0.0f});
        }
        if (hitbox._direction == LEFT) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 1.575f, 0.0f});
        }
        if (hitbox._direction == RIGHT) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 4.725f, 0.0f});
        }
        DrawModel(_model.getModel(), get_object<HitBox>()
                  .get_pos().get_vector(), 0.8f, WHITE);
    }

    void Player::save_game_obj(std::ofstream &file) {
        file << "P";
    }

    int Player::get_id() const {
        return _id;
    }
//////////////////////////////////////////////////////////////////////////////////////

    Bot::~Bot()
    {
        auto &hitbox = get_object<HitBox>();

        hitbox.set_destroy(true);
        _engine._collision_manager.del_hitbox(hitbox);
        _engine.set_ia_alive(-1);
    }

    Bot::Bot(Engine &engine, MyModel &model, MyTexture2D &texture, int id,
             MyModelAnimation &anim, MyVector3 pos) :
        _engine(engine), _model(model), _texture(texture), _id(id), _anim(anim), _pos(pos) {
        SetMaterialTexture(&_model.getModel().materials[0],
                           MATERIAL_MAP_DIFFUSE,
                           _texture.get_texture_2d());
        _model.getModel().transform = MatrixRotateXYZ(
            (Vector3) {1.6f, 0.0f, 0.0f});
        start();
    }

    void Bot::start() {
        push_back_comp<HitBox>(_pos, _size, false, false, _id,
                               *this, _engine, "bot");
        _engine._collision_manager.add_hitbox(get_object<HitBox>());
    }

    void Bot::draw() {
        printf("draw bot start\n");
        clock_t _time = clock();
        float tmp = float(_time) / CLOCKS_PER_SEC;
        auto &hitbox = get_object<HitBox>();
        printf("hb\n");
        if (hitbox.get_is_moving()) {
            printf("is moving\n");
            if (tmp - _time_anim > 0.05) {
                printf("tmp\n");
                _anim_frame_counter++;
                UpdateModelAnimation(this->_model.getModel(),
                                     _anim.getModelAnimation()[0],
                                     _anim_frame_counter);
                printf("update\n");
                if (_anim_frame_counter >= _anim.getModelAnimation()[0].frameCount)
                    _anim_frame_counter = 0;
            }
            printf("1\n");
        }
        else {
            printf("abu\n");
            _anim_frame_counter = 10;
            UpdateModelAnimation(this->_model.getModel(),
                                 _anim.getModelAnimation()[0],
                                 _anim_frame_counter);
        }
        if (hitbox._direction == UP) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 3.15f, 0.0f});
        }
        if (hitbox._direction == DOWN) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 0.0f, 0.0f});
        }
        if (hitbox._direction == LEFT) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 1.575f, 0.0f});
        }
        if (hitbox._direction == RIGHT) {
            _model.getModel().transform =
                MatrixRotateXYZ((Vector3) {1.6f, 4.725f, 0.0f});
        }
        printf("draw\n");
        DrawModel(_model.getModel(), get_object<HitBox>()
                  .get_pos().get_vector(), 1.0f, WHITE);
        printf("draw bot end\n");
    }

    void Bot::save_game_obj(std::ofstream &file)
    {
        file << "I";
    }

    int Bot::get_id() const
    {
        return _id;
    }
}
