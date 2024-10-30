## A09 - Convex Hull
### Victor Marchesi

## Description

- Convex Hull problems
- [LINK](https://github.com/rugbyprof/4883-Programming_Techniques/tree/master/Assignments/09-A09) to the github instructions.
- I chose P218 - The Skyline Problem
- The file chart below contains the documents for the assignment with short descriptions.
- Underneath the file chart is code solution is displayed.

### Files

|   #   | Files    | Description                      |
| :---: | -------- | -------------------------------- |
|  1  | [Instruction PDF](./REPLACEME.pdf) | PDF instructions for P218 - The Skyline Problem. |
|  2  | [Solution](./solution.cpp) | Solution.cpp for the problem 218 - The Skyline Problem. |
|  3  | [Input data from leetcode](./input.txt) | Input file for the problem 218 - The Skyline Problem. |

### Solution in C++
```c++
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (int i = 0; i < buildings.size(); i++){
            events.push_back(make_pair(buildings[i][0], buildings[i][2]));
            events.push_back(make_pair(buildings[i][1], -buildings[i][2]));
        }

        sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        vector<vector<int>> result;
        vector<int> heights = {0};
        int prevMaxHeight = 0;

        for (int i = 0; i < events.size(); i++){
            int x = events[i].first;
            int h = events[i].second;

            if (h > 0){
                heights.push_back(h);
            } 
            else{
                for (int j = 0; j < heights.size(); j++){
                    if (heights[j] == -h){
                        heights.erase(heights.begin() + j);
                        break;
                    }
                }
            }

            int currMaxHeight = 0;
            for (int j = 0; j < heights.size(); j++){
                if (heights[j] > currMaxHeight){
                    currMaxHeight = heights[j];
                }
            }

            if (currMaxHeight != prevMaxHeight){
                result.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return result;
    }
};