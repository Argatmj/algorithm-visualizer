#include "algorithm.h"

class controller {
public:
    controller();
    bool getAlgoCompleted();
    bool getAlgoRunning();
    void setAlgoRunning(bool flag);
    void setAlgoCompleted(bool flag);
    void drawGrid(sf::RenderWindow& window);
    bool runAlgo(int num);
    void algoInit();
    void clearGrid();
    void handleMouseEvent(sf::RenderWindow& window);

private:
    std::pair<int,int> prevStart{0,0}, prevFinish{0,0};

    bool algoCompleted = false;
    bool algoRunning = false;
    grid _grid;
    algorithm algo;
};