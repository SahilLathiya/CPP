class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // A single node tree
        
        // Build the graph
        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        
        // Trim the leaves layer by layer
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                if (graph[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }
        
        // The remaining nodes are the MHT roots
        return leaves;
    }
};
