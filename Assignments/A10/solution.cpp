class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        for (int i = 0; i < k; ++i) {
            int minIndex = 0;

            for (int j = 1; j < points.size(); ++j) {
                int dist1 = points[minIndex][0] * points[minIndex][0] +
                            points[minIndex][1] * points[minIndex][1];
                int dist2 =
                    points[j][0] * points[j][0] + points[j][1] * points[j][1];

                if (dist2 < dist1) {
                    minIndex = j;
                }
            }

            result.push_back(points[minIndex]);

            points[minIndex] = points.back();
            points.pop_back();
        }

        return result;
    }
};