#include <SFML/Graphics.hpp>
#include "controller.h"
#include "timer.h"
#include <string>

class view{
public:
    view();
    void showWindow();
private: 
    void updateTimer();
    int height, width, op;
    sf::RenderWindow window;
    controller control;
    sf::Font font; 
    timer bfsTimer, gbfsTimer, aTimer;
};