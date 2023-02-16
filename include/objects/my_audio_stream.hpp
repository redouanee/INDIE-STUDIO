/*
** EPITECH PROJECT, 2022
** my_audio_stream.hpp
** File description:
** header
*/

#ifndef MY_AUDIO_STREAM_HPP
#define MY_AUDIO_STREAM_HPP

#include <raylib.h>

namespace Raylib {

    class MyAudioStream {
    private:
        struct AudioStream _audio_stream;
    public:
        MyAudioStream(unsigned int sampleRate,
                      unsigned int sampleSize, unsigned int channels);
        ~MyAudioStream();
        AudioStream get_audio_stream();
    };
};

#endif
