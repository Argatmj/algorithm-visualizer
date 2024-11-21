#include "timer.h"

timer::timer(float x, float y, const std::string& label, const sf::Font& font, unsigned int fontSize)
    : label(label), elapsedTime(0.0f) {
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    text.setString(formatDisplay(label,0));
}

void timer::restartClock() {
    clock.restart();
}

void timer::update(bool isRunning) {
    float currentTime = isRunning ? clock.getElapsedTime().asSeconds() : elapsedTime;
    text.setString(formatDisplay(label, currentTime));
}

void timer::finalize() {
    elapsedTime = clock.getElapsedTime().asSeconds();
}

void timer::draw(sf::RenderWindow& window)  {
    window.draw(text);
}

std::string timer::formatDisplay(const std::string& label, float time) const {
    std::ostringstream ss;
    ss << label << ": " << std::fixed << std::setprecision(2) << time << "s";
    return ss.str();
}