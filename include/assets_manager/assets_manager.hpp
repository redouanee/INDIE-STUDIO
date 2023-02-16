/*
** EPITECH PROJECT, 2022
** assets_manager.hpp
** File description:
** header
*/

#ifndef ASSETS_MANAGER_HPP
#define ASSETS_MANAGER_HPP

#include <map>
#include <raylib.h>
#include "my_wave.hpp"
#include "my_font.hpp"
#include "my_image.hpp"
#include "my_texture2d.hpp"
#include "my_model.hpp"
#include "my_sound.hpp"
#include "my_model_animation.hpp"

namespace Raylib {

    class AssetsManager {
    private:
        std::map<std::string, MyWave> _wave_assets;
        std::map<std::string, MyFont> _font_assets;
        std::map<std::string, MyImage> _image_assets;
        std::map<std::string, MyTexture2D> _texture_assets;
        std::map<std::string, MyModel> _model_assets;
        std::map<std::string, MySound> _sound_assets;
        std::map<std::string, MyModelAnimation> _model_animation_assets;
    public:
        AssetsManager();
        ~AssetsManager();

        MyWave &load_wave(const std::string &filename);
        MyFont &load_font(const std::string &filename);
        MyImage &load_image(const std::string &filename);
        MyTexture2D &load_texture_2d(const std::string &filename);
        MyModel &load_model(const std::string &filename);
        MySound &load_sound(const std::string &filename);
        MyModelAnimation &load_model_animation(const std::string &filename);
    };
};
#endif
