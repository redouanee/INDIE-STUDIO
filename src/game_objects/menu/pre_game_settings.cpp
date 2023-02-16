/*
** EPITECH PROJECT, 2022
** pre_game_settings.cpp
** File description:
** functions
*/

#include "pre_game_settings_obj.hpp"
#include "font_game.hpp"

namespace Raylib {

    PreGameSettingsObj::PreGameSettingsObj(Engine &engine) : _engine(engine),
                                                            _texture_launch("../assets/menu/launch.png"),
                                                            _texture_right("../assets/menu/fleche_droite.png"),
                                                            _texture_left("../assets/menu/fleche_gauche.png"),
                                                            _texture_return("../assets/menu/return.png"),
                                                            _texture_font("../assets/menu/font_art.png")
    {
        start();
    }

    PreGameSettingsObj::~PreGameSettingsObj()
    {
    }

    void PreGameSettingsObj::start()
    {
        push_back_comp<Button> (_texture_launch, 683.0f, 0.0f, 225.0f, 175.0f, [this](){
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine._can_start = true;
            _engine.push_back_obj<FontGame>(_engine);
            _engine._sound_manager.change_music("../assets/music/ingame_mus.wav");
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
            _engine.build_map();
        });
        push_back_comp<Button> (_texture_right, 450.0f, 0.0f, 150.0f, 100.0f, [this](){
            printf("right bot\n");
            _engine.set_add_player_count(1);
            if (_engine.get_player_count() > 4)
                _engine.set_player_count(0);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_left, 150.0f, 0.0f, 150.0f, 100.0f, [this](){
            printf("left bot\n");
            _engine.set_add_player_count(-1);
            if (_engine.get_player_count() < 0)
                _engine.set_player_count(4);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_right, 1250.0f, 0.0f, 150.0f, 100.0f, [this](){
            printf("right map\n");
            _engine._font_game += 1;
            if (_engine._font_game > 3)
                _engine._font_game = 0;
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_left, 950.0f, 0.0f, 150.0f, 100.0f, [this](){
            printf("left map\n");
            _engine._font_game -= 1;
            if (_engine._font_game < 0)
                _engine._font_game = 3;
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
        push_back_comp<Button> (_texture_return, 683.0f, -400.0f, 150.0f, 100.0f, [this](){
            printf("return\n");
            while (!_engine._game_obj_list.empty())
                _engine._game_obj_list.pop();
            _engine.push_back_obj<MainMenuObj>(_engine);
            _engine._sound_manager.play_sound(
                _engine._assets_manager.
                load_sound("../assets/music/click_button.wav"));
        });
    }

    void PreGameSettingsObj::draw()
    {
        _texture_font.set_texture_grather(1366.0f, 768.0f);
        DrawTexture(_texture_font.get_texture_2d(), 1366/2 - _texture_font.get_texture_2d().width/2, 50, WHITE);
        DrawText(TextFormat("Number Players:"), 150, 250, 40, GOLD);
        DrawText(TextFormat("%i", _engine.get_player_count()), 280, 340, 100, WHITE);
        DrawText(TextFormat("theme game:"), 975, 250, 40, GOLD);
        if (_engine._font_game == 0)
            DrawText(TextFormat("Night-city"), 995, 360, 45, WHITE);
        else if (_engine._font_game == 1)
            DrawText(TextFormat("Montain"), 1015, 360, 45, WHITE);
        else
            DrawText(TextFormat("Sky land"), 1005, 360, 45, WHITE);
    }
}
