/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-louis-quentin.amsellem
** File description:
** ModelAnimation.cpp
*/

#include <raylib.h>
#include "my_model_animation.hpp"
#include <string>

namespace Raylib {

    MyModelAnimation::MyModelAnimation(const std::string &filename) :
        _anim_count(0) {
        this->_modelanimation = LoadModelAnimations(filename.c_str(), &_anim_count);
    }

    MyModelAnimation::~MyModelAnimation() {
        UnloadModelAnimation(*this->_modelanimation);
    }

    ModelAnimation *MyModelAnimation::getModelAnimation() {
        return this->_modelanimation;
    }
}
