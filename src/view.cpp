#include "view.h"

view::view():
window(sf::VideoMode(width, height), "Algo-viz"),
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
    std::vector<std::vector<std::pair<int, int>>> prev(grid.size(), std::vector<std::pair<int, int>>(grid[0].size(), {-1, -1}));
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    bool initialized = false;
    std::pair start{1,1} , end{30,30};
    
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
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::B) {
                    algoRunning = true;
                    algoCompleted = false;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    clearGrid(false);
                    initialized = false;
                    visited.clear();
                    prev.assign(grid.size(), std::vector<std::pair<int, int>>(grid[0].size(), {-1, -1}));
                    while (!q.empty()) q.pop();
                }
            }
        }

        if (algoRunning && !algoCompleted) {
           algoCompleted = algo.bfs(grid, prev, q, visited, start, end, 4, initialized);
            if (algoCompleted) {
                algoRunning = false; 
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
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
            grid[gridY][gridX].setFillColor(sf::Color::White);  
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

void view::clearGrid(bool flag){
    algoCompleted = false;
    algoRunning = false;
    for(int i = 0; i < rows; i++){
            for(int j = 0 ;j < cols; j++){
                if(grid[i][j].getFillColor() == sf::Color::Black && !flag){
                    continue;
                }
                grid[i][j].setFillColor(sf::Color::White);
            }
        }
}