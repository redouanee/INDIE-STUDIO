/*
** EPITECH PROJECT, 2022
** collision_obj.hpp
** File description:
** header
*/

#ifndef SOUND_OBJ_HPP
#define SOUND_OBJ_HPP

#include <memory>
#include <vector>
#include <string>
#include "my_music.hpp"
#include "my_sound.hpp"
//#include "raylib.hpp"

namespace Raylib {

    class Engine;

    class SoundObj {
    private:
        Engine &_engine;
        MyMusic _music;
        std::vector<MySound> _list;
    public:

        SoundObj(Engine &engine, const std::string &music_path =
                 "../assets/music/menu_sound.wav");
        ~SoundObj();

        void add_sound(const std::string &filename, Engine &engine);
        void update();
        void pause_music();
        void play_music();
        Music get_music();
        void play_sound(MySound &sound);
        void change_music(const std::string &filepath);
    };
}

#endif
