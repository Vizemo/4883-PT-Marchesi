## 1342 - Number of Steps to Reduce a Number to Zero
### Victor Marchesi

## Description

- I chose problem [1342 - Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P1342.pdf) | PDF instructions for P1342. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P1342. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P1342. |

### Solution in C++
```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        // Initialize a counter to track the number of steps
        int count = 0;

        // Continue the process until the number becomes 0
        while(num != 0)
        {
            // If the number is even, divide it by 2 and increment the step count
            if(num % 2 == 0){
                num /= 2;
                count++;
            }
            // If the number is odd, subtract 1 and increment the step count
            else{
                num -= 1;
                count++;
            }
        }
        
        // Return the total number of steps taken
        return count;
    }
};