class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> vert;
        for (int i = 0; i < buildings.size(); i++){
            vert.push_back(make_pair(buildings[i][0], buildings[i][2]));
            vert.push_back(make_pair(buildings[i][1], -buildings[i][2]));
        }

        sort(vert.begin(), vert.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        vector<vector<int>> result;
        vector<int> heights = {0};
        int prevMaxHeight = 0;

        for (int i = 0; i < vert.size(); i++){
            int x = vert[i].first;
            int h = vert[i].second;

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