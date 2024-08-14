class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0)
            return 0;
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        int l = solve(m-1,n, dp);
        int r = solve(m,n-1, dp);
        return dp[m][n] = l+r;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int> (n));
        // for(int i=0;i<m;i++)
        //     for(int j=0;j<n;j++)
        //         dp[i][j] = -1;
        // return solve(m-1, n-1, dp);

        // for(int i=0;i<m;i++)
        //     dp[i][0] = 1;
        
        // for(int i=0;i<n;i++)
        //     dp[0][i] = 1;

        vector<int> prev(n, 0);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            temp[0] = 1;
            for(int j=1;j<n;j++){
                temp[j] = prev[j] + temp[j-1];
            }
            prev = temp;
        }
        return prev[n-1];
    }
};