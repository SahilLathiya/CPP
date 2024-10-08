class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>> &isVisited, int prevHeight){
        if(r<0 || r>=heights.size() || c<0 || c>=heights[0].size()||
            isVisited[r][c] || heights[r][c]<prevHeight)
            return;
        
        isVisited[r][c] = true;
        dfs(r+1, c, heights, isVisited, heights[r][c]); 
        dfs(r-1, c, heights, isVisited, heights[r][c]); 
        dfs(r, c+1, heights, isVisited, heights[r][c]); 
        dfs(r, c-1, heights, isVisited, heights[r][c]); 
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            dfs(i, 0, heights, pacific_reachable, heights[i][0]);
            dfs(i, n-1, heights, atlantic_reachable, heights[i][n-1]);
        }

        for(int i = 0; i < n; i++){
            dfs(0, i, heights, pacific_reachable, heights[0][i]);
            dfs(m-1, i, heights, atlantic_reachable, heights[m-1][i]);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific_reachable[i][j] && atlantic_reachable[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};