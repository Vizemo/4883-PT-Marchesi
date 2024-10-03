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