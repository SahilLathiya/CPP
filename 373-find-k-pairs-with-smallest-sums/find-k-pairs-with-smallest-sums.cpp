class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        // Min-heap to store the pairs and their sums
        auto cmp = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first; // Min-heap by sum
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> minHeap(cmp);

        // Initialize the heap with the first element of nums1 and all elements of nums2
        for (int j = 0; j < nums2.size(); ++j) {
            minHeap.push({nums1[0] + nums2[j], {0, j}});
        }

        // Extract the k smallest pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, indices] = minHeap.top();
            minHeap.pop();
            int i = indices.first;
            int j = indices.second;
            
            result.push_back({nums1[i], nums2[j]});
            
            if (i + 1 < nums1.size()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
        }

        return result;
    }
};