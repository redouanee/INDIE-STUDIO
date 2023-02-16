/*
** EPITECH PROJECT, 2022
** Background_obj.hpp
** File description:
** header
*/

#ifndef BACKGROUND_OBJ_HPP
#define BACKGROUND_OBJ_HPP

#include <vector>

namespace Raylib {

    class Engine;

    class BackGroundObj {
    private:
        Engine &_engine;
    public:

        BackGroundObj(Engine &_engine);
        ~BackGroundObj() = default;
        void update();
        void draw();
    };
}

#endif
