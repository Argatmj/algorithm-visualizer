#include "controller.h"

controller::controller():
_grid(),
algo(_grid)
{
}

void controller::algoInit(){
    algoRunning = true;
    algoCompleted = false;
}

void controller::clearGrid(){
    algoCompleted = false;
    algoRunning = false;
    _grid.resetGrid(false);
    algo.resetValues();
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

void controller::setAlgoCompleted(bool flag){
    algoCompleted = flag;
}

void controller::drawGrid(sf::RenderWindow& window){
    _grid.drawGrid(window);
}

bool controller::runAlgo(int num){
    bool result;
    switch(num){
        case 1:
            result = algo.bfs(_grid);
            break;
        case 2:
            result = algo.gbfs(_grid);
            break;
        case 3:
            result = algo.astar(_grid);
            break;
    }
    return result;

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
            _grid.setColor(coords,sf::Color::Red);  
            prevFinish = {gridY,gridX};
           algo.setFinish(prevFinish);
        }
    }
}