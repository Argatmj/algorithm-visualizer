#include "timer.h"

timer::timer(float x, float y, const std::string& label, const sf::Font& font, unsigned int fontSize, int op)
    : label(label), elapsedTime(0.0f) {
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    text.setString(formatDisplay(label,0,op));
}

void timer::restartClock() {
    clock.restart();
}

void timer::update(bool isRunning, int op) {
    float currentTime = isRunning ? clock.getElapsedTime().asSeconds() : elapsedTime;
    text.setString(formatDisplay(label, currentTime, op));
}

void timer::finalize() {
    elapsedTime = clock.getElapsedTime().asSeconds();
}

void timer::draw(sf::RenderWindow& window)  {
    window.draw(text);
}

std::string timer::formatDisplay(const std::string& label, float time, int op) const {
    std::string space = " ";
    switch (op) {
        case 1:
            space = std::string(4, ' ');
            break;
        case 2:
            space = std::string(1, ' '); 
            break;
        case 3:
            space = std::string(6, ' ');
            break;
    }

    std::ostringstream ss;
    ss << label << space << ": " << std::fixed << std::setprecision(2) << time << "s";
    return ss.str();
}