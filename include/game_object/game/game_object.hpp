/*
** EPITECH PROJECT, 2022
** game_object.hpp
** File description:
** header
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#pragma once

#include <vector>
#include <memory>
#include "components.hpp"
#include "raylib.hpp"

namespace Raylib {

    class IComponents;

    class IGameObj {
    public:
        std::vector<std::unique_ptr<IComponents>> _comps_list;
        IGameObj() = default;
        ~IGameObj() = default;

        template<typename T, typename... Args>
        void push_back_comp(Args && ...args)
            {
                this->_comps_list.emplace_back(
                    std::make_unique<T>(std::forward<Args>(args)...));
            }
        template<typename T>
        T& get_object()
            {
                for (auto &comp : this->_comps_list) {
                    T *ret = dynamic_cast<T *>(comp.get());
                    if (ret != nullptr)
                        return *ret;
                }
            }
        virtual void start() = 0;
        virtual void draw() = 0;
        void save_game_obj(std::ofstream &save_file);

        bool to_destroy = false;
    };
}
#endif
