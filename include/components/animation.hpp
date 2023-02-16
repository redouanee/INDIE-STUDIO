/*
** EPITECH PROJECT, 2022
** Animation.hpp
** File description:
** header
*/

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "my_model_animation.hpp"
#include "hit_box.hpp"

namespace Raylib {

    class Animation : public IComponents{
    private:
        int _anim_frame_counter;
        MyModelAnimation _anim;

    public:
        Animation(int anim_frame_counter,
                  const std::string &anim_path);
        ~Animation();

        void update(IGameObj &obj, Engine &engine);
        void draw(IGameObj &obj, Engine &engine);
        void refresh(IGameObj &obj, Engine &engine);
    };
};

#endif
