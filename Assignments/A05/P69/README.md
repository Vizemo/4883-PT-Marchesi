## P69 - Sqrt(x)
### Victor Marchesi

## Description

- I chose problem [69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P69.pdf) | PDF instructions for P69. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P69. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P69. |

### Solution in C++
```c++
class Solution {
public:
    int mySqrt(int x) {
        // If x is 0 or 1, return x because the square root of 0 is 0 and the 
        // square root of 1 is 1.
        if (x == 0 || x == 1) return x;

        // Binary search approach requires initializing left, right, and mid.
        // Using long long int to avoid overflow when dealing with large values 
        // of x.
        long long int left = 0;
        long long int right = x;
        long long int mid = 0;

        // Perform binary search until the range is exhausted (right < left)
        while (right >= left) {
            mid = (left + right) / 2;

            if (x == mid * mid) return mid;

            else if (x < mid * mid)
                right = mid - 1;

            else if (x > mid * mid)
                left = mid + 1;
        }

        // If the exact square root is not found, return the floor of the 
        // square root, which is 'right'
        return right;
    }
};