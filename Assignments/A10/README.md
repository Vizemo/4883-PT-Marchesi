## A10 - Geometry Problems
### Victor Marchesi

## Description

- Geometry like problems
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/10-A10) to the github instructions.
- I chose [Problem 973 - K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/description/)
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart the code solution is displayed.
**Note:** The third input on the input.txt failed because my code was too slow.
- I sped up the solution by swapping the closest point with the last point in the list and removing it. Instead of what I did previously where I was shifting all the remaining points around.

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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        for (int i = 0; i < k; ++i) {
            int minIndex = 0;

            for (int j = 1; j < points.size(); ++j) {
                int dist1 = points[minIndex][0] * points[minIndex][0] +
                            points[minIndex][1] * points[minIndex][1];
                int dist2 =
                    points[j][0] * points[j][0] + points[j][1] * points[j][1];

                if (dist2 < dist1) {
                    minIndex = j;
                }
            }

            result.push_back(points[minIndex]);

            points[minIndex] = points.back();
            points.pop_back();
        }

        return result;
    }
};
```