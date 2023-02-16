/*
** EPITECH PROJECT, 2022
** camera.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_camera.hpp"

namespace Raylib {

    MyCamera::MyCamera(MyVector3 pos, MyVector3 target, MyVector3 up, float fovy,
                       int mode)
    {
        this->_camera.position = pos.get_vector();
        this->_camera.target = target.get_vector();
        this->_camera.up = up.get_vector();
        this->_camera.fovy = fovy;
        this->_camera.projection = mode;
    }

    void MyCamera::start_3d()
    {
        BeginMode3D(this->_camera);
    }

    MyCamera::~MyCamera() {
    }

    Camera MyCamera::get_camera(void)
    {
        return this->_camera;
    }

    void MyCamera::stop_3d()
    {
        EndMode3D();
    }
}
