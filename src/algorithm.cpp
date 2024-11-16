#include "algorithm.h"


bool algorithm::isValid(std::pair<int,int> coords,int size, int len){
    return (coords.first >= 0 && coords.second >= 0 && coords.first < size && coords.second < len);
}

std::set<std::pair<int,int>> algorithm::neighbors(std::pair<int,int> point, int size, int len){
    std::set<std::pair<int,int>> possible_neighbors;
    std::set<std::pair<int,int>> valid_neighbors;
    possible_neighbors.insert({{point.first + 1,point.second},{point.first -1,point.second},{point.first,point.second + 1},{point.first,point.second - 1}});
    for(auto point: possible_neighbors){
        if(isValid(point,size,len)){
            valid_neighbors.insert(point);
        }
    }
    return valid_neighbors;
}

bool algorithm::bfs(std::vector<std::vector<sf::RectangleShape>>& grid,
                    std::vector<std::vector<std::pair<int, int>>>& prev,
                    std::queue<std::pair<int, int>>& q,
                    std::set<std::pair<int, int>>& visited,
                    std::pair<int, int>& start, 
                    std::pair<int, int>& end, 
                    int stepsPerFrame,
                    bool& initialized){
    if (!initialized) {
        q.push(start);
        initialized = true;
    }

    for (int step = 0; step < stepsPerFrame && !q.empty(); ++step) {
        if (q.empty()) {
            initialized = false; 
            return true;        
        }
        auto current = q.front();
        q.pop();
        int row = current.first;
        int col = current.second;

        if (visited.count({row, col})) continue;
        if (grid[row][col].getFillColor() == sf::Color::Black) continue;
        visited.insert({row, col});

        if (row == end.first && col == end.second) {
            grid[row][col].setFillColor(sf::Color::Blue);
            reconstructPath(grid, prev, start, end);
            initialized = false;
            q = {};
            return true;
        }

        if (row == start.first && col == start.second) {
            grid[row][col].setFillColor(sf::Color::Green);
        } else {
            grid[row][col].setFillColor(sf::Color::Red);
        }

        auto valid_neighbors = neighbors({row, col}, grid.size(), grid[0].size());
        for (auto point : valid_neighbors) {
            if (!visited.count(point)) {
                q.push(point);
                prev[point.first][point.second] = {row, col};
            }
        }
    }
    return false;
}

void algorithm::reconstructPath(std::vector<std::vector<sf::RectangleShape>>& grid, 
                                const std::vector<std::vector<std::pair<int, int>>>& prev, 
                                std::pair<int, int> start, 
                                std::pair<int, int> end) {
    int row = end.first;
    int col = end.second;

    while (prev[row][col] != std::make_pair(start.first, start.second)) {
        std::pair<int, int> point = prev[row][col];
        grid[point.first][point.second].setFillColor(sf::Color::Yellow);
        row = point.first;
        col = point.second;
    }
}

