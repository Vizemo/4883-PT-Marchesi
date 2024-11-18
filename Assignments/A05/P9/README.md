## P9 - Palindrome Number
### Victor Marchesi

## Description

- I chose problem [9. Palindrome Number](https://leetcode.com/problems/palindrome-number/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P9.pdf) | PDF instructions for P9. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P9. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P9. |

### Solution in C++
```c++
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string reverseStr = "";
        // convert int to string
        string numStr = to_string(x);

        // reverse the string
        for (int i = numStr.length() - 1; i >= 0; i--){
            reverseStr += numStr[i];
        }

        // compare the string
        if (numStr == reverseStr)
            return true;
        else
            return false;
    }
};
```