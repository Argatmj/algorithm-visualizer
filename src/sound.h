#include "SFML/Audio.hpp"

class audio{
public:
    void loadAudio();
    void playAudio(float pitch);

private:
    sf::SoundBuffer soundBuffer;
    sf::Sound bleeps;
};