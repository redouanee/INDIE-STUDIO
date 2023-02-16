/*
** EPITECH PROJECT, 2022
** image.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_image.hpp"

namespace Raylib {

    MyImage::MyImage(const std::string &filename) {
        this->_image = LoadImage(filename.c_str());
    }

    MyImage::~MyImage() {
        UnloadImage(this->_image);
    }

    void MyImage::set_image(Image image) {
        this->_image = image;
    }

    Image MyImage::get_image() {
        return this->_image;
    }
}
