/*
** EPITECH PROJECT, 2022
** power_up.cpp
** File description:
** functions
*/

#include "power_up.hpp"

namespace Raylib {

    PowerUp::PowerUp(power_up speed, power_up bomb,
                    power_up fire, power_up wall_pass) : _speed(speed), _bomb(bomb),
                                                        _fire(fire), _wall_pass(wall_pass) {}

    PowerUp::~PowerUp() {}

    void PowerUp::update(IGameObj &game_obj, Engine &engine) {}

    void PowerUp::draw(IGameObj &game_obj, Engine &engine) {}

    void PowerUp::refresh(IGameObj &obj, Engine &engine)
    {
    }
}
