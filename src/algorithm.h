#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "grid.h"
#include <queue>
#include <set>
#include <cmath>
#include "sound.h"
#include <algorithm>

class algorithm {
public:
    algorithm(grid& grid);
    bool bfs(grid& grid);
    bool gbfs(grid& grid);
    void setStart(std::pair<int,int> coords);
    void setFinish(std::pair<int,int> coords);
    float calculateDistance(const std::pair<int, int>& point1, const std::pair<int, int>& point2);

private:
    std::set<std::pair<int,int>> neighbors(std::pair<int,int> point, int size, int len);
    void reconstructPath(grid& grid, const std::vector<std::vector<std::pair<int, int>>>& prev);
    int manhattanDistance(std::pair<int,int> start);
    bool isValid(std::pair<int,int> coords, int size, int len);

    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> priorityQ;
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    std::vector<std::vector<std::pair<int, int>>> prev;
    bool initialized = false;
    std::pair<int, int> start, end;
    audio beep;

};