#include <SFML/Graphics.hpp>
#include "controller.h"
#include <vector>

class view{
public:
    view();
    void showWindow();
private:
    int height, width;
    sf::RenderWindow window;
    controller control;
};