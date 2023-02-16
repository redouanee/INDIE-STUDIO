/*
** EPITECH PROJECT, 2022
** event_manager.hpp
** File description:
** header
*/

#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <raylib.h>
#include "raylib.hpp"
#include "my_vector2.hpp"


namespace Raylib {

    class EventManager {
    public:
        EventManager();
        ~EventManager();

        MyVector2 get_mouse_position(void);
        MyVector2 get_mouse_delta(void);

        //bool click_event(game_obj game_obj);
    };
};
#endif
