/*
** EPITECH PROJECT, 2022
** my_model.hpp
** File description:
** header
*/

#ifndef MY_MODEL_HPP
#define MY_MODEL_HPP

#include <raylib.h>
#include <string>

namespace Raylib {

    class MyModel {
    private:
        struct Model _model;
    public:
        MyModel(const std::string &filename = "");
        ~MyModel();
        Model &getModel();
    };
};

#endif
