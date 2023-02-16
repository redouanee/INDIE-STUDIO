/*
** EPITECH PROJECT, 2022
** main_menu_obj.hpp
** File description:
** header
*/

#ifndef PAUSE_GAME_OBJ_HPP
#define PAUSE_GAME_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "font_game.hpp"
#include "button.hpp"

namespace Raylib {

    class PauseGameObj : public IGameObj {
    protected:
        Engine &_engine;
        std::vector<std::unique_ptr<IComponents>> _comps;
        MyTexture2D _texture_return;
        MyTexture2D _texture_setting;
        MyTexture2D _texture_save;
        MyTexture2D _texture_home;
        MyTexture2D _texture_font;
    public:
        PauseGameObj(Engine &engine);
        ~PauseGameObj();
        void start();
        void draw();
    };
}

#endif
