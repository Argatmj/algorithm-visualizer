#include "controller.h"

controller::controller(){
    prev.resize(_grid.getRows(), std::vector<std::pair<int, int>>(_grid.getCols(), {0, 0}));
}

void controller::algoInit(){
    algoRunning = true;
    algoCompleted = false;
}

void controller::clearGrid(){
    algoCompleted = false;
    algoRunning = false;
    _grid.resetGrid(false);
    initialized = false;
    visited.clear();
    prev.assign(_grid.getSize(), std::vector<std::pair<int, int>>(_grid.getCols(), {-1, -1}));
    while (!q.empty()) q.pop();
}

bool controller::getAlgoCompleted(){
    return algoCompleted;
}

bool controller::getAlgoRunning(){
    return algoRunning;
}

void controller::setAlgoRunning(bool flag){
    algoRunning = flag;
}

void controller::drawGrid(sf::RenderWindow& window){
    _grid.drawGrid(window);
}

bool controller::runAlgo(){
    return algo.bfs(_grid, prev, q, visited, 4, initialized);
}

void controller::handleMouseEvent(sf::RenderWindow& window){
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