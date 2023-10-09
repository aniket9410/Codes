#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // maze size

// Maze represented as a 2D array
int maze[N][N] = {
    { 1, 0, 0, 0, 0 },
    { 1, 0, 0, 1, 1 },
    { 1, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 1 } 
};

// Function to print the maze
void printMaze() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if rat can move to cell (x, y)
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze
bool solveMaze(int x, int y, vector<vector<int>> &path) {
    // If the rat reaches the end, return true
    if(x == N - 1 && y == N - 1) {
        path.push_back({x, y});
        return true;
    }

    // Check if the rat can move to the cell
    if(isSafe(x, y)) {
        // Add the cell to the path
        path.push_back({x, y});

        // Move down
        if(solveMaze(x + 1, y, path)) {
            return true;
        }

        // Move right
        if(solveMaze(x, y + 1, path)) {
            return true;
        }

        // Remove the cell from the path if none of the moves work
        path.pop_back();
    }

    // If the rat cannot move to the cell, return false
    return false;
}

int main() {
    // Print the maze
    printMaze();

    // Solve the maze
    vector<vector<int>> path;
    bool result = solveMaze(0, 0, path);

    // Print the solution
    if(result) {
        cout << "Solution found:" << endl;
        for(auto p : path) {
            cout << "(" << p[0] << ", " << p[1] << ")" << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
