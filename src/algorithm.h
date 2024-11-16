#include <SFML/Graphics.hpp>
#include <utility>
#include <thread>
#include <chrono> 
#include <vector>
#include <queue>
#include <set>

class algorithm {
private:
    std::set<std::pair<int,int>> neighbors(std::pair<int,int> point, int size, int len);
    void reconstructPath(std::vector<std::vector<sf::RectangleShape>>& grid, 
                                const std::vector<std::vector<std::pair<int, int>>>& prev, 
                                std::pair<int, int> start, 
                                std::pair<int, int> end);
    bool isValid(std::pair<int,int> coords, int size, int len);

public:
    bool bfs(std::vector<std::vector<sf::RectangleShape>>& grid,
            std::vector<std::vector<std::pair<int, int>>>& prev,
            std::queue<std::pair<int, int>>& q,
            std::set<std::pair<int, int>>& visited,
            std::pair<int, int>& start, 
            std::pair<int, int>& end, 
            int stepsPerFrame,
            bool& initialized);



};