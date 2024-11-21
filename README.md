# Pathfinding Algorithm Visualizer: SFML 

## Overview
Welcome to the **Pathfinding Algorithm Visualizer**. 
This project allows you to visually explore how algorithms like BFS, GBFS, and A* calculate paths in a grid-based environment. By customizing grid layouts and observing step-by-step computations, you’ll gain a deeper understanding of these algorithms.

## How it Works

The visualizer uses **SFML** to create an interactive grid-based interface where you can explore how pathfinding algorithms work. Here's what you can do:  

### Grid Interaction
- **Set Start Point**: Press `S` and left-click on a grid cell to set the start point.  
- **Set End Point**: Press `F` and left-click on a grid cell to set the end point.  
- **Add Obstacles**: Right-click on a grid cell to add an obstacle.  
- **Clear Obstacles**: Right-click again on an obstacle to remove it.  
- **Clear the Board**: Press `C` to reset the entire grid.

### Algorithms
You can choose from three pathfinding algorithms:  
- **BFS**: Breadth-First Search systematically explores all nodes at the same depth before proceeding deeper.  
- **GBFS**: Greedy Best-First Search prioritizes nodes closer to the target using a heuristic function.  
- **A***: A-Star Algorithm uses both actual cost and heuristic cost for efficient pathfinding.  

### Running an Algorithm
- Press `B` to run **BFS**.  
- Press `G` to run **GBFS**.  
- Press `A` to run **A***.  

Once an algorithm is selected, the visualizer dynamically illustrates how it explores nodes, avoids obstacles, and determines the shortest path between the start and end points.

## What You'll Need
- **SFML 2.5**

## Features
- **Real-Time Visualization**: Displays every step the algorithm takes to find a path.
- **Interactive Grid**: Allows users to draw obstacles, set start/end points, and reset the grid.
- **Multiple Algorithm Options**: Compare how BFS, GBFS, and A* behave under the same conditions.

## Steps to Run the Program

1. **Clone the Repository**  
   ```bash
   git clone https://github.com/Argatmj/algorithm-visualizer.git
2. Install SFML
   ```bash
    sudo apt-get install libsfml-dev
4. Build the Program 
   ```bash
   make
6. Run the Program
   ```bash
   ./main 
## Demo
Check out the demo:

[![Pathfinding Algorithm Visualizer Demo](https://img.youtube.com/vi/IgNzDYCisxY/0.jpg)](https://www.youtube.com/watch?v=IgNzDYCisxY)
