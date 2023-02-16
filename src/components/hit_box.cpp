/*
** EPITECH PROJECT, 2022
** hit_box.cpp
** File description:
** functions
*/

#include "hit_box.hpp"
#include <ctime>
#include <random>
#include <iostream>
#include "bomb_obj.hpp"
#include "wall_obj.hpp"
#include "flame_obj.hpp"
#include "fire_up_obj.hpp"
#include "pnj_manager.hpp"
#include "speed_up_obj.hpp"
#include "wall_pass_obj.hpp"

namespace Raylib {
    HitBox::HitBox(MyVector3 pos, MyVector3 size, bool touch, bool is_moving, IGameObj &obj,
        Engine &engine, const std::string &obj_type = "" /*, const std::string &sound_path*/) :
        _pos(pos), _size(size), _touch(touch), _is_moving(is_moving),
        _obj(obj), _engine(engine), _obj_type(obj_type) /*, _sound(sound_path)*/ {
        }
        HitBox::HitBox(MyVector3 pos, MyVector3 size, bool touch, bool is_moving, int id, IGameObj &obj,
        Engine &engine, const std::string &obj_type = "" /*, const std::string &sound_path*/) :
        _pos(pos), _size(size), _touch(touch), _is_moving(is_moving), _id(id),
        _obj(obj), _engine(engine), _obj_type(obj_type) /*, _sound(sound_path)*/ {
        }

    HitBox::~HitBox() {}

    void HitBox::update(IGameObj &game_obj, Engine &engine) {
        _tmp = _pos;
        if (_obj_type == "player")
            move_player();
        else if (_obj_type == "bot")
            move_bot();
        if (_obj_type == "flame")
            _engine._collision_manager.check_collision(*this);
    }

    MyVector3 HitBox::get_pos() const {
        return _pos;
    }

    MyVector3 HitBox::get_tmp() const {
        return _tmp;
    }

    MyVector3 HitBox::get_size() const {
        return _size;
    }

    void HitBox::draw(IGameObj &game_obj, Engine &engine) {}

    bool HitBox::get_is_moving() {
        return _is_moving;
    }

    void HitBox::move_player() {
        _tmp = _pos;
        _engine._collision_manager.check_collision(*this);
        if ((IsKeyDown(KEY_UP) && _id == 1) ||
            (IsKeyDown(KEY_W) && _id == 2) ||
            (IsKeyDown(KEY_T) && _id == 3) ||
            (IsKeyDown(KEY_I) && _id == 4)) {
            _tmp.set_vector_z(-0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_z(-0.15f * _speed);
                _is_moving = true;
                _direction = UP;
            }
        } else if ((IsKeyDown(KEY_DOWN) && _id == 1) ||
                   (IsKeyDown(KEY_S) && _id == 2) ||
                   (IsKeyDown(KEY_G) && _id == 3) ||
                   (IsKeyDown(KEY_K) && _id == 4)) {
            _tmp.set_vector_z(0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_z(0.15f * _speed);
                _is_moving = true;
                _direction = DOWN;
            }
        } else if ((IsKeyDown(KEY_LEFT) && _id == 1) ||
                   (IsKeyDown(KEY_Q) && _id == 2) ||
                   (IsKeyDown(KEY_R) && _id == 3) ||
                   (IsKeyDown(KEY_U) && _id == 4)) {
            _tmp.set_vector_x(-0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_x(-0.15f * _speed);
                _is_moving = true;
                _direction = LEFT;
            }
        } else if ((IsKeyDown(KEY_RIGHT) && _id == 1) ||
                   (IsKeyDown(KEY_D) && _id == 2) ||
                   (IsKeyDown(KEY_H) && _id == 3) ||
                   (IsKeyDown(KEY_L) && _id == 4)) {
            _tmp.set_vector_x(0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_x(0.15f * _speed);
                _is_moving = true;
                _direction = RIGHT;
            }
        } else if ((IsKeyDown(KEY_SPACE) && _id == 1) ||
                   (IsKeyDown(KEY_X) && _id == 2) ||
                   (IsKeyDown(KEY_B) && _id == 3) ||
                   (IsKeyDown(KEY_P) && _id == 4)) {
            MyVector3 tmp = _pos;
            tmp.set_vector_y(-1);
            _engine.push_back_obj_game<BombObj>(_engine, _fire_up,
                                    _engine._assets_manager.load_model("../assets/bomb.iqm"),
                                    _engine._assets_manager.load_texture_2d("../assets/bomb_texture.png"),
                                    _engine._assets_manager.load_model_animation("../assets/bomb_anim.iqm"),
                                    tmp, MyVector3 (1.0f, 1.0f, 1.0f));
            } else
                _is_moving = false;
    }

    std::string HitBox::directions() {
        int tmp_rand = 0;
        std::string direction;
        std::srand(std::time(nullptr));
        _rand_1 = rand() % 4;
        _rand_2 = rand() % 4;
        _rand_3 = rand() % 4;
        _rand_4 = rand() % 4;
        if (_id == 1)
            tmp_rand = _rand_1;
        if (_id == 2)
            tmp_rand = _rand_2;
        if (_id == 3)
            tmp_rand = _rand_3;
        if (_id == 4)
            tmp_rand = _rand_4;
        switch (tmp_rand) {
            case 0:
                direction = "TOP";
                break;
            case 1:
                direction = "RIGHT";
                break;
            case 2:
                direction = "DOWN";
                break;
            case 3:
                direction = "LEFT";
                break;
            default:
                break;
        }
        return direction;
    }

