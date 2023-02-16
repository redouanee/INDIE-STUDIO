/*
** EPITECH PROJECT, 2022
** bomb.cpp
** File description:
** functions
*/

#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>
#include "bomb_obj.hpp"
#include "flame_obj.hpp"

namespace Raylib {

    BombObj::BombObj(Engine &engine, int fire_up, MyModel &model, MyTexture2D &texture,
        MyModelAnimation &anim, MyVector3 pos, MyVector3 size) :
        _engine(engine), _model(model), _texture(texture),
        _anim(anim), _fire_up(fire_up), _pos(pos), _size(size) {
        SetMaterialTexture(&_model.getModel().materials[0],
            MATERIAL_MAP_DIFFUSE, _texture.get_texture_2d());
        _model.getModel().transform = MatrixRotateXYZ(
            (Vector3) {1.6f, 0.0f, 0.0f});
        start();
    }

    BombObj::~BombObj()
    {
    }

    void BombObj::start() {}

    void BombObj::draw() {
        clock_t _time = clock();
        float tmp = float(_time) / CLOCKS_PER_SEC;
        if (tmp - _time_explosion > 2) {
            _pos.set_vector_y(1);
            MyVector3 tmp = _pos;
            to_destroy = true;
            _engine._sound_manager.play_sound(
                _engine._assets_manager.load_sound(
                    "../assets/music/explosion_bomb.wav"));
            _engine.push_back_obj_game<FlameObj>(_engine,
                                                 _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                 _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                 _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                 _pos, MyVector3 (1.0f, 1.0f, 1.0f));
            tmp.set_vector_x(1.5);
            _engine.push_back_obj_game<FlameObj>(_engine,
                                                 _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                 _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                 _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                 tmp, MyVector3 (1.0f, 1.0f, 1.0f));
            tmp.set_vector_x(-3);
            _engine.push_back_obj_game<FlameObj>(_engine,
                                                 _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                 _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                 _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                 tmp, MyVector3 (1.0f, 1.0f, 1.0f));
            tmp.set_vector_x(1.5);
            tmp.set_vector_z(1.5);
            _engine.push_back_obj_game<FlameObj>(_engine,
                                                 _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                 _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                 _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                 tmp, MyVector3 (1.0f, 1.0f, 1.0f));
            tmp.set_vector_z(-3);
            _engine.push_back_obj_game<FlameObj>(_engine,
                                                 _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                 _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                 _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                 tmp, MyVector3 (1.0f, 1.0f, 1.0f));
            tmp.set_vector_z(1.5);
            if (_fire_up > 0) {
                for (int i = 0; i < _fire_up; i++) {
                    tmp.set_vector_x((1.5) * (i + 2));
                    _engine.push_back_obj_game<FlameObj>(_engine,
                                                        _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                        _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                        _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                        tmp, MyVector3 (1.0f, 1.0f, 1.0f));
                    tmp.set_vector_x((-3) * (i + 2));
                    _engine.push_back_obj_game<FlameObj>(_engine,
                                                        _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                        _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                        _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                        tmp, MyVector3 (1.0f, 1.0f, 1.0f));
                    tmp.set_vector_x((1.5) * (i + 2));
                    tmp.set_vector_z((1.5) * (i + 2));
                    _engine.push_back_obj_game<FlameObj>(_engine,
                                                        _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                        _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                        _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                        tmp, MyVector3 (1.0f, 1.0f, 1.0f));
                    tmp.set_vector_z((-3) * (i + 2));
                    _engine.push_back_obj_game<FlameObj>(_engine,
                                                        _engine._assets_manager.load_model("../assets/flame.iqm"),
                                                        _engine._assets_manager.load_texture_2d("../assets/flame_texture.png"),
                                                        _engine._assets_manager.load_model_animation("../assets/flame_anim.iqm"),
                                                        tmp, MyVector3 (1.0f, 1.0f, 1.0f));
                    tmp.set_vector_z((1.5) * (i + 2));
                }
            }
        }
        if (tmp - _time_anim > 0.05) {
            _anim_frame_counter++;
            UpdateModelAnimation(this->_model.getModel(),
                                 _anim.getModelAnimation()[0],
                                 _anim_frame_counter);
            if (_anim_frame_counter >= _anim.getModelAnimation()[0].frameCount)
                _anim_frame_counter = 0;
        }
        DrawModel(_model.getModel(), _pos.get_vector(), 2.3f, WHITE);
    }
}
