/*
** EPITECH PROJECT, 2022
** my_camera.hpp
** File description:
** header
*/

#ifndef MY_CAMERA_HPP
#define MY_CAMERA_HPP

#include <raylib.h>
#include "my_vector3.hpp"

namespace Raylib {

    class MyCamera {
    private:
        Camera _camera;
    public:
        MyCamera(MyVector3 pos = {0, 50, 15},
                MyVector3 target = {0, 0, 0},
                MyVector3 up = {0, 1, 0},
                float fovy = 45.0f,
                int mode = CAMERA_PERSPECTIVE);
        ~MyCamera();

        Camera get_camera(void);
        void update();

        void start_3d();
        void stop_3d();
    };
};

#endif
