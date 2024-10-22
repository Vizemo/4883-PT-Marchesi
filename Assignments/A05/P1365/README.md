## 1365 - How Many Numbers Are Smaller Than the Current Number
### Victor Marchesi

## Description

- I chose problem [1365 - How Many Numbers Are Smaller Than the Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/) from the problem [list](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/05-A05).
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./P1365.pdf) | PDF instructions for P1365. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem P1365. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem P1365. |

### Solution in C++
```c++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Result vector to store the count of smaller numbers for each element
        vector<int> ret;
        // Store the size of the input array
        int size = nums.size();
        // Variable to count how many numbers are smaller than the current element
        int count;

        // Outer loop to process each element in the 'nums' array
        for(int i = 0; i < size; i++){
            // Reset the count for the current element
            count = 0;

            // Inner loop to compare the current element with all other elements
            for(int j = 0; j < size; j++){
                // If the current element is greater than another element, increment the count
                if(nums[i] > nums[j]){
                    count++;
                }
            }
            // After comparing with all other elements, push the count into the result vector
            ret.push_back(count);
        }

        // Return the result vector containing the counts of smaller elements for each input element
        return ret;
    }
};