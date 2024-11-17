#include "view.h"

view::view():
window(sf::VideoMode(width, height), "Algo-viz"),
height(800),
width(1000)
{
}


void view::showWindow(){
    std::vector<std::vector<std::pair<int, int>>> prev(_grid.getGrid().size(), std::vector<std::pair<int, int>>(_grid.getGrid()[0].size(), {-1, -1}));
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    bool initialized = false;
    std::pair prevStart{0,0}, prevFinish{0,0};
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseButtonPressed){
                handleMouseEvent(prevStart, prevFinish);
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::B) {
                    algoRunning = true;
                    algoCompleted = false;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    _grid.resetGrid(false, algoCompleted, algoRunning);
                    initialized = false;
                    visited.clear();
                    prev.assign(_grid.getSize(), std::vector<std::pair<int, int>>(_grid.getCols(), {-1, -1}));
                    while (!q.empty()) q.pop();
                }
            }
        }

        if (algoRunning && !algoCompleted) {
           algoCompleted = algo.bfs(_grid, prev, q, visited, 4, initialized);
            if (algoCompleted) {
                algoRunning = false; 
            }
        }

        window.clear(sf::Color::White);
        _grid.drawGrid(window);
        window.display();
    }
}

void view::handleMouseEvent(std::pair<int,int>& prevStart, std::pair<int,int>& prevFinish){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    
    int cellSize = _grid.getCellSize();
    int cols = _grid.getCols();
    int rows = _grid.getRows();

    int gridX = mousePos.x / cellSize;
    int gridY = mousePos.y / cellSize;

    std::pair<int,int> coords = {gridY,gridX};

    if (gridX >= 0 && gridX < cols && gridY >= 0 && gridY < rows) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
           _grid.setColor(coords,sf::Color::Black);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
           _grid.setColor(coords,sf::Color::White);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if(std::make_pair(gridY,gridX) != prevStart){
                _grid.setColor(prevStart,sf::Color::White);
            }
            _grid.setColor(coords,sf::Color::Green);  
            prevStart = {gridY,gridX};
            algo.setStart(prevStart);
         }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            if(std::make_pair(gridY,gridX) != prevFinish ){
               _grid.setColor(prevFinish,sf::Color::White);
            }
            _grid.setColor(coords,sf::Color::Blue);  
            prevFinish = {gridY,gridX};
           algo.setFinish(prevFinish);
        }
    }
}
