#include <SFML/Graphics.hpp>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>

class timer {
public:
    timer(float x, float y, const std::string& label, const sf::Font& font, unsigned int fontSize, int op);

    void restartClock();
    void update(bool isRunning, int op);
    void finalize();
    void draw(sf::RenderWindow& window);

private:
    sf::Text text;
    sf::Clock clock;
    float elapsedTime;
    std::string label;
    std::string formatDisplay(const std::string& label, float time, int op) const;
};


