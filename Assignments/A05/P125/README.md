## 125 - Valid Palindrome
### Victor Marchesi

## Description

- I chose problem [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P125.pdf) | PDF instructions for P125. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P125. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P125. |

### Solution in C++
```c++
#include <string>
#include <cctype> // for tolower() & isalnum()
#include <algorithm> // For reverse()

class Solution {
public:
    bool isPalindrome(string s) {
        string fString = "";

        // Process the string: convert to lowercase and keep only alphanumeric
        for (int i = 0; i < s.length(); i++) {
            char lowerChar = tolower(s[i]);

            // Append only alphanumeric characters
            if (isalnum(lowerChar)) {
                fString += lowerChar;
            }
        }

        // Check if the processed string is a palindrome
        string revString = fString;
        reverse(revString.begin(), revString.end());

        if (fString == revString) return true;
        else return false;
    }
};