/*
** EPITECH PROJECT, 2022
** blocks_obj.hpp
** File description:
** header
*/

#ifndef BLOCKS_OBJ_HPP
#define BLOCKS_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "my_texture2d.hpp"
#include "my_vector3.hpp"
#include "hit_box.hpp"
#include "my_color.hpp"

namespace Raylib {

    class BlocksObj : public IGameObj {
    public:
        BlocksObj();
        virtual ~BlocksObj();

        virtual void start() = 0;
        virtual void draw() = 0;
    };
}

#endif
