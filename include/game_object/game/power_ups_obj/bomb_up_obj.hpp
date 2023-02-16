/*
** EPITECH PROJECT, 2022
** bomb_up_obj.hpp
** File description:
** header
*/

#ifndef BOMB_UP_OBJ_HPP
#define BOMB_UP_OBJ_HPP

#include "power_ups_obj.hpp"

namespace Raylib {

    class BombUpObj : public PowerUpsObj {
    private:

    public:
        void start() override;
        void draw() override;
    };
}

#endif
