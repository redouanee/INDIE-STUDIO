/*
** EPITECH PROJECT, 2022
** material_map.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_material_map.hpp"

namespace Raylib {

    MyMaterialMap::MyMaterialMap() {}

    MyMaterialMap::~MyMaterialMap() {}

    MaterialMap MyMaterialMap::get_material_map() {
        return this->_material_map;
    }
}
