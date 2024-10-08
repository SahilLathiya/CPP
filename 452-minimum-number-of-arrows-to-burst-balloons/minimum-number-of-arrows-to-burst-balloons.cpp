class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        
        // Sort the balloons by their end points (xend)
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Start with one arrow shot at the end of the first balloon
        int arrows = 1;
        int arrow_position = points[0][1];
        
        // Traverse through the balloons
        for (int i = 1; i < points.size(); ++i) {
            // If the start of the current balloon is beyond the arrow's position,
            // we need a new arrow for this balloon
            if (points[i][0] > arrow_position) {
                ++arrows;
                arrow_position = points[i][1];  // Move the arrow to the end of this balloon
            }
        }
        
        return arrows;
    }
};
