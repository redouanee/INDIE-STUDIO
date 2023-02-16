/*
** EPITECH PROJECT, 2022
** my_wave.hpp
** File description:
** header
*/

#ifndef MY_WAVE_HPP
#define MY_WAVE_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyWave {
    private:
        struct Wave _wave;
    public:
        MyWave(const std::string &filename = "");
        ~MyWave();
        bool export_wave(const std::string &filename);
        Wave get_wave(void);
    };
};

#endif
