/*
** EPITECH PROJECT, 2022
** engine.cpp
** File description:
** functions
*/

#include "pause_game_obj.hpp"
#include "button.hpp"

namespace Raylib {
    FontGame::FontGame(Engine &engine) : _engine(engine),
                                        _texture_font_1_back("../assets/menu/cyberpunk_street_back.png"),
                                        _texture_font_1_mid("../assets/menu/cyberpunk_street_mid.png"),
                                        _texture_font_1_for("../assets/menu/cyberpunk_street_fore.png"),
                                        _texture_font_2_back("../assets/menu/parallax-mountain-bg.png"),
                                        _texture_font_2_mid("../assets/menu/parallax-mountain-mountains.png"),
                                        _texture_font_2_for("../assets/menu/parallax-mountain-montain-far.png"),
                                        _texture_font_3_back("../assets/menu/Sky-layer.png"),
                                        _texture_font_3_mid("../assets/menu/buildings-layer.png"),
                                        _texture_pause("../assets/menu/pause.png")
    {
        start();
    }

    FontGame::~FontGame(){};

    void FontGame::start()
    {
        push_back_comp<Button> (_texture_pause, 1250.0f, 525.0f, 150.0f, 100.0f, [this](){
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._can_start = false;
            _engine.push_back_obj<PauseGameObj>(_engine);
        });
    }

    void FontGame::draw() {
        _texture_font_1_back.set_texture_grather(900.0f, 500.0f);
        _texture_font_1_mid.set_texture_grather(900.0f, 500.0f);
        _texture_font_1_for.set_texture_grather(900.0f, 500.0f);
        _texture_font_2_back.set_texture_grather(900.0f, 500.0f);
        _texture_font_2_mid.set_texture_grather(900.0f, 500.0f);
        _texture_font_2_for.set_texture_grather(900.0f, 500.0f);
        _texture_font_3_back.set_texture_grather(900.0f, 500.0f);
        _texture_font_3_mid.set_texture_grather(900.0f, 500.0f);
        scrollingBack -= 0.1f;
        scrollingMid -= 0.5f;
        scrollingFore -= 1.0f;
        if (_engine._font_game == 0) {
            if (scrollingBack <= -_texture_font_1_back.get_texture_2d().width*2)
                scrollingBack = 0;
            if (scrollingMid <= -_texture_font_1_mid.get_texture_2d().width*2)
                scrollingMid = 0;
            if (scrollingFore <= -_texture_font_1_for.get_texture_2d().width*2)
                scrollingFore = 0;
            DrawTextureEx(_texture_font_1_back.get_texture_2d() , (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_1_back.get_texture_2d() , (Vector2){ _texture_font_1_back.get_texture_2d().width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_1_mid.get_texture_2d(), (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_1_mid.get_texture_2d(), (Vector2){ _texture_font_1_mid.get_texture_2d().width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_1_for.get_texture_2d(), (Vector2){ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_1_for.get_texture_2d(), (Vector2){ _texture_font_1_for.get_texture_2d().width*2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
        } else if (_engine._font_game == 1)  {
            if (scrollingBack <= -_texture_font_2_back.get_texture_2d().width*2)
                scrollingBack = 0;
            if (scrollingMid <= -_texture_font_2_mid.get_texture_2d().width*2)
                scrollingMid = 0;
            if (scrollingFore <= -_texture_font_2_for.get_texture_2d().width*2)
                scrollingFore = 0;
            DrawTextureEx(_texture_font_2_back.get_texture_2d() , (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_2_back.get_texture_2d() , (Vector2){ _texture_font_2_back.get_texture_2d().width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_2_mid.get_texture_2d(), (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_2_mid.get_texture_2d(), (Vector2){ _texture_font_2_mid.get_texture_2d().width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_2_for.get_texture_2d(), (Vector2){ scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_2_for.get_texture_2d(), (Vector2){ _texture_font_2_for.get_texture_2d().width*2 + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
        } else {
            if (scrollingBack <= -_texture_font_3_back.get_texture_2d().width*2)
                scrollingBack = 0;
            if (scrollingMid <= -_texture_font_3_mid.get_texture_2d().width*2)
                scrollingMid = 0;
            if (scrollingFore <= -_texture_font_3_for.get_texture_2d().width*2)
                scrollingFore = 0;
            DrawTextureEx(_texture_font_3_back.get_texture_2d() , (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_3_back.get_texture_2d() , (Vector2){ _texture_font_3_back.get_texture_2d().width*2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_3_mid.get_texture_2d(), (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(_texture_font_3_mid.get_texture_2d(), (Vector2){ _texture_font_3_mid.get_texture_2d().width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
        }
    }
}