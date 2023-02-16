/*
** EPITECH PROJECT, 2022
** collision_manager.hpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "hit_box.hpp"
#include "collision_obj.hpp"

namespace Raylib {

    CollisionObj::CollisionObj(Engine &engine) : _engine(engine)
    {
    }

    CollisionObj::~CollisionObj()
    {
    }

    void CollisionObj::add_hitbox(HitBox &hitbox) {
        _list.push_back(hitbox);
    }

    bool CollisionObj::check_collision(HitBox &hitbox) {
        //printf("hitbox LIST = %d\n", _list.size());
        for (auto &obj : _list) {
            if (hitbox == obj.get())
                return true;
        }
        return false;
    }

    void CollisionObj::del_hitbox(HitBox &hitbox)
    {
        size_t i = 0;

        for (auto &obj : _list) {
            if (obj.get().get_destroy() == true) {
                printf("erased hitbox\n");
                exit(46);
                _list.erase(_list.begin() + i);
                return;
            }
            i++;
        }
    }

    void CollisionObj::update()
    {
        _list.clear();

        for (size_t i = 0; i < _engine._game_obj_list_game.size(); ++i) {
            auto &p = *_engine._game_obj_list_game[i];
            for (size_t i = 0; i < p._comps_list.size(); ++i) {
                auto &pc = *p._comps_list[i];
                pc.refresh(p, _engine);
            }
        }
    }
}
