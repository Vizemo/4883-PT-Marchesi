## P1281 - Subtract the Product and Sum of Digits of an Integer
### Victor Marchesi

## Description

- I chose problem [P1281. Subtract the Product and Sum of Digits of an Integer](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P1281.pdf) | PDF instructions for P1281. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P1281. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P1281. |

### Solution in C++
```c++
class Solution {
public:
    int subtractProductAndSum(int n) {
        // Convert the integer 'n' to a string to determine its size
        string sizeN = to_string(n);
        // Get the number of digits in the number 'n'
        int size = sizeN.size();
        
        // Initialize 'prod' to store the product of digits, starting with 1
        int prod = 1;
        // Initialize 'sum' to store the sum of digits, starting with 0
        int sum = 0;

        // Loop through each digit of the number
        for(int i = 0; i < size; i++){
            // Multiply the current digits last digit of 'n' to 'prod'
            prod *= n % 10;
            // Add the current digits last digit of 'n' to 'sum'
            sum += n % 10;
            // Remove the last digit of 'n' by dividing it by 10
            n /= 10;
        }

        // Return the result of product minus sum of digits
        return prod - sum;
    }
};
```