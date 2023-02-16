/*
** EPITECH PROJECT, 2022
** my_model_animation.hpp
** File description:
** header
*/

#ifndef MY_MODEL_ANIMATION_HPP
#define MY_MODEL_ANIMATION_HPP

#include <vector>
#include <raylib.h>
#include <string>

namespace Raylib {

    class MyModelAnimation {
    private:
        struct ModelAnimation *_modelanimation;
        unsigned int _anim_count;
    public:
        MyModelAnimation(const std::string &filename = "");
        ~MyModelAnimation();
        ModelAnimation *getModelAnimation();
    };
};

#endif
