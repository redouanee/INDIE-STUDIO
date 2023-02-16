/*
** EPITECH PROJECT, 2022
** raylib.hpp
** File description:
** header
*/

#ifndef RAYLIB_HPP
#define RAYLIB_HPP

#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <stack>
#include "assets_manager.hpp"
#include "collision_obj.hpp"
#include "sound_manager_obj.hpp"
#include "background_manager_obj.hpp"
#include "my_camera.hpp"
#include "my_texture2d.hpp"

namespace Raylib {

    class SoundObj;
    class IGameObj;

    class Engine {
    public:
        bool _can_start = false;
        bool _return = true;
        bool _close = false;
        int _font_game = 0;
        std::vector<std::unique_ptr<IGameObj>> _game_obj_list_game;
        std::stack<std::shared_ptr<IGameObj>> _game_obj_list;
        AssetsManager _assets_manager;
        CollisionObj _collision_manager;
        SoundObj _sound_manager;
        MyCamera _camera;

        Engine(const std::string &title="bomberman", int width=1920, int height=1080);
        ~Engine();

        void start();
        void run();
        void update();

        std::string build_full_string();
        std::string build_unbreak_string(bool space_player);
        std::string build_player_string();
        std::string build_break_string();
        void set_player_count(int nbr);
        void set_add_player_count(int nbr);
        void set_player_alive(int nb);
        void set_ia_alive(int nb);
        int get_player_count();
        void update_game();
        void build_map();
        void print_map();
        void save_map();
        void check_win();

        template<typename T, typename... Args>
        void push_back_obj(Args && ...args)
            {
                this->_game_obj_list.push(
                    std::make_unique<T>(std::forward<Args>(args)...));
            }
        template<typename T, typename... Args>
        void push_back_obj_game(Args && ...args) {
            this->_game_obj_list_game.emplace_back(
                std::make_unique<T>(std::forward<Args>(args)...));
        }
        template<typename T>
        T& get_game_obj() {
            T *ret = dynamic_cast<T *>(this->_game_obj_list.top().get());
            if (ret != nullptr)
                return *ret;
            //TODO: THROW AN ERROR
        }
        template<class T>
        void remove_game_obj(T obj) {
            _game_obj_list_game.erase(obj);
        }

    private:
        std::string map;
        size_t size_x = 21;
        size_t size_y = 21;
        int player_count = 0;
        int max_player = 0;
        int IA_count = 0;
        int player_alive = 0;
        int ia_alive = 0;
    };
};

#endif
