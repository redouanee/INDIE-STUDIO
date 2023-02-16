/*
** EPITECH PROJECT, 2022
** power_up.hpp
** File description:
** header
*/

#ifndef POWER_UP_HPP
#define POWER_UP_HPP

#include "components.hpp"

namespace Raylib {

    class PowerUp : public IComponents{
    private:
        struct power_up
        {
            int difficulties;
            double time;
        };
        power_up _speed;
        power_up _bomb;
        power_up _fire;
        power_up _wall_pass;
    public:
        PowerUp(power_up speed, power_up bomb, power_up fire, power_up wall_pass);
        ~PowerUp();

        void update(IGameObj &game_obj, Engine &engine);
        void draw(IGameObj &game_obj, Engine &engine);
        void refresh(IGameObj &obj, Engine &engine);
    };
};

#endif
