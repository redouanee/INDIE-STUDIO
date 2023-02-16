/*
** EPITECH PROJECT, 2022
** engine.cpp
** File description:
** functions
*/

#include "raylib.hpp"
#include "game_object.hpp"

namespace Raylib {

    class FontGame : public IGameObj {
    private:
        Engine &_engine;
        MyTexture2D _texture_font_1_back;
        MyTexture2D _texture_font_1_mid;
        MyTexture2D _texture_font_1_for;
        MyTexture2D _texture_font_2_back;
        MyTexture2D _texture_font_2_mid;
        MyTexture2D _texture_font_2_for;
        MyTexture2D _texture_font_3_back;
        MyTexture2D _texture_font_3_mid;
        MyTexture2D _texture_font_3_for;
        MyTexture2D _texture_pause;
        float scrollingBack = 0.0f;
        float scrollingMid = 0.0f;
        float scrollingFore = 0.0f;
    public:
        FontGame(Engine &engine);
        ~FontGame();
        virtual void start();
        virtual void draw();
    };
}