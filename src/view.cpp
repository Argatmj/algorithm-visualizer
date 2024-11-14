#include "view.h"

view::view():
height(400),
width(400)
{}


void view::showWindow(){
    sf::RenderWindow window(sf::VideoMode(height, width), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}