/*
** EPITECH PROJECT, 2022
** hit_box.hpp
** File description:
** header
*/

#ifndef HIT_BOX_HPP
#define HIT_BOX_HPP

#include "raylib.hpp"
#include "components.hpp"
#include "my_vector3.hpp"
#include "my_sound.hpp"

enum Direction{
    UP,
    LEFT,
    DOWN,
    RIGHT
};

namespace Raylib {

    class HitBox : public IComponents {
    private:
        bool _to_destroy = false;
        bool _touch;
        bool _is_moving;
        int _id;
        std::string tmp_direction;
        int detect_coll;
        IGameObj &_obj;
        MyVector3 _pos;
        MyVector3 _size;
        MyVector3 _tmp;
        Engine &_engine;
        std::string _obj_type;
        int _fire_up = 0;
        int _rand_1;
        int _rand_2;
        int _rand_3;
        int _rand_4;

        float _speed = 1;
        bool _wall_path = false;
        float _wall_time;
        //MySound _sound;
    public:
        Direction _direction;
        HitBox(MyVector3 pos, MyVector3 size, bool touch, bool _is_moving, IGameObj &_obj,
               Engine &engine, const std::string &_obj_type /*, const std::string &sound_path*/);
        HitBox(MyVector3 pos, MyVector3 size, bool touch, bool _is_moving, int id, IGameObj &_obj,
               Engine &engine, const std::string &_obj_type /*, const std::string &sound_path*/);
        ~HitBox();

        void update(IGameObj &game_obj, Engine &engine);
        void draw(IGameObj &game_obj, Engine &engine);
        MyVector3 get_pos() const;
        MyVector3 get_tmp() const;
        MyVector3 get_size() const;
        bool get_is_moving();
        void move_player();
        void move_bot();
        std::string directions();
        bool operator==(HitBox const &right);
        void set_destroy(bool value);
        bool get_destroy();
        void refresh(IGameObj &obj, Engine &engine);
    };
};

#endif