    void HitBox::move_bot() {
        std::string direction = directions();
        if (detect_coll == 1) {
            if (direction == tmp_direction) {
                return;
            }
            else
                detect_coll = 0;
        }
        float x = _pos.get_vector().x;
        if (direction == "TOP") {
            tmp_direction = direction;
            _tmp.set_vector_z(-0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_z(-0.15f * _speed);
                _is_moving = true;
                _direction = UP;
            } else {
                detect_coll = 1;
                return;
            }
        }
        if (direction == "RIGHT") {
            tmp_direction = direction;
            _tmp.set_vector_x(0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_x(0.15f * _speed);
                _is_moving = true;
                _direction = RIGHT;
            } else {
                detect_coll = 1;
                return;
            }
        }
        if (direction == "DOWN") {
            tmp_direction = direction;
            _tmp.set_vector_z(0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_z(0.15f * _speed);
                _is_moving = true;
                _direction = DOWN;
            } else {
                detect_coll = 1;
                return;
            }
        }
        if (direction == "LEFT") {
            tmp_direction = direction;
            _tmp.set_vector_x(-0.15f * _speed);
            if (!(_touch = _engine._collision_manager.check_collision(*this))) {
                _pos.set_vector_x(-0.15f * _speed);
                _is_moving = true;
                _direction = LEFT;
            } else {
                detect_coll = 1;
                return;
            }
        }
    }

    bool HitBox::operator==(HitBox const &right) {
        if (_obj_type != right._obj_type) {
            if (CheckCollisionBoxes(
                (BoundingBox){(Vector3){_tmp.get_vector().x - _size.get_vector().x / 2,
                                        _tmp.get_vector().y - _size.get_vector().y / 2,
                                        _tmp.get_vector().z - _size.get_vector().z / 2},
                            (Vector3) {_tmp.get_vector().x + _size.get_vector().x / 2,
                                        _tmp.get_vector().y + _size.get_vector().y / 2,
                                        _tmp.get_vector().z + _size.get_vector().z / 2}},
                (BoundingBox){(Vector3){right.get_tmp().get_vector().x - right.get_size().get_vector().x / 2,
                                        right.get_tmp().get_vector().y - right.get_size().get_vector().y / 2,
                                        right.get_tmp().get_vector().z - right.get_size().get_vector().z / 2},
                            (Vector3) {right.get_tmp().get_vector().x + right.get_size().get_vector().x / 2,
                                        right.get_tmp().get_vector().y + right.get_size().get_vector().y / 2,
                                        right.get_tmp().get_vector().z + right.get_size().get_vector().z / 2}})) {
                if (_obj_type == "flame" && right._obj_type == "wall") {
                    _obj.to_destroy = true;
                }
                if (_obj_type == "flame" && right._obj_type == "brick") {
                    right._obj.to_destroy = true;
                    if (rand() % 10 + 1 == 1) {
                        int r = rand() % 3 + 1;
                        if (r == 1)
                            _engine.push_back_obj_game<FireUpObj>(right._pos,
                                MyVector3(1.5, 1.5 ,1.5), _engine,
                                _engine._assets_manager.load_texture_2d("../assets/fire_up.png"));
                        else if (r == 2)
                            _engine.push_back_obj_game<SpeedUpObj>(right._pos,
                                MyVector3(1.5, 1.5 ,1.5), _engine,
                                _engine._assets_manager.load_texture_2d("../assets/speed_up.png"));
                        else if (r == 3)
                            _engine.push_back_obj_game<WallPassObj>(right._pos,
                                MyVector3(1.5, 1.5 ,1.5), _engine,
                                _engine._assets_manager.load_texture_2d("../assets/wall_pass.png"));
                    }
                }
                if (_obj_type == "player" && right._obj_type == "flame") {
                    _obj.to_destroy = true;
                    _engine.set_player_alive(-1);
                }
                if (_obj_type == "bot" && right._obj_type == "flame") {
                    _obj.to_destroy = true;
                    _engine.set_ia_alive(-1);
                }
                if (_obj_type == "player" && right._obj_type == "fire_up") {
                    _fire_up += 1;
                    right._obj.to_destroy = true;
                }
                if (_obj_type == "player" && right._obj_type == "speed_up") {
                    _speed += 0.2;
                    right._obj.to_destroy = true;
                }
                if (_obj_type == "player" && right._obj_type == "wall_pass") {
                    _wall_path = true;
                    _wall_time = float(clock()) / CLOCKS_PER_SEC;
                    right._obj.to_destroy = true;
                }
                if (_wall_path == false)
                    return true;
                else {
                    float tmp = float(clock()) / CLOCKS_PER_SEC;
                    if (tmp - _wall_time > 5)
                        _wall_path = false;
                    return false;
                }
            } else
                return false;
        }
    }

    void HitBox::set_destroy(bool value) {
        _to_destroy = value;
    }

    bool HitBox::get_destroy() {
        return _to_destroy;
    }

    void HitBox::refresh(IGameObj &obj, Engine &engine) {
        engine._collision_manager.add_hitbox(obj.get_object<HitBox>());
    }
}
