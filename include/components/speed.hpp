/*
** EPITECH PROJECT, 2022
** speed.hpp
** File description:
** header
*/

#ifndef SPEED_HPP
#define SPEED_HPP

#include "components.hpp"

namespace Raylib {

    class Speed : public IComponents{
    private:
        int _speed;

    public:
        Speed(int _speed);
        ~Speed();

        void update(IGameObj &game_obj, Engine &engine);
        void draw(IGameObj &game_obj, Engine &engine);
        void refresh(IGameObj &obj, Engine &engine);
    };
};

#endif
