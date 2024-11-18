## A10 - Geometry Problems
### Victor Marchesi

## Description

- Geometry like problems
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/10-A10) to the github instructions.
- I chose [Problem 973 - K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/description/)
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart the code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./p973.pdf) | PDF instructions for problem 973 - K Closest Points to Origin. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem 973 - K Closest Points to Origin. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem 973 - K Closest Points to Origin. |

### Solution in C++
```c++
class Solution {
public:
    // Function to return the k closest points to the origin
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        // Iterate k times to find the closest point
        for (int i = 0; i < k; ++i) {
            int minIndex = 0;

            // Find the index of the closest point
            for (int j = 1; j < points.size(); ++j) {
                int dist1 = points[minIndex][0] * points[minIndex][0] +
                            points[minIndex][1] * points[minIndex][1];
                int dist2 =
                    points[j][0] * points[j][0] + points[j][1] * points[j][1];

                if (dist2 < dist1) {
                    minIndex = j;
                }
            }

            // Add the closest point to the result
            result.push_back(points[minIndex]);

            // Remove the closest point from the list
            points.erase(points.begin() + minIndex);
        }

        return result;
    }
};
```