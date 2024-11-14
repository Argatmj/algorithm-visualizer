#include <SFML/Graphics.hpp>
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
    sf::RenderWindow window;
    std::vector<std::vector<sf::RectangleShape>> grid;
};