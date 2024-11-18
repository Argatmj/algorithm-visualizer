#include "grid.h"

grid::grid():
cellSize(20),
rows(1000/20),
cols(800/20)
{
    _grid.resize(rows, std::vector<sf::RectangleShape>(cols));
    initGrid();
}

std::vector<std::vector<sf::RectangleShape>>& grid::getGrid(){
    return _grid;
}

int grid::getCellSize(){
    return cellSize;
}

int grid::getRows(){
    return rows;
}

int grid::getCols(){
    return cols;
}

int grid::getSize(){
    return _grid.size();
}

sf::Color grid::getColor(std::pair<int, int> coords){
    return _grid[coords.first][coords.second].getFillColor();
}

void grid::setColor(std::pair<int,int> coords, sf::Color color){
    _grid[coords.first][coords.second].setFillColor(color);
}

void grid::initGrid(){
    for(int y = 0; y < rows; y++){
        for( int x = 0; x < cols ; x++){
                _grid[y][x].setSize(sf::Vector2f(cellSize, cellSize));
                _grid[y][x].setPosition(x * cellSize, y * cellSize);
                _grid[y][x].setFillColor(sf::Color::White); 
                _grid[y][x].setOutlineThickness(1);
                _grid[y][x].setOutlineColor(sf::Color::Black);
        }
    }
}

void grid::drawGrid(sf::RenderWindow& window){
        for(int i = 0; i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                window.draw(_grid[i][j]);
            }
        }
}

void grid::resetGrid(bool flag){
    for(int i = 0; i < rows; i++){
        for(int j = 0 ;j < cols; j++){
            if(_grid[i][j].getFillColor() == sf::Color::Black && !flag){
                continue;
            }
        setColor(std::make_pair(i,j), sf::Color::White);
        }
    }
}