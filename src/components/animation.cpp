/*
** EPITECH PROJECT, 2022
** animation.cpp
** File description:
** functions
*/

#include "animation.hpp"
#include "hit_box.hpp"
#include "game_object.hpp"
#include "pnj_manager.hpp"

namespace Raylib {

    Animation::Animation(int anim_frame_counter,
                         const std::string &anim_path) :
        _anim_frame_counter(anim_frame_counter),
        _anim(anim_path)
    {

    }

    Animation::~Animation(){}

    void Animation::update(IGameObj &obj, Engine &engine) {
    }

    void Animation::draw(IGameObj &game_obj, Engine &engine) {
    }

    void Animation::refresh(IGameObj &obj, Engine &engine) {
    }
}
