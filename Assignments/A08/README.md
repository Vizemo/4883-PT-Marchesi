## A08 - Graphin Sleezy
### Victor Marchesi

## Description

- Both DFS and BFS are foundational graph traversal algorithms that can be used in a variety of problems, including those involving connected components, tree traversals, and exploring graph-based data structures. Here are 5 LeetCode problems that require graph traversal (DFS/BFS). I explicitly avoided shortest path or spanning tree algorithms.
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/08-A08) to the github instructions.
- I chose P200 - Number of Islands, which I solved before the test.
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart the code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./p200.pdf) | PDF instructions for P200 - Number of Islands. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P200 - Number of Islands. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P200 - Number of Islands. |

### Solution in C++
```c++
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';

        // Define possible directions (up, down, left, right) for exploration
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Loop through each direction to explore adjacent cells
        for (int k = 0; k < directions.size(); k++) {
            int tempI = i + directions[k].first;   // Calculate new row index
            int tempJ = j + directions[k].second;  // Calculate new column index

            // Check if the adjacent cell is within bounds and is part of an island ('1')
            if (tempI >= 0 && tempI < grid.size() && tempJ >= 0 &&
                tempJ < grid[0].size() && grid[tempI][tempJ] == '1') {
                // Recursively apply DFS to the adjacent cell to mark connected land
                dfs(grid, tempI, tempJ);
            }
        }
    }

    // Function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        // Return 0 if the grid is empty
        if (grid.empty())
            return 0;

        int numIslands = 0; // Initialize the island count

        // Traverse each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // If the cell contains '1', it is the start of a new island
                if (grid[i][j] == '1') {
                    numIslands++;    // Increment the island count
                    dfs(grid, i, j); // Use DFS to mark the entire island as visited
                }
            }
        }

        // Return the total count of islands found
        return numIslands;
    }
};
```