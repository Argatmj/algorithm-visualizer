#include "sound.h"

void audio::loadAudio(){
    soundBuffer.loadFromFile("src/beep.wav");
    bleeps.setBuffer(soundBuffer);
}

void audio::playAudio(float pitch) {
    pitch = std::clamp(pitch, 0.0f, 8.0f);
    bleeps.setPitch(pitch);
    if (bleeps.getStatus() != sf::Sound::Playing) {
        bleeps.play();
    }
}
