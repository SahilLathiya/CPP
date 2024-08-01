class Solution {
public:
    int solve(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x>=m || y>=n)
            return 0;
        
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(x==m-1 && y==n-1)
            return dp[x][y] = solve(x+1,y,m,n,dp) + solve(x,y+1,m,n,dp) + 1;
        return dp[x][y] = solve(x+1,y,m,n,dp) + solve(x,y+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = -1;

        return solve(0,0,m,n,dp);
    }
};