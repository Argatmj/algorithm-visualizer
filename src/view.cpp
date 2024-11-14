#include "view.h"

view::view():
window(sf::VideoMode(width, height), "SFML works!"),
height(800),
width(1000),
cellSize(20),
rows(height/20),
cols(800/20)
{
    grid.resize(rows, std::vector<sf::RectangleShape>(cols));
    initGrid();
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
                handleMouseEvent();
            }
        }

        window.clear(sf::Color::White);
        drawGrid();
        window.display();
    }
}

void view::handleMouseEvent(){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    int gridX = mousePos.x / cellSize;
    int gridY = mousePos.y / cellSize;

    if (gridX >= 0 && gridX < cols && gridY >= 0 && gridY < rows) {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            grid[gridY][gridX].setFillColor(sf::Color::Black);  
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            grid[gridY][gridX].setFillColor(sf::Color::Green);  
         }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            grid[gridY][gridX].setFillColor(sf::Color::Red);  
        }
    }
}

void view::drawGrid(){
        for(int i = 0; i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                window.draw(grid[i][j]);
            }
        }
}

void view::initGrid(){
    for(int y = 0; y < rows; y++){
        for( int x = 0; x < cols ; x++){
                grid[y][x].setSize(sf::Vector2f(cellSize, cellSize));
                grid[y][x].setPosition(x * cellSize, y * cellSize);
                grid[y][x].setFillColor(sf::Color::White); 
                grid[y][x].setOutlineThickness(1);
                grid[y][x].setOutlineColor(sf::Color::Black);
        }
    }
}