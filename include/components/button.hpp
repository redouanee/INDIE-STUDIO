/*
** EPITECH PROJECT, 2022
** bouton.hpp
** File description:
** header
*/

#ifndef BOUTON_HPP
#define BOUTON_HPP

#include <functional>
#include "components.hpp"
#include "my_rectangle.hpp"
#include "my_sound.hpp"
#include "my_texture2d.hpp"
#include "my_vector2.hpp"
#include "raylib.hpp"
#include "main_menu_obj.hpp"

namespace Raylib {

    class Button : public IComponents{
    private:
        bool _button_action;
        float _pos_x;
        float _pos_y;
        float _a;
        float _b;
        std::function<void()> _function;
        MyVector2 _mouse;
        MyVector2 _vect;
        MyRectangle _bounds_button;
        MyRectangle _rect;
        //MySound _sound;
        MyTexture2D _texture;

    public:
        Button(MyTexture2D &texture, float pos_x, float pos_y, float a, float b, std::function<void()> function);
        ~Button();

        void draw(IGameObj &game_obj, Engine &engine);
        void update(IGameObj &game_obj, Engine &engine);
        void refresh(IGameObj &obj, Engine &engine);
    };
};

#endif
