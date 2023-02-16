/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-louis-quentin.amsellem
** File description:
** model.cpp
*/

#include <raylib.h>
#include "my_model.hpp"

namespace Raylib {

    MyModel::MyModel(const std::string &filename) {
        this->_model = LoadModel(filename.c_str());
    }
    MyModel::~MyModel() {
        UnloadModel(this->_model);
    }
    Model &MyModel::getModel() {
        return this->_model;
    }
}
