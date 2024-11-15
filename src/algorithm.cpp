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

void algorithm::bfs(std::vector<std::vector<sf::RectangleShape>>& grid, std::pair<int,int> start, std::pair<int,int> end){
    std::queue<std::pair<int,int>> q;
    std::set<std::pair<int,int>> visited;
    std::set<std::pair<int,int>> valid_neighbors;
    q.push({start.first,start.second});
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        int row = current.first;
        int col = current.second;
        if (visited.count({row, col})) continue;
        if (grid[row][col].getFillColor() == sf::Color::Black) continue;
        visited.insert({row,col});
        if(row == end.first && col == end.second){
             grid[row][col].setFillColor(sf::Color::Blue);
            break;
        }
        if(row == start.first && col == start.second){
             grid[row][col].setFillColor(sf::Color::Green);
        }else{
            grid[row][col].setFillColor(sf::Color::Red);
        }
        valid_neighbors = neighbors({row,col}, grid.size(), grid[0].size());
        for ( auto point : valid_neighbors){
            if(!visited.count(point)){
                q.push(point);
            }
        }
    }

}