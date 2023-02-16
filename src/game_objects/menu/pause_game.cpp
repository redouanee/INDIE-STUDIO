/*
** EPITECH PROJECT, 2022
** pause_game.cpp
** File description:
** functions
*/

#include "pause_game_obj.hpp"
#include "general_settings_obj.hpp"
#include "button.hpp"

namespace Raylib {

    PauseGameObj::PauseGameObj(Engine &engine) : _engine(engine),
                                                _texture_return("../assets/menu/back.png"),
                                                _texture_setting("../assets/menu/setting.png"),
                                                _texture_save("../assets/menu/save.png"),
                                                _texture_home("../assets/menu/home.png"),
                                                _texture_font("../assets/menu/font_menu_pause.png")
    {
        start();
    }

    PauseGameObj::~PauseGameObj()
    {
    }

    void PauseGameObj::start()
    {
        push_back_comp<Button> (_texture_return, 683.0f, -500.0f, 370.0f, 120.0f, [this](){
            printf("return\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._can_start = true;
            _engine.push_back_obj<FontGame>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_setting, 683.0f, 400.0f, 280.0f, 100.0f, [this](){
            printf("setting\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._return = false;
            _engine.push_back_obj<GeneralSettingsObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_save, 683.0f, -200.0f, 300.0f, 120.0f, [this](){
            printf("save\n");
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
            _engine.save_map();
        });
        push_back_comp<Button> (_texture_home, 683.0f, 100.0f, 280.0f, 100.0f, [this](){
            printf("home\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._return = true;
            _engine.push_back_obj<MainMenuObj>(_engine);
            _engine._sound_manager.change_music("../assets/music/menu_sound.wav");
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
    }

    void PauseGameObj::draw()
    {
        _texture_font.set_texture_grather(1366.0f, 768.0f);
        DrawTexture(_texture_font.get_texture_2d(), 1366/2 - _texture_font.get_texture_2d().width/2, 50, WHITE);
    }
}
