/*
** EPITECH PROJECT, 2022
** my_material.hpp
** File description:
** header
*/

#ifndef MY_MATERIAL_HPP
#define MY_MATERIAL_HPP

#include <raylib.h>
#include <iostream>
#include <vector>

namespace Raylib {

    class MyMaterial {
        private:
            struct Material _material;
        public:
            MyMaterial(const std::string &filename, std::vector<int> &material_count);
            ~MyMaterial();
            Material get_material();
    };
};

#endif
