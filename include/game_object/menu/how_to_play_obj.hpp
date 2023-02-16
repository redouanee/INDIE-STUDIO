/*
** EPITECH PROJECT, 2022
** how_to_play_obj.hpp
** File description:
** header
*/

#ifndef HOW_TO_PLAY_OBJ_HPP
#define HOW_TO_PLAY_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "raylib.hpp"

namespace Raylib {

    class HowToPlayObj : public IGameObj {
    protected:
        Engine &_engine;
        std::vector<std::unique_ptr<IComponents>> _comps;
    public:
        HowToPlayObj(Engine &engine);
        ~HowToPlayObj();
        void start();
        void draw();
    };
}

#endif
