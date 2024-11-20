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
    bool astar(grid& grid);
    void resetValues();
    void setStart(std::pair<int,int> coords);
    void setFinish(std::pair<int,int> coords);
    float calculateDistance(const std::pair<int, int>& point1, const std::pair<int, int>& point2);

private:
    struct Node{
        int x,y;
        int g,h,f;
        Node(int _x, int _y, int _g, int _h)
        : x(_x), y(_y), g(_g), h(_h), f(_g + _h){}
        bool operator<(const Node& other) const {
            return f > other.f; 
        }
    };
    std::priority_queue<Node> nodeQ;
    std::map<std::pair<int, int>, int> costMap;
    std::set<std::pair<int,int>> neighbors(std::pair<int,int> point, int size, int len);
    void reconstructPath(grid& grid);
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