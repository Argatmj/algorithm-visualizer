#include <SFML/Graphics.hpp>
#include "algorithm.h"
#include <vector>

class view{
public:
    view();
    void showWindow();
    void initGrid();
    void drawGrid();
    void handleMouseEvent();
private:
    int height, width;
    int cols, rows, cellSize;
    algorithm algo;
    sf::RenderWindow window;
    std::vector<std::vector<sf::RectangleShape>> grid;
};