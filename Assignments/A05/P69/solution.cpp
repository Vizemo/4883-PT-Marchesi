class Solution {
public:
    int mySqrt(int x) {
        // If x is 0 or 1, return x because the square root of 0 is 0 and the 
        // square root of 1 is 1.
        if (x == 0 || x == 1) return x;

        // Binary search approach requires initializing left, right, and mid.
        // Using long long int to avoid overflow when dealing with large values 
        // of x.
        long long int left = 0;
        long long int right = x;
        long long int mid = 0;

        // Perform binary search until the range is exhausted (right < left)
        while (right >= left) {
            mid = (left + right) / 2;

            if (x == mid * mid) return mid;

            else if (x < mid * mid)
                right = mid - 1;

            else if (x > mid * mid)
                left = mid + 1;
        }

        // If the exact square root is not found, return the floor of the 
        // square root, which is 'right'
        return right;
    }
};
