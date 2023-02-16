/*
** EPITECH PROJECT, 2022
** my_image.hpp
** File description:
** header
*/

#ifndef MY_IMAGE_HPP
#define MY_IMAGE_HPP

#include <raylib.h>
#include <iostream>

namespace Raylib {

    class MyImage {
        private:
            struct Image _image;
        public:
            MyImage(const std::string &filename = "");
            ~MyImage();
            void set_image(Image image);
            Image get_image();
    };
};

#endif
