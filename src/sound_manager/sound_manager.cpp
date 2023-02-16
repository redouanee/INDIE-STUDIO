/*
** EPITECH PROJECT, 2022
** sound_manager.cpp
** File description:
** functions
*/

#include <raylib.h>
#include <vector>
#include "sound_manager_obj.hpp"
#include "raylib.hpp"

namespace Raylib {

    SoundObj::SoundObj(Engine &engine, const std::string &music_path) :
        _engine(engine),
        _music(music_path)
    {
        this->play_music();
    }

    SoundObj::~SoundObj()

    {
    }

    void SoundObj::update()
    {
        UpdateMusicStream(_music.get_music());
        /*printf("BEFORE\n");
          for (int i = 0; i < _list.size(); ++i)
          _list.at(i).play_sound();
          printf("AFTER\n");*/
    }

    void SoundObj::add_sound(const std::string &filename, Engine &engine)
    {
        /*printf("list size = %d\n", _list.size());
          printf("bef\n");
          _list.emplace_back(filename);
          printf("AF\n");
          printf("list size = %d\n", _list.size());*/
    }

    void SoundObj::pause_music()
    {
        _music.pause_music();
    }

    void SoundObj::play_sound(MySound &sound)
    {
        sound.play_sound();
    }

    void SoundObj::play_music()
    {
        _music.play_music();
    }

    Music SoundObj::get_music()
    {
        return _music.get_music();
    }

    void SoundObj::change_music(const std::string &filepath)
    {
        _music.change_music(filepath);
    }
}
