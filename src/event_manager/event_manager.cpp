/*
** EPITECH PROJECT, 2022
** event_manager.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "event_manager.hpp"
#include "my_vector2.hpp"

namespace Raylib {

    EventManager::EventManager()
    {
    }

    EventManager::~EventManager()
    {
    }

    MyVector2 EventManager::get_mouse_position(void)
    {
        struct Vector2 vector = GetMousePosition();
        MyVector2 vec(vector.x, vector.y);
        return vec;
    }

    MyVector2 EventManager::get_mouse_delta(void)
    {
        struct Vector2 vector = GetMouseDelta();
        MyVector2 vec(vector.x, vector.y);
        return vec;
    }
}
