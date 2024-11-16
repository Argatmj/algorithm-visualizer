#include <SFML/Graphics.hpp>
#include "algorithm.h"
#include <vector>

class view{
public:
    view();
    void showWindow();
    void initGrid();
    void drawGrid();
    void clearGrid(bool flag);
    void handleMouseEvent();
private:
    int height, width;
    int cols, rows, cellSize;
    bool algoCompleted = false;
    bool algoRunning = false;
    algorithm algo;
    sf::RenderWindow window;
    std::vector<std::vector<sf::RectangleShape>> grid;
};