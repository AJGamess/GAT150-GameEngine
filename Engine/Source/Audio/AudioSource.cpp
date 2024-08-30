#include "AudioSource.h"
#include <fmod_errors.h>
#include <iostream>

bool AudioSource::Play(Audio& audio, bool loop, float volume, float pitch)
{
    m_audioClip->m_sound->setMode(loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF);

    FMOD_RESULT result = audio.m_audio->playSound(m_audioClip->m_sound, nullptr, false, &m_channel);
    if (result != FMOD_OK)
    {
        std::cerr << "Error playing sound: " << FMOD_ErrorString(result) << std::endl;
        return false;
    }

    SetVolume(volume);
    SetPitch(pitch);

    return true;
}

void AudioSource::Stop()
{
    if (IsPlaying()) m_channel->stop();
}

void AudioSource::Pause(bool pause)
{
    FMOD_RESULT result = m_channel->setPaused(pause);
    if (result != FMOD_OK)
    {
        std::cerr << "Error pausing sound: " << FMOD_ErrorString(result) << std::endl;
    }
}

bool AudioSource::IsPlaying()
{
    bool isPlaying = false;
    FMOD_RESULT result = m_channel->isPlaying(&isPlaying);
    if (result != FMOD_OK)
    {
        std::cerr << "Error checking if sound is playing: " << FMOD_ErrorString(result) << std::endl;
    }

    return isPlaying;
}

bool AudioSource::SetVolume(float volume)
{
    FMOD_RESULT result = m_channel->setVolume(volume);
    if (result != FMOD_OK)
    {
        std::cerr << "Error setting volume: " << FMOD_ErrorString(result) << std::endl;
        return false;
    }

    return true;
}

bool AudioSource::SetPitch(float pitch)
{
    FMOD_RESULT result = m_channel->setPitch(pitch);
    if (result != FMOD_OK)
    {
        std::cerr << "Error setting pitch: " << FMOD_ErrorString(result) << std::endl;
        return false;
    }

    return true;
}