/*
** EPITECH PROJECT, 2022
** wave.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_wave.hpp"

namespace Raylib {

    MyWave::MyWave(const std::string &filename) {
        this->_wave = LoadWave(filename.c_str());
    }

    MyWave::~MyWave() {
        UnloadWave(this->_wave);
    }

    Wave MyWave::get_wave(void)
    {
        return this->_wave;
    }
}
