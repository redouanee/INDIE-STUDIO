/*
** EPITECH PROJECT, 2022
** music.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_music.hpp"

namespace Raylib {

    MyMusic::MyMusic(const std::string &filename) {
        InitAudioDevice();
        this->_music = LoadMusicStream(filename.c_str());
    }

    MyMusic::~MyMusic() {
        UnloadMusicStream(this->_music);
        CloseAudioDevice();
    }

    Music MyMusic::get_music() {
        return this->_music;
    }

    void MyMusic::play_music()
    {
        PlayMusicStream(_music);
    }

    void MyMusic::pause_music()
    {
        PauseMusicStream(_music);
    }

    void MyMusic::change_music(const std::string &filepath)
    {
        UnloadMusicStream(_music);
        _music = LoadMusicStream(filepath.c_str());
        this->play_music();
    }
}
