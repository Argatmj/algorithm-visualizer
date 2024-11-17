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

bool algorithm::bfs(grid& grid,
                    std::vector<std::vector<std::pair<int, int>>>& prev,
                    std::queue<std::pair<int, int>>& q,
                    std::set<std::pair<int, int>>& visited,
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
        if (grid.getColor(current) == sf::Color::Black) continue;
        visited.insert({row, col});

        if (current == end) {
            reconstructPath(grid, prev);
            initialized = false;
            q = {};
            return true;
        }

        if(current != start){
            grid.setColor(current,sf::Color::Red);
        }

        auto valid_neighbors = neighbors({row, col}, grid.getSize(), grid.getCols());
        for (auto point : valid_neighbors) {
            if (!visited.count(point)) {
                q.push(point);
                prev[point.first][point.second] = {row, col};
            }
        }
    }
    return false;
}

void algorithm::setStart(std::pair<int, int> coords)
{
    start = coords;
}

void algorithm::setFinish(std::pair<int, int> coords)
{
    end = coords;
}

void algorithm::reconstructPath(grid& grid, const std::vector<std::vector<std::pair<int, int>>>& prev) {
    int row = end.first;
    int col = end.second;

    while (prev[row][col] != std::make_pair(start.first, start.second)) {
        std::pair<int, int> point = prev[row][col];
        grid.setColor(point, sf::Color::Yellow);
        row = point.first;
        col = point.second;
    }
}

