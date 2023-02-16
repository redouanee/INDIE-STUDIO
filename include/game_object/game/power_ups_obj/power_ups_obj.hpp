/*
** EPITECH PROJECT, 2022
** power_ups_obj.hpp
** File description:
** header
*/

#ifndef POWER_UPS_OBJ_HPP
#define POWER_UPS_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "my_texture2d.hpp"
#include "my_vector3.hpp"
#include "hit_box.hpp"
#include "my_color.hpp"

namespace Raylib {

    class PowerUpsObj : public IGameObj {
    public:
        PowerUpsObj();
        virtual ~PowerUpsObj();

        virtual void start() = 0;
        virtual void draw() = 0;
    };
}

#endif
