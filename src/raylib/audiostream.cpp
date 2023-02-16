/*
** EPITECH PROJECT, 2022
** audio_stream.cpp
** File description:
** functions
*/

#include <raylib.h>
#include "raylib.hpp"
#include "my_audio_stream.hpp"

namespace Raylib {

    MyAudioStream::MyAudioStream(unsigned int sampleRate,
                                 unsigned int sampleSize,
                                 unsigned int channels) {
        this->_audio_stream = LoadAudioStream(sampleRate, sampleSize, channels);
    }

    MyAudioStream::~MyAudioStream() {
        UnloadAudioStream(this->_audio_stream);
    }

    AudioStream MyAudioStream::get_audio_stream() {
    return this->_audio_stream;
    }
}
