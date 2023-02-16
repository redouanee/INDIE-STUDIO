/*
** EPITECH PROJECT, 2022
** sound.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_sound.hpp"

namespace Raylib {

    MySound::MySound(const std::string &filename) {
        this->_sound = LoadSound(filename.c_str());
    }

    MySound::~MySound() {
        UnloadSound(this->_sound);
    }

    Sound MySound::get_sound(void)
    {
        return this->_sound;
    }

    void MySound::play_sound(void)
    {
        PlaySound(_sound);
    }
}
