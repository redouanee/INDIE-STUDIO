/*
** EPITECH PROJECT, 2022
** asset_manager.cpp
** File description:
** functions
*/

#include <map>
#include <raylib.h>
#include "raylib.hpp"
#include "assets_manager.hpp"

namespace Raylib {

    AssetsManager::AssetsManager()
    {
    }

    AssetsManager::~AssetsManager()
    {
    }

    MyWave &AssetsManager::load_wave(const std::string &filename)
    {
        if (this->_wave_assets.contains(filename)) {
            return this->_wave_assets.find(filename)->second;
        }
        this->_wave_assets.emplace(filename, filename);
        return this->_wave_assets[filename];
    }

    MyFont &AssetsManager::load_font(const std::string &filename)
    {
        if (this->_font_assets.contains(filename)) {
            return this->_font_assets.find(filename)->second;
        }
        this->_font_assets.emplace(filename, filename);
        return this->_font_assets[filename];
    }

    MyImage &AssetsManager::load_image(const std::string &filename)
    {
        if (this->_image_assets.contains(filename)) {
            return this->_image_assets.find(filename)->second;
        }
        this->_image_assets.emplace(filename, filename);
        return this->_image_assets[filename];

    }

    MyTexture2D &AssetsManager::load_texture_2d(const std::string &filename)
    {
        if (this->_texture_assets.contains(filename)) {
            return this->_texture_assets.find(filename)->second;
        }
        this->_texture_assets.emplace(filename, filename);
        return this->_texture_assets[filename];
    }

    MyModel &AssetsManager::load_model(const std::string &filename)
    {
        if (this->_model_assets.contains(filename)) {
            return this->_model_assets.find(filename)->second;
        }
        this->_model_assets.emplace(filename, filename);
        return this->_model_assets[filename];
    }

    MySound &AssetsManager::load_sound(const std::string &filename)
    {
        if (this->_sound_assets.contains(filename)) {
            return this->_sound_assets.find(filename)->second;
        }
        this->_sound_assets.emplace(filename, filename);
        return this->_sound_assets[filename];
    }

    MyModelAnimation &AssetsManager::load_model_animation(const std::string &filename)
    {
        if (this->_model_animation_assets.contains(filename)) {
            return this->_model_animation_assets.find(filename)->second;
        }
        this->_model_animation_assets.emplace(filename, filename);
        return this->_model_animation_assets[filename];
    }
};
