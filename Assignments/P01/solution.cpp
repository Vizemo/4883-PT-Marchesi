class Solution {
public:
    int minDistance(string word1, string word2) {
        // Get the lengths of word1 and word2
        int m = word1.size();
        int n = word2.size();

        // Initialize a 2D DP table with (m+1) x (n+1) dimensions
        // dpt[i][j] will store the minimum edit distance to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dpt(m + 1, vector<int>(n + 1, 0));

        // Converting word1 to an empty word2 requires m deletions
        for (int i = 0; i <= m; i++) dpt[i][0] = i;

        // Converting an empty word1 to word2 requires n insertions
        for (int i = 0; i <= n; i++) dpt[0][i] = i;

        // Fill the DP table by calculating dpt[i][j] for each i and j
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters are the same, no operation is needed
                if (word1[i - 1] == word2[j - 1]) {
                    dpt[i][j] = dpt[i - 1][j - 1];
                } else {
                    // Calculate costs for deletion, insertion, and substitution
                    int deleteCost = dpt[i - 1][j];         // Deleting a character from word1
                    int insertCost = dpt[i][j - 1];         // Inserting a character to word1
                    int substituteCost = dpt[i - 1][j - 1]; // Replacing a character in word1

                    // Find the minimum cost among the three operations
                    int minCost = deleteCost;
                    if (insertCost < minCost) minCost = insertCost;
                    if (substituteCost < minCost) minCost = substituteCost;

                    // Add 1 to the minimum cost (for the current operation) and store in dpt[i][j]
                    dpt[i][j] = 1 + minCost;
                }
            }
        }

        // The answer is in dpt[m][n], which holds the edit distance between word1 and word2
        return dpt[m][n];
    }
};