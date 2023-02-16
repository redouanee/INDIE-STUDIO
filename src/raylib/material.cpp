/*
** EPITECH PROJECT, 2022
** material.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_material.hpp"

namespace Raylib {

    MyMaterial::MyMaterial(const std::string &filename, std::vector<int> &material_count) {
        this->_material = *LoadMaterials(filename.c_str(), material_count.data());
    }

    MyMaterial::~MyMaterial() {}

    Material MyMaterial::get_material() {
        return this->_material;
    }
}
