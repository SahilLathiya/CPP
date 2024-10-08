#include <vector>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false);  // To keep track of points already included in the MST
        vector<int> minDist(n, INT_MAX);  // To store the minimum distance to add each point to the MST
        minDist[0] = 0;  // Start with the first point

        auto manhattanDist = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };

        // Min-heap to pick the point with the smallest edge distance to add to the MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});  // {distance, point_index}

        int mstCost = 0;
        int pointsInMST = 0;

        while (pointsInMST < n) {
            auto [dist, u] = pq.top();
            pq.pop();

            // If the point is already included in the MST, skip it
            if (inMST[u]) continue;

            // Add this point to the MST
            mstCost += dist;
            inMST[u] = true;
            pointsInMST++;

            // Update the distances of the other points not yet in the MST
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int newDist = manhattanDist(u, v);
                    if (newDist < minDist[v]) {
                        minDist[v] = newDist;
                        pq.push({newDist, v});
                    }
                }
            }
        }

        return mstCost;
    }
};
