class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(); // Get the size of the digits array
        
        // Loop through the digits array starting from the last element
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += 1; // Add one to the current index value
            
            // If after adding 1, the digit becomes 10, set it to 0
            if (digits[i] == 10) digits[i] = 0;

            // If the digit does not become 10, we can return the result
            else return digits;
        }
        
        // If the loop completes, that means we had to carry a 1 beyond the
        // most significant digit. This happens, for example, if the input was
        // [9, 9, 9], so we add a '1' at the beginning
        digits.insert(digits.begin(), 1);
        
        // Return the modified digits array
        return digits;
    }
};
