## A06 - Hardwood Sneezy
### Victor Marchesi

## Description

- These problems focus on counting frequencies or selecting the top/bottom K elements, using heaps, priority queues, and sorting.
- [LINK](https://github.com/rugbypro f/4883-Programming_Techniques/tree/master/Assignments/06-A06) to the github instructions.
- I chose [P1046](https://leetcode.com/problems/last-stone-weight/)
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart the code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./p1046.pdf) | PDF instructions for P1046 - Last Stone Weight. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P1046 - Last Stone Weight. |
|  3  | [Input data from leetcode](./input.txt) | Input file for problem 1046. |

### Solution in C++
```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x = 0, y = 0; // Values of the two heaviest stones
        int xi = -1, yi = -1; // Indices of the two heaviest stones

        while (stones.size() > 1) {
            // Find the two largest stones and their indices
            x = y = 0;
            xi = yi = -1;
            
            for (int i = 0; i < stones.size(); i++) {
                if (stones[i] > x) {
                    y = x;         // Move the current max to y
                    yi = xi;       // Update the index for y
                    x = stones[i]; // Update x with new max
                    xi = i;        // Update index for x
                } else if (stones[i] > y) {
                    y = stones[i];
                    yi = i;
                }
            }

            // Smash the two heaviest stones
            if (x == y) {
                // If stones are equal, remove both
                stones.erase(stones.begin() + max(xi, yi));
                stones.erase(stones.begin() + min(xi, yi));
            } else {
                // If stones are not equal, replace the largest with the result of (x - y) and remove the second largest
                stones[yi] = x - y;
                stones.erase(stones.begin() + xi);
            }
        }

        // Check if stones is empty and return the appropriate value
        if (stones.empty()) {
            return 0;
        } else {
            return stones[0];
        }
    }
};