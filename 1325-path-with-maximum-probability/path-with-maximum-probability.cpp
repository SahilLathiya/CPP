#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the graph using an adjacency list
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob = succProb[i];
            graph[a].emplace_back(b, prob);
            graph[b].emplace_back(a, prob);
        }

        // Max-heap (priority queue) for probabilities
        priority_queue<pair<double, int>> max_heap;
        max_heap.emplace(1.0, start_node); // Start with probability of 1 at the start node

        // Vector to store maximum probabilities to each node
        vector<double> max_prob(n, 0.0);
        max_prob[start_node] = 1.0;

        while (!max_heap.empty()) {
            auto [prob, node] = max_heap.top();
            max_heap.pop();

            // If we reached the end node, return the probability
            if (node == end_node) {
                return prob;
            }

            // Explore neighbors
            for (const auto& [neighbor, edge_prob] : graph[node]) {
                double new_prob = prob * edge_prob; // Calculate the new probability
                if (new_prob > max_prob[neighbor]) { // Only consider better paths
                    max_prob[neighbor] = new_prob;
                    max_heap.emplace(new_prob, neighbor); // Push to the max-heap
                }
            }
        }

        return 0.0; // If no path exists
    }
};
