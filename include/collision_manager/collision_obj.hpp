/*
** EPITECH PROJECT, 2022
** collision_obj.hpp
** File description:
** header
*/

#ifndef COLLISION_OBJ_HPP
#define COLLISION_OBJ_HPP

#include <fstream>
#include <iostream>
#include <vector>

namespace Raylib {
    class HitBox;
    class Engine;

    class CollisionObj {
    private:
        Engine &_engine;
        std::vector<std::reference_wrapper<HitBox>> _list;
    public:

        CollisionObj(Engine &engine);
        ~CollisionObj();
        void add_hitbox(HitBox &hitbox);
        void del_hitbox(HitBox &hitbox);
        bool check_collision(HitBox &hitbox);
        void update();
    };
}

#endif
