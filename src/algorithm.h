#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include "grid.h"
#include <queue>
#include <set>

class algorithm {
public:
    bool bfs(grid& grid,
            std::vector<std::vector<std::pair<int, int>>>& prev,
            std::queue<std::pair<int, int>>& q,
            std::set<std::pair<int, int>>& visited,
            int stepsPerFrame,
            bool& initialized);
    void setStart(std::pair<int,int> coords);
    void setFinish(std::pair<int,int> coords);

private:
    std::set<std::pair<int,int>> neighbors(std::pair<int,int> point, int size, int len);
    void reconstructPath(grid& grid, const std::vector<std::vector<std::pair<int, int>>>& prev);
    bool isValid(std::pair<int,int> coords, int size, int len);

    std::pair<int, int> start, end;

};