/*
** EPITECH PROJECT, 2022
** engine.cpp
** File description:
** functions
*/

#include <iostream>
#include <fstream>
#include <raylib.h>
#include "raylib.hpp"
#include "game_object.hpp"
#include "main_menu_obj.hpp"
#include "pnj_manager.hpp"
#include "wall_obj.hpp"
#include "bomb_obj.hpp"
#include "brick_obj.hpp"

namespace Raylib {

    Engine::Engine(const std::string &title, int width, int height) :
                                            _collision_manager(*this), _sound_manager(*this)
    {
        InitWindow(width, height, title.c_str());
        this->start();
    }

    Engine::~Engine() {
        CloseWindow();
    }

    void Engine::start()
    {
    }

    void Engine::build_map() {
        MyVector3 pos(-15.2, 2, -14.8);
        MyVector3 size(1.7, 1, 1.7);
        float reset = -(21 * 1.6) - 1.6;
        MyVector3 player_size(0.2, 0.5, 0.2);

        for (int i = 0; i <= size_y; i++) {
            if (i == 0 || i == size_y) {
                map += build_full_string();
                map += "\n";
            }
            else if (i == 1 || i == size_y - 2) {
                map += build_player_string();
                map += "\n";
            }
            else if (i == 2 || i == size_y - 3) {
                map +=build_unbreak_string(true);
                map += "\n";
            }
            else if (i%2 == 0) {
                map +=build_unbreak_string(false);
                map += "\n";
            }
            else {
                map +=build_break_string();
                map += "\n";
            }
        }
        int passed_id = 1;
        std::string colors[] =
            {"../assets/player_texture_orange.png",
             "../assets/player_texture_blue.png",
             "../assets/player_texture_green.png",
             "../assets/player_texture_red.png"};
        for (int i = 0; i < map.size(); ++i) {
           if (map.at(i) == 'P') {
                max_player += 1;
                if (max_player > player_count)
                    map.at(i) = 'I';
           }
        }
        for (int i = 0; i < map.size(); ++i) {
            if (map.at(i) == 'W') {
                this->push_back_obj_game<WallObj>
                    (pos, size, *this,
                     _assets_manager.load_texture_2d("../assets/wall.png"));
            }
            else if (map.at(i) == 'P') {
                this->player_alive++;
                if (passed_id == 1)
                    this->push_back_obj_game<Player>(*this,
                                                     _assets_manager.load_model("../assets/player.iqm"),
                                                     _assets_manager.load_texture_2d(colors[0]),
                                                     passed_id,
                                                     _assets_manager.load_model_animation("../assets/player_anim.iqm"),
                                                     pos, player_size);
                    else if (passed_id == 2)
                    this->push_back_obj_game<Player>(*this,
                                                     _assets_manager.load_model("../assets/player.iqm"),
                                                     _assets_manager.load_texture_2d(colors[1]),
                                                     passed_id,
                                                     _assets_manager.load_model_animation("../assets/player_anim.iqm"),
                                                     pos, player_size);
                else if (passed_id == 3)
                    this->push_back_obj_game<Player>(*this,
                                                     _assets_manager.load_model("../assets/player.iqm"),
                                                     _assets_manager.load_texture_2d(colors[2]),
                                                     passed_id,
                                                     _assets_manager.load_model_animation("../assets/player_anim.iqm"),
                                                     pos, player_size);
                else
                    this->push_back_obj_game<Player>(*this,
                                                     _assets_manager.load_model("../assets/player.iqm"),
                                                     _assets_manager.load_texture_2d(colors[3]),
                                                     passed_id,
                                                     _assets_manager.load_model_animation("../assets/player_anim.iqm"),
                                                     pos, player_size);
                passed_id++;
            }
            else if (map.at(i) == 'B') {
                this->push_back_obj_game<BrickObj>
                    (pos, size, *this,
                     _assets_manager.load_texture_2d("../assets/box.png"));
            }
            else if (map.at(i) == 'I') {
                this->push_back_obj_game<Bot>(*this,
                                              _assets_manager.load_model("../assets/player.iqm"),
                                              _assets_manager.load_texture_2d("../assets/player_texture_green.png"),
                                              passed_id,
                                              _assets_manager.load_model_animation("../assets/player_anim.iqm"),
                                              pos);
                this->ia_alive++;
                passed_id++;
            }
            pos.set_vector_x(1.6);
            if (map.at(i) == '\n') {
                pos.set_vector_z(1.6);
                pos.set_vector_x(reset);
            }
        }
    }

    void Engine::print_map()
    {
        std::cout<<map;
    }

    std::string Engine::build_full_string()
    {
        std::string map;

        for (int i = 0; i < size_x; i++) {
            map += 'W';
        }
        return(map);
    }

    std::string Engine::build_unbreak_string(bool space_player)
    {
        std::string tmp_str;
        for (int i = 0; size_x > i; i++) {
            if (i == 0 || i == size_x - 1) {
                tmp_str += "W";
                continue;
            }
            if (i == 1 || i == size_x - 2 && space_player) {
                tmp_str += " ";
                continue;
            }
            if (i%2 == 0) {
                tmp_str += "W";
                continue;
            }
            int rand = std::rand()%2;
                if (rand == 1)
                    tmp_str += "B";
                else
                    tmp_str += " ";
        }
        return(tmp_str);
    }

    std::string Engine::build_player_string()
    {
        int cpt = 0;
        std::string tmp_str;
        for (int i = 0; size_x > i; i++) {
            if (i == 0 || i == size_x-1) {
                tmp_str += "W";
                continue;
            }
            if (i == 1 || i == size_x - 2) {
                tmp_str += "P";
                continue;
            }
            if (i == 2 || i == size_x - 3) {
                tmp_str += " ";
                continue;
            }
            int rand = std::rand()%2;
            if (rand == 1)
                tmp_str += "B";
            else
                tmp_str += " ";
        }
        return(tmp_str);
    }

    std::string Engine::build_break_string()
    {
        std::string tmp_str;
        for (int i = 0; size_x > i; i++) {
            if (i == 0 || i == size_x - 1) {
                tmp_str += "W";
                continue;
            }
            int rand = std::rand()%2;
                if (rand == 1)
                    tmp_str += "B";
                else
                    tmp_str += " ";
        }
        return(tmp_str);
    }

    void Engine::run() {
        this->push_back_obj<MainMenuObj>(*this);
        while(true) {
            BeginDrawing();
            if (WindowShouldClose() || _close) {
                break;
            }
            ClearBackground(RAYWHITE);
            this->update();
            this->update_game();
            EndDrawing();
        }
    }

    int Engine::get_player_count()
    {
        return player_count;
    }

    void Engine::set_player_count(int nbr)
    {
        player_count = nbr;
    }

    void Engine::set_add_player_count(int nbr)
    {
        player_count += nbr;
    }

    void Engine::update()
    {
        _sound_manager.update();
        if (!this->_game_obj_list.empty()) {
            auto scene = this->_game_obj_list.top();
            scene->draw();
            for (auto &c : scene->_comps_list) {
                c->update(*scene, *this);
                c->draw(*scene, *this);
            }
        }
    }

    void Engine::save_map()
    {
        std::ofstream save_file;

        save_file.open("../save/save_game.save");
        for (auto &obj : _game_obj_list_game) {
            obj->save_game_obj(save_file);
        }
        save_file.close();
    }

    void Engine::update_game()
    {
        int i = 0;

        if (_can_start) {
            this->_camera.start_3d();
            for (size_t i = 0; i < _game_obj_list_game.size(); ++i) {
                auto &p = *_game_obj_list_game[i];
                for (size_t i = 0; i < p._comps_list.size(); ++i) {
                    auto &pc = *p._comps_list[i];
                    pc.update(p, *this);
                    pc.draw(p, *this);
                }
                p.draw();
            }
            for (size_t i = 0; i < _game_obj_list_game.size(); ++i) {
                if (_game_obj_list_game.at(i)->to_destroy == true) {
                    _game_obj_list_game.erase(_game_obj_list_game.begin() + i);
                    if (i != 0)
                        i--;
                    continue;
                }
            }
            _collision_manager.update();
            this->_camera.stop_3d();
            this->check_win();
        }
    }


    void Engine::check_win()
    {
        if (this->ia_alive + this->player_alive == 1) {
            if (this->ia_alive == 1) {
                DrawText(TextFormat("AI wins !"),
                         400, 30, 100, RED);
            }
            else {
                DrawText(TextFormat("Player wins !"),
                         400, 30, 100, GREEN);
            }
            if (IsKeyDown(KEY_ENTER)) {
                _game_obj_list_game.clear();
                while (!_game_obj_list.empty())
                    _game_obj_list.pop();
                _can_start = false;
                push_back_obj<MainMenuObj>(*this);
                _sound_manager.change_music("../assets/music/menu_sound.wav");
            }
        }
    }

    void Engine::set_player_alive(int nb)
    {
        player_alive += nb;
    }

    void Engine::set_ia_alive(int nb)
    {
        ia_alive += nb;
    }
}
