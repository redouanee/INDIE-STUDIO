/*
** EPITECH PROJECT, 2022
** components.hpp
** File description:
** header
*/

#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#pragma once

#include "game_object.hpp"

namespace Raylib {

    class IComponents {
    public:
        IComponents() = default;
        virtual ~IComponents() = default;

        virtual void update(IGameObj &game_obj, Engine &engine) = 0;
        virtual void draw(IGameObj &game_obj, Engine &engine) = 0;
        virtual void refresh(IGameObj &game_obj, Engine &engine) = 0;
    };
};

#endif
