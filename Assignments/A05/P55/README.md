## 55 - Jump Game
### Victor Marchesi

## Description

- I chose problem [55. Jump Game](https://leetcode.com/problems/jump-game/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P55.pdf) | PDF instructions for P55. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P55. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P55. |

### Solution in C++
```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Start at the first index
        int index = 0;
        // Keep track of the farthest index we can reach
        int farthest = 0;
        // Store the last index of the array
        int size = nums.size() - 1;

        // Loop as long as the current index is within the farthest 
        // reachable position
        while (index <= farthest) {
            // Update the farthest index we can reach from the current position
            if (index + nums[index] > farthest) 
                farthest = index + nums[index];

            // If we can reach or go beyond the last index, return true
            if (farthest >= size) 
                return true;

            // Move to the next index
            index++;
        }

        // If we exit the loop without reaching the last index, return false
        return false;
    }
};