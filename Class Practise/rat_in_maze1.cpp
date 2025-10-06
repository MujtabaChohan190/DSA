#include <iostream>
using namespace std;

void drone(char maze[][6], int row, int col, char path[][6]) {
    // Step 1: Check boundaries or walls (F)
    if (row < 0 || col < 0 || row >= 6 || col >= 6 || maze[row][col] == 'F') {
        return;
    }

    // Step 2: If we reached 'H' (Home)
    if (maze[row][col] == 'H') {
        path[row][col] = 'H';

        // Count how many 'S' cells are used in this path
        int count = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (path[i][j] == 'S') count++;
            }
        }

        // Step 3: Print path if within 8 steps
        if (count <= 8) {
            cout << "Path found:\n";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    cout << path[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    // Step 4: Mark current cell as visited in both arrays
    path[row][col] = maze[row][col];
    maze[row][col] = 'F';  // mark as visited to avoid revisiting

    // Step 5: Move in all four directions (recursive calls)
    drone(maze, row + 1, col, path); // down
    drone(maze, row - 1, col, path); // up
    drone(maze, row, col + 1, path); // right
    drone(maze, row, col - 1, path); // left

    // Step 6: Undo (Backtrack)
    maze[row][col] = path[row][col];
    path[row][col] = 'o';
}

int main() {
    char maze[6][6] = {
        {'D','S','S','F','D','F'},
        {'S','S','S','F','S','D'},
        {'S','D','S','S','S','F'},	
        {'F','S','F','S','S','F'},
        {'S','S','S','D','S','F'},
        {'S','F','S','S','S','H'}
    };

    char path[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            path[i][j] = 'o'; // empty initially
        }
    }

    // Start from top-left corner
    drone(maze, 0, 0, path);
}
