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
