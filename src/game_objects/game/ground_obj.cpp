/*
** EPITECH PROJECT, 2022
** ground.cpp
** File description:
** functions
*/

#include "ground_obj.hpp"

namespace Raylib {

    GroundObj::GroundObj(Engine &engine, const std::string &model_path, const std::string &texture_path, const std::string &anim_path) :
        _engine(engine), _model(model_path), _texture(texture_path) {
        SetMaterialTexture(&_model.getModel().materials[0], MATERIAL_MAP_DIFFUSE, _texture.get_texture_2d());
        start();
    }

    GroundObj::~GroundObj()
    {
    }

    void GroundObj::start() {}

    void GroundObj::draw() {
        DrawModel(_model.getModel(), get_object<HitBox>().get_pos().get_vector(), 1.0f, WHITE);
    }
}
