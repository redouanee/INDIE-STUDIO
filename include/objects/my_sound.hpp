/*
65;6602;1c** EPITECH PROJECT, 2022
** my_sound.hpp
** File description:
** header
*/

#ifndef MY_SOUND_HPP
#define MY_SOUND_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MySound {
    private:
        struct Sound _sound;
    public:
        MySound(const std::string &filename = "");
        ~MySound();
        Sound get_sound(void);
        void play_sound(void);
    };
};

#endif
