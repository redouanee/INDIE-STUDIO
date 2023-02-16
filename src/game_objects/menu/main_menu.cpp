/*
** EPITECH PROJECT, 2022
** main_menu.cpp
** File description:
** functions
*/

#include "main_menu_obj.hpp"
#include "general_settings_obj.hpp"
#include "pause_game_obj.hpp"
#include "pre_game_settings_obj.hpp"

namespace Raylib {

    MainMenuObj::MainMenuObj(Engine &engine) : _engine(engine),
                                               _sound("../assets/music/test_music_1.mp3"),
                                               _texture_start("../assets/menu/start.png"),
                                               _texture_setting("../assets/menu/setting.png"),
                                               _texture_exit("../assets/menu/quit.png"),
                                               _texture_loaded("../assets/menu/load.png"),
                                               _texture_font("../assets/menu/bomberman.png")
    {
        printf("MAIN MENU\n");
        start();
    }

    MainMenuObj::~MainMenuObj()
    {
    }

    void MainMenuObj::start()
    {
        push_back_comp<Button> (_texture_start, 830.0f, 0.0f, 335.0f, 120.0f, [this](){
            printf("start\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._can_start = false;
            _engine.push_back_obj<PreGameSettingsObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_loaded, 510.0f, 0.0f, 280.0f, 100.0f, [this](){
            printf("loaded\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._can_start = false;
            _engine.push_back_obj<PreGameSettingsObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_setting, 920.0f, 400.0f, 280.0f, 100.0f, [this](){
            printf("settings\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine.push_back_obj<GeneralSettingsObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_exit, 920.0f, -400.0f, 280.0f, 100.0f, [this](){
            printf("exit\n");
            _engine._close = true;
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
    }

    void MainMenuObj::draw()
    {
        _texture_font.set_texture_grather(1366.0f, 768.0f);
        DrawTexture(_texture_font.get_texture_2d(), 1366/2 - _texture_font.get_texture_2d().width/2, 50, WHITE);
    }
}
