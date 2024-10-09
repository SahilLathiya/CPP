class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        
        vector<unordered_set<int>> graph(n);
        for(auto e:edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        vector<int> leaves;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==1)
                leaves.push_back(i);
        }

        int totalNodes = n;
        while(totalNodes>2){
            totalNodes -= leaves.size();
            vector<int> newLeaves;
            for(auto l:leaves){
                int neighbor = *graph[l].begin();
                graph[neighbor].erase(l);
                if(graph[neighbor].size()==1){
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }
        
        return leaves;
    }
};