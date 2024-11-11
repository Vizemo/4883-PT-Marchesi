## P01 - Problem Prsentation
### Victor Marchesi

## Description

- Choose a problem from Leetcode, Neetcode, Uva Online Judge, or any other source that you find a problem that would be interesting to discuss.
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/12-P01) to the github instructions.
- I chose leetcode problem number 72 to present
- [Link to the problem.](https://leetcode.com/problems/edit-distance/description/)

### Files
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart the code solution is displayed.

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./p72.pdf) | PDF instructions for problem number 72 from leetcode. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem number 72 from leetcode. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem number 72 from leetcode. |
|  4  | [Powerpoint](./p72_VM.ppsx) | Powerpoint show used to aid the presentation for problem number 72 from leetcode. |

### Solution in C++
```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Get the lengths of word1 and word2
        int m = word1.size();
        int n = word2.size();

        // Initialize a 2D DP table with (m+1) x (n+1) dimensions
        // dp[i][j] will store the minimum edit distance to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: Converting word1 to an empty word2 requires i deletions
        for (int i = 0; i <= m; i++) dp[i][0] = i;

        // Base case: Converting an empty word1 to word2 requires j insertions
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        // Fill the DP table by calculating dp[i][j] for each i and j
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters are the same, no operation is needed; take previous diagonal value
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Calculate costs for deletion, insertion, and substitution
                    int deleteCost = dp[i - 1][j];        // Deleting a character from word1
                    int insertCost = dp[i][j - 1];        // Inserting a character to word1
                    int substituteCost = dp[i - 1][j - 1]; // Replacing a character in word1

                    // Find the minimum cost among the three operations
                    int minCost = deleteCost;
                    if (insertCost < minCost) minCost = insertCost;
                    if (substituteCost < minCost) minCost = substituteCost;

                    // Add 1 to the minimum cost (for the current operation) and store in dp[i][j]
                    dp[i][j] = 1 + minCost;
                }
            }
        }

        // The answer is in dp[m][n], which holds the edit distance between word1 and word2
        return dp[m][n];
    }
};