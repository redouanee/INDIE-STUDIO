/*
** EPITECH PROJECT, 2022
** general_settings.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "general_settings_obj.hpp"
#include "pause_game_obj.hpp"
#include "main_menu_obj.hpp"

namespace Raylib {

    GeneralSettingsObj::GeneralSettingsObj(Engine &engine) : _engine(engine),
                                                            _sound("../assets/music/test_music_1.mp3"),
                                                            _texture_mute("../assets/menu/mute.png"),
                                                            _texture_unmute("../assets/menu/unmute.png"),
                                                            _texture_return("../assets/menu/return.png"),
                                                            _texture_font("../assets/menu/among_us.png")
    {
        printf("GENERAL SETTINGS\n");
        start();
    }

    GeneralSettingsObj::~GeneralSettingsObj() {}

    void GeneralSettingsObj::start()
    {
        push_back_comp<Button> (_texture_mute, 960.0f, 400.0f, 150.0f, 100.0f, [this](){
            printf("mute\n");
            _engine._sound_manager.pause_music();
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_unmute, 920.0f, 0.0f, 150.0f, 100.0f, [this](){
            printf("unmute\n");
            _engine._sound_manager.play_music();
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_return, 920.0f, -400.0f, 150.0f, 100.0f, [this](){
            printf("return\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            if (_engine._return)
                _engine.push_back_obj<MainMenuObj>(_engine);
            else
                _engine.push_back_obj<PauseGameObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
    }

    void GeneralSettingsObj::draw() {
        _texture_font.set_texture_grather(1920.0f, 1080.0f);
        DrawTexture(_texture_font.get_texture_2d(), 1366/2 - _texture_font.get_texture_2d().width/2, 50, WHITE);
    }
}
