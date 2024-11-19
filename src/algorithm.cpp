#include "algorithm.h"
#include <iostream>

algorithm::algorithm(){
    beep.loadAudio();
}

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
    
    float pathDistance = calculateDistance(start, end);

    for (int step = 0; step < stepsPerFrame && !q.empty(); ++step) {
        if (q.empty()) {
            initialized = false; 
            return true;        
        }

        auto current = q.front();

        if (current == end) {
            reconstructPath(grid, prev);
            initialized = false;
            q = {};
            return true;
        }

        float focusPointDistance = calculateDistance(current, end);
        
        if (pathDistance > 6.0f) {
            float ratio = focusPointDistance / pathDistance;
            ratio = 1.0f - ratio; 
            float pitch = 0.1f + (ratio * 7.5f);
            beep.playAudio(pitch);
        }

        q.pop();
        int row = current.first;
        int col = current.second;

        if (visited.count({row, col})) continue;
        if (grid.getColor(current) == sf::Color::Black) continue;
        visited.insert({row, col});

        if(current != start){
            grid.setColor(current,sf::Color::Blue);
        }

        auto valid_neighbors = neighbors(current, grid.getSize(), grid.getCols());
        for (auto point : valid_neighbors) {
            if (!visited.count(point)) {
                q.push(point);
                prev[point.first][point.second] = {row, col};
            }
        }
    }
    return false;
}

float algorithm::calculateDistance(const std::pair<int, int>& point1, const std::pair<int, int>& point2) {
    int dx = point1.first - point2.first;
    int dy = point1.second - point2.second;
    return std::sqrt(dx * dx + dy * dy);
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

bool algorithm::gbfs(grid& grid,
                    std::vector<std::vector<std::pair<int, int>>>& prev,
                    std::priority_queue<std::pair<int, std::pair<int, int>>, 
                    std::vector<std::pair<int, std::pair<int, int>>>, 
                    std::greater<>>& priorityQ,
                    std::set<std::pair<int, int>>& visited,
                    int stepsPerFrame,
                    bool& initialized) {

    if (!initialized) {
        priorityQ.push(std::make_pair(manhattanDistance(start), start));
        initialized = true;
    }

    float pathDistance = calculateDistance(start, end);

    for (int step = 0; step < stepsPerFrame && !priorityQ.empty(); ++step) {
        std::pair<int, std::pair<int, int>> current = priorityQ.top();
        priorityQ.pop();
        std::pair<int, int> coords = current.second;

        float focusPointDistance = calculateDistance(coords, end);
        
        if (pathDistance > 6.0f) {
            float ratio = focusPointDistance / pathDistance;
            ratio = 1.0f - ratio; 
            float pitch = 0.1f + (ratio * 7.5f);
            beep.playAudio(pitch);
        }

        if (visited.count(coords)) continue;
        visited.insert(coords);

        if (grid.getColor(coords) == sf::Color::Black) continue;

         if (coords == end) {
            reconstructPath(grid, prev);
            initialized = false;
            std::priority_queue<
                std::pair<int, std::pair<int, int>>, 
                std::vector<std::pair<int, std::pair<int, int>>>, 
                std::greater<>
            > empty;
            priorityQ.swap(empty);
            return true;
        }

        if (coords != start) {
            grid.setColor(coords, sf::Color::Blue);
        }

        auto valid_neighbors = neighbors(coords, grid.getSize(), grid.getCols());
        for (auto point : valid_neighbors) {
            if (!visited.count(point)) {
                priorityQ.push(std::make_pair(manhattanDistance(point), point));
                prev[point.first][point.second] = coords;
            }
        }
    }

    return false;
}


int algorithm::manhattanDistance(std::pair<int,int> start){
    return abs(end.first - start.first) + abs(end.second - start.second);
}