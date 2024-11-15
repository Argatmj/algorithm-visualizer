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
    bool isValid(std::pair<int,int> coords, int size, int len);

public:
    void bfs(std::vector<std::vector<sf::RectangleShape>>& grid, std::pair<int,int> start, std::pair<int,int> end);



};