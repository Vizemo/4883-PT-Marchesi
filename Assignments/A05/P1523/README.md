## 1523 - Count Odd Numbers in an Interval Range
### Victor Marchesi

## Description

- I chose problem [1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/palindrome-number/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P1523.pdf) | PDF instructions for P1523. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P1523. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P1523. |

### Solution in Python
```python
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # Calculate how many odd numbers exist between low and high
        oddNums = (high - low) // 2

        # Check if the range between low and high is odd
        if (high - low) % 2 == 1 or low % 2 == 1 or high % 2 == 1:
            oddNums += 1

        return oddNums