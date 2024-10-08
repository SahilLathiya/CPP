class Solution {
private:
    // DFS helper function
    void dfs(int r, int c, vector<vector<bool>>& reachable, vector<vector<int>>& heights, vector<pair<int, int>>& directions, int m, int n) {
        reachable[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !reachable[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, reachable, heights, directions, m, n);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic_reachable(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // Directions for moving in 4 directions: right, left, down, up
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        
        // Perform DFS for cells adjacent to the Pacific and Atlantic oceans
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pacific_reachable, heights, directions, m, n);      // Left column (Pacific)
            dfs(i, n - 1, atlantic_reachable, heights, directions, m, n); // Right column (Atlantic)
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(0, j, pacific_reachable, heights, directions, m, n);      // Top row (Pacific)
            dfs(m - 1, j, atlantic_reachable, heights, directions, m, n); // Bottom row (Atlantic)
        }
        
        // Collect the cells that can reach both oceans
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }


};
