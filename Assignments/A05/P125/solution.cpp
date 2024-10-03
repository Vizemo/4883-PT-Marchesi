#include <string>
#include <cctype> // for tolower() & isalnum()
#include <algorithm> // For reverse()

class Solution {
public:
    bool isPalindrome(string s) {
        string fString = "";

        // Process the string: convert to lowercase and keep only alphanumeric
        for (int i = 0; i < s.length(); i++) {
            char lowerChar = tolower(s[i]);

            // Append only alphanumeric characters
            if (isalnum(lowerChar)) {
                fString += lowerChar;
            }
        }

        // Check if the processed string is a palindrome
        string revString = fString;
        reverse(revString.begin(), revString.end());

        if (fString == revString) return true;
        else return false;
    }
};