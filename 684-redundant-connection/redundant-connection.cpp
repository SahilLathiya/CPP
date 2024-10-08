class Solution {
public:
    int findParent(vector<int> &parent, int node){
        if(parent[node]!=node){
            parent[node] = findParent(parent, parent[node]);
        }
        return parent[node];
    }
    bool unionFind(int u, int v, vector<int> &parent, vector<int> &rank){
        int root1 = findParent(parent, u);
        int root2 = findParent(parent, v);

        if(root1==root2)
            return false;
        else if(rank[root1] < rank[root2]){
            parent[root1] = root2;
        }
        else if(rank[root2] < rank[root1]){
            parent[root2] = root1;
        }
        else{
            parent[root2] = root1;
            rank[root1]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(!unionFind(u, v, parent, rank))
                return {u, v};
        }
        return {};
    }
};