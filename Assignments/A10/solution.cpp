class Solution {
public:
    // Function to return the k closest points to the origin
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        // Iterate k times to find the closest point
        for (int i = 0; i < k; ++i) {
            int minIndex = 0;

            // Find the index of the closest point
            for (int j = 1; j < points.size(); ++j) {
                int dist1 = points[minIndex][0] * points[minIndex][0] +
                            points[minIndex][1] * points[minIndex][1];
                int dist2 =
                    points[j][0] * points[j][0] + points[j][1] * points[j][1];

                if (dist2 < dist1) {
                    minIndex = j;
                }
            }

            // Add the closest point to the result
            result.push_back(points[minIndex]);

            // Remove the closest point from the list
            points.erase(points.begin() + minIndex);
        }

        return result;
    }
};