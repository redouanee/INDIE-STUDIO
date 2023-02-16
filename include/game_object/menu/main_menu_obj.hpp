/*
** EPITECH PROJECT, 2022
** main_menu_obj.hpp
** File description:
** header
*/

#ifndef MAIN_MENU_OBJ_HPP
#define MAIN_MENU_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "my_rectangle.hpp"
#include "button.hpp"
#include "my_image.hpp"

namespace Raylib {

    class MainMenuObj : public IGameObj {
    protected:
        Engine &_engine;
    private:
        MySound _sound;
        MyRectangle _bounds_button_start;
        MyRectangle _rect_start;
        MyTexture2D _texture_start;
        MyRectangle _bounds_button_setting;
        MyRectangle _rect_setting;
        MyTexture2D _texture_setting;
        MyRectangle _bounds_button_exit;
        MyRectangle _rect_exit;
        MyTexture2D _texture_exit;
        MyTexture2D _texture_loaded;
        MyTexture2D _texture_font;
    public:
        MainMenuObj(Engine &engine);
        ~MainMenuObj();
        virtual void start();
        virtual void draw();
    };
}

#endif
