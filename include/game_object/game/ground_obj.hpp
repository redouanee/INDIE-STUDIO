/*
** EPITECH PROJECT, 2022
** ground_obj.hpp
** File description:
** header
*/

#ifndef GROUND_OBJ_HPP
#define GROUND_OBJ_HPP

#include "blocks_obj.hpp"

namespace Raylib {

    class GroundObj : public BlocksObj {
    private:
        Engine &_engine;
        MyModel _model;
        MyTexture2D _texture;
    public:
        GroundObj(Engine &engine, const std::string &model_path = "",
            const std::string &texture_path = "", const std::string &anim_path = "");
        ~GroundObj();

        void start();
        void draw();
    };
}

#endif
