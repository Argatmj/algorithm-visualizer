#include "view.h"

view::view():
window(sf::VideoMode(width, height), "Algo-viz"),
height(800),
width(1000),
control(),
bfsTimer(850,50,"BFS",font,20,1),
gbfsTimer(850,100,"GBFS",font,20,2),
aTimer(850,150,"A*",font,20,3)
{
    font.loadFromFile("src/OpenSans-Regular.ttf");
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
                    op = 1;
                    bfsTimer.restartClock();
                }
                if (event.key.code == sf::Keyboard::G) {
                    control.algoInit();
                    op = 2;
                    gbfsTimer.restartClock();
                }
                if (event.key.code == sf::Keyboard::A) {
                    control.algoInit();
                    op = 3;
                    aTimer.restartClock();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    control.clearGrid();
                }
            }
        }

        if (control.getAlgoRunning() && !control.getAlgoCompleted()) {
            bool flag = control.runAlgo(op);
            control.setAlgoCompleted(flag);
            if (control.getAlgoCompleted()) {
                control.setAlgoRunning(false);
                switch(op){
                    case 1:
                        bfsTimer.finalize();
                        break;
                    case 2:
                        gbfsTimer.finalize();
                        break;
                    case 3:
                        aTimer.finalize();
                        break;
                }
            }
        }

        window.clear(sf::Color::White);
        control.drawGrid(window);
        updateTimer();
        window.display();
    }
}

void view::updateTimer(){
    bool flag = control.getAlgoRunning();
    
    switch(op){
        case 1: 
            bfsTimer.update(flag,op);
            break;
        case 2: 
            gbfsTimer.update(flag,op);
            break;
        case 3: 
            aTimer.update(flag,op);
            break;
    }

    bfsTimer.draw(window);
    gbfsTimer.draw(window);
    aTimer.draw(window);

}
