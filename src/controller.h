#include "algorithm.h"

class controller {
public:
    controller();
    bool getAlgoCompleted();
    bool getAlgoRunning();
    void setAlgoRunning(bool flag);
    void drawGrid(sf::RenderWindow& window);
    bool runAlgo(int num);
    void algoInit();
    void clearGrid();
    void handleMouseEvent(sf::RenderWindow& window);

private:
    std::vector<std::vector<std::pair<int, int>>> prev;
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> priorityQ;
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    bool initialized = false;
    std::pair<int,int> prevStart{0,0}, prevFinish{0,0};

    bool algoCompleted = false;
    bool algoRunning = false;
    algorithm algo;
    grid _grid;
};