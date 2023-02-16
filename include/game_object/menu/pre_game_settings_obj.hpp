/*
** EPITECH PROJECT, 2022
** main_menu_obj.hpp
** File description:
** header
*/

#ifndef PRE_GAME_SETTINGS_OBJ_HPP
#define PRE_GAME_SETTINGS_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "button.hpp"

namespace Raylib {

    class PreGameSettingsObj : public IGameObj {
    protected:
        Engine &_engine;
        std::vector<std::unique_ptr<IComponents>> _comps;
        MyTexture2D _texture_right;
        MyTexture2D _texture_left;
        MyTexture2D _texture_font;
        MyTexture2D _texture_launch;
        MyTexture2D _texture_return;
    public:
        PreGameSettingsObj(Engine &engine);
        ~PreGameSettingsObj();
        virtual void start();
        virtual void draw();
    };
}

#endif
