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

| # | Files | Description |
| - | - | - |
| 1 | [Instruction PDF](./p72.pdf) | PDF instructions for problem number 72 from leetcode. |
| 2 | [Solution](./solution.cpp) | Solution.cpp for the problem number 72 from leetcode. |
| 3 | [Input data from leetcode](./input.txt) | Input file for the problem number 72 from leetcode. |
| 4 | [Powerpoint](./p72-VM.pptx) | Powerpoint show used to aid the presentation for problem number 72 from leetcode. |

### Solution in C++
```c++
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
```

#### Problem Setup
We are comparing `word1 = "horse"` and `word2 = "ros"`.

#### Initial DP Table
The table starts with all entries initialized to `0`:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 0 | 0 | 0 |
| h | 0 | 0 | 0 | 0 |
| o | 0 | 0 | 0 | 0 |
| r | 0 | 0 | 0 | 0 |
| s | 0 | 0 | 0 | 0 |
| e | 0 | 0 | 0 | 0 |

#### Step 1: Fill Base Cases

1. Fill the first row with increasing values for inserting each character in `word2`:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | **1** | **2** | **3** |
| h | 0 | 0 | 0 | 0 |
| o | 0 | 0 | 0 | 0 |
| r | 0 | 0 | 0 | 0 |
| s | 0 | 0 | 0 | 0 |
| e | 0 | 0 | 0 | 0 |

2. Fill the first column with increasing values for deleting each character in `word1`:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | **1** | 0 | 0 | 0 |
| o | **2** | 0 | 0 | 0 |
| r | **3** | 0 | 0 | 0 |
| s | **4** | 0 | 0 | 0 |
| e | **5** | 0 | 0 | 0 |

#### Step 2: Fill DP Table Using Levenshtein Distance Algorithm

Now we proceed to fill the table row by row, comparing characters in `word1` and `word2` and calculating the minimum edit distance for each cell.

##### Row 1 (i = 1, Comparing 'h' in `word1`)

1. **i = 1, j = 1** (Comparing 'h' and 'r'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[0][1] + 1 = 2`
     - Insert: `dp[1][0] + 1 = 2`
     - Substitute: `dp[0][0] + 1 = 1`
   - Minimum cost is `1`, so `dp[1][1] = 1`.

2. **i = 1, j = 2** (Comparing 'h' and 'o'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[0][2] + 1 = 3`
     - Insert: `dp[1][1] + 1 = 2`
     - Substitute: `dp[0][1] + 1 = 2`
   - Minimum cost is `2`, so `dp[1][2] = 2`.

3. **i = 1, j = 3** (Comparing 'h' and 's'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[0][3] + 1 = 4`
     - Insert: `dp[1][2] + 1 = 3`
     - Substitute: `dp[0][2] + 1 = 3`
   - Minimum cost is `3`, so `dp[1][3] = 3`.

After completing row 1, the DP table looks like this:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | 1 | **1** | **2** | **3** |
| o | 2 | 0 | 0 | 0 |
| r | 3 | 0 | 0 | 0 |
| s | 4 | 0 | 0 | 0 |
| e | 5 | 0 | 0 | 0 |

##### Row 2 (i = 2, Comparing 'o' in `word1`)

1. **i = 2, j = 1** (Comparing 'o' and 'r'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[1][1] + 1 = 2`
     - Insert: `dp[2][0] + 1 = 3`
     - Substitute: `dp[1][0] + 1 = 2`
   - Minimum cost is `2`, so `dp[2][1] = 2`.

2. **i = 2, j = 2** (Comparing 'o' and 'o'):
   - Characters match, so `dp[2][2] = dp[1][1] = 1`.

3. **i = 2, j = 3** (Comparing 'o' and 's'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[1][3] + 1 = 4`
     - Insert: `dp[2][2] + 1 = 2`
     - Substitute: `dp[1][2] + 1 = 3`
   - Minimum cost is `2`, so `dp[2][3] = 2`.

After completing row 2, the DP table looks like this:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | 1 | 1 | 2 | 3 |
| o | 2 | **2** | **1** | **2** |
| r | 3 | 0 | 0 | 0 |
| s | 4 | 0 | 0 | 0 |
| e | 5 | 0 | 0 | 0 |

##### Row 3 (i = 3, Comparing 'r' in `word1`)

1. **i = 3, j = 1** (Comparing 'r' and 'r'):
   - Characters match, so `dp[3][1] = dp[2][0] = 2`.

2. **i = 3, j = 2** (Comparing 'r' and 'o'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[2][2] + 1 = 2`
     - Insert: `dp[3][1] + 1 = 3`
     - Substitute: `dp[2][1] + 1 = 3`
   - Minimum cost is `2`, so `dp[3][2] = 2`.

3. **i = 3, j = 3** (Comparing 'r' and 's'):
   - Characters don't match.
   - Costs:
     - Delete: `dp[2][3] + 1 = 3`
     - Insert: `dp[3][2] + 1 = 3`
     - Substitute: `dp[2][2] + 1 = 2`
   - Minimum cost is `2`, so `dp[3][3] = 2`.

After completing row 3, the DP table looks like this:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | 1 | 1 | 2 | 3 |
| o | 2 | 2 | 1 | 2 |
| r | 3 | **2** | **2** | **2** |
| s | 4 | 0 | 0 | 0 |
| e | 5 | 0 | 0 | 0 |

##### Row 4 (i = 4, Comparing 's' in `word1`)

1. **i = 4, j = 1** (Comparing 's' and 'r'):
   - Characters don't match.
   - Minimum cost is `3`, so `dp[4][1] = 3`.

2. **i = 4, j = 2** (Comparing 's' and 'o'):
   - Characters don't match.
   - Minimum cost is `3`, so `dp[4][2] = 3`.

3. **i = 4, j = 3** (Comparing 's' and 's'):
   - Characters match, so `dp[4][3] = dp[3][2] = 2`.

After completing row 4, the DP table looks like this:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | 1 | 1 | 2 | 3 |
| o | 2 | 2 | 1 | 2 |
| r | 3 | 2 | 2 | 2 |
| s | 4 | **3** | **3** | **2** |
| e | 5 | 0 | 0 | 0 |

##### Row 5 (i = 5, Comparing 'e' in `word1`)

1. **i = 5, j = 1** (Comparing 'e' and 'r'):
   - Characters don't match.
   - Minimum cost is `4`, so `dp[5][1] = 4`.

2. **i = 5, j = 2** (Comparing 'e' and 'o'):
   - Characters don't match.
   - Minimum cost is `3`, so `dp[5][2] = 3`.

3. **i = 5, j = 3** (Comparing 'e' and 's'):
   - Characters don't match.
   - Minimum cost is `3`, so `dp[5][3] = 3`.

Final DP Table:

|   |   | r | o | s |
|---|---|---|---|---|
|   | 0 | 1 | 2 | 3 |
| h | 1 | 1 | 2 | 3 |
| o | 2 | 2 | 1 | 2 |
| r | 3 | 2 | 2 | 2 |
| s | 4 | 3 | 3 | 2 |
| e | 5 | **4** | **3** | **3** |

The answer is in `dp[5][3] = 3`, meaning the minimum edit distance is `3`.