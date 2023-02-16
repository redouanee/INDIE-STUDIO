/*
** EPITECH PROJECT, 2022
** general_settings_obj.hpp
** File description:
** header
*/

#ifndef GENERAL_SETTINGS_OBJ_HPP
#define GENERAL_SETTINGS_OBJ_HPP

#include "components.hpp"
#include "game_object.hpp"
#include "my_rectangle.hpp"
#include "button.hpp"
#include "my_image.hpp"

namespace Raylib {

    class GeneralSettingsObj : public IGameObj {
    protected:
        Engine &_engine;
        std::vector<std::unique_ptr<IComponents>> _comps;
        MySound _sound;
        MyTexture2D _texture_return;
        MyRectangle _bounds_button_mute;
        MyRectangle _rect_mute;
        MyTexture2D _texture_mute;
        MyRectangle _bounds_button_unmute;
        MyRectangle _rect_unmute;
        MyTexture2D _texture_unmute;
        MyTexture2D _texture_font;
    public:
        GeneralSettingsObj(Engine &engine);
        ~GeneralSettingsObj();
        virtual void start();
        virtual void draw();
    };
}

#endif
