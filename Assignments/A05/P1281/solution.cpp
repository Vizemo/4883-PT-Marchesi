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
