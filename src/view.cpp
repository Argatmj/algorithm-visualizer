#include "view.h"

view::view():
window(sf::VideoMode(width, height), "Algo-viz"),
height(800),
width(1000),
control()
{
}

void view::showWindow(){
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseButtonPressed){
                control.handleMouseEvent(window);
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::B) {
                    control.algoInit();
                    num = 1;

                }
                if (event.key.code == sf::Keyboard::G) {
                    control.algoInit();
                    num = 2;

                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    control.clearGrid();
                }
            }
        }


        if (control.getAlgoRunning() && !control.getAlgoCompleted()) {
            bool flag = control.runAlgo(num);
            control.setAlgoCompleted(flag);
            if (control.getAlgoCompleted()) {
                control.setAlgoRunning(false);
            }
        }


        window.clear(sf::Color::White);
        control.drawGrid(window);
        window.display();
    }
}
