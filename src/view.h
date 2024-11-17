#include <SFML/Graphics.hpp>
#include "algorithm.h"
#include <vector>

class view{
public:
    view();
    void showWindow();
    void handleMouseEvent(std::pair<int,int>& prevStart, std::pair<int,int>& prevFinish);
private:
    int height, width;
    bool algoCompleted = false;
    bool algoRunning = false;
    algorithm algo;
    sf::RenderWindow window;
    grid _grid;
};