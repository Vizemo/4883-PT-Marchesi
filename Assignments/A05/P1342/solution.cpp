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