/*
** EPITECH PROJECT, 2022
** my_music.hpp
** File description:
** header
*/

#ifndef MY_MUSIC_HPP
#define MY_MUSIC_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyMusic {
    private:
        struct Music _music;
    public:
        MyMusic(const std::string &filename);
        ~MyMusic();
        Music get_music();
        void play_music();
        void pause_music();
        void change_music(const std::string &filepath);
    };
};

#endif
