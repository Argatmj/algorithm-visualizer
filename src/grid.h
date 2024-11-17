#include <SFML/Graphics.hpp>
#include <vector>

class grid {
public:
    grid();
    int getRows();
    int getCols();
    int getSize();
    sf::Color getColor(std::pair<int,int> coords);
    void initGrid();
    void setColor(std::pair<int,int> coords, sf::Color color);
    int getCellSize();
    void drawGrid(sf::RenderWindow& window);
    void resetGrid(bool flag, bool& algoCompleted, bool& algoRunning);
    std::vector<std::vector<sf::RectangleShape>>& getGrid();


private:
    std::vector<std::vector<sf::RectangleShape>> _grid;
    int cols, rows, cellSize;

};