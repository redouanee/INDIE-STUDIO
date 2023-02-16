/*
** EPITECH PROJECT, 2022
** bouton.cpp
** File description:
** functions
*/

#include <cstring>
#include "button.hpp"

namespace Raylib {

    Button::Button(MyTexture2D &texture, float pos_x, float pos_y, float a, float b,
                    std::function<void()> function) : _texture(texture),
                                                    _pos_x(pos_x),
                                                    _pos_y(pos_y),
                                                    _a(a),
                                                    _b(b),
                                                    _function(function)
    {
       _texture.set_texture_grather(a, b);
        _rect.set_rectangle(0, 0, (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
        _bounds_button.set_rectangle(_pos_x - _texture.get_texture_2d().width/2.0f,
                                    (768 - _pos_y)/2.0f - _texture.get_texture_2d().height/2.0f,
                                    (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
        _button_action = false;
        _vect.set_vector_x(0.0f);
        _vect.set_vector_y(0.0f);
        _mouse.set_vector_x(0.0f);
        _mouse.set_vector_y(0.0f);
    }

    Button::~Button() {}

    void Button::update(IGameObj &game_obj, Engine &engine) {
        _mouse.set_vector(GetMousePosition());
        _button_action = false;

        if (CheckCollisionPointRec(_mouse.get_vector(), _bounds_button.get_rectangle())) {
            _texture.set_texture_grather(_a + 20.0f, _b + 20.0f);
            _rect.set_rectangle(0, 0, (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
            _bounds_button.set_rectangle(_pos_x - _texture.get_texture_2d().width/2.0f,
                                    (768 - _pos_y)/2.0f - _texture.get_texture_2d().height/2.0f,
                                    (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                _button_action = true;
        } else {
            _texture.set_texture_grather(_a, _b);
            _rect.set_rectangle(0, 0, (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
            _bounds_button.set_rectangle(_pos_x - _texture.get_texture_2d().width/2.0f,
                                    (768 - _pos_y)/2.0f - _texture.get_texture_2d().height/2.0f,
                                    (float)_texture.get_texture_2d().width, _texture.get_texture_2d().height);
        }
        if (_button_action)
            _function();
        _vect.set_vector_x(_bounds_button.get_rectangle().x);
        _vect.set_vector_y(_bounds_button.get_rectangle().y);
    }

    void Button::draw(IGameObj &game_obj, Engine &engine) {
        DrawTextureRec(_texture.get_texture_2d(), _rect.get_rectangle(), _vect.get_vector(), WHITE);
    }

    void Button::refresh(IGameObj &obj, Engine &engine)
    {
    }
}
