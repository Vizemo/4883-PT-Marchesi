#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string reverseStr = "";
        string numStr = to_string(x);

        for (int i = numStr.length() - 1; i >= 0; i--){
            reverseStr += numStr[i];
        }

        if (numStr == reverseStr)
            return true;
        else
            return false;
    }
};