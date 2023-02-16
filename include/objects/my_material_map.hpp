/*
** EPITECH PROJECT, 2022
** my_material_map.hpp
** File description:
** header
*/

#ifndef MY_MATERIAL_MAP_HPP
#define MY_MATERIAL_MAP_HPP

#include <raylib.h>

namespace Raylib {

    class MyMaterialMap {
        private:
            struct MaterialMap _material_map;
        public:
            MyMaterialMap();
            ~MyMaterialMap();
            MaterialMap get_material_map();
    };
};

#endif
