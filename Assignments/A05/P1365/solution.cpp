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