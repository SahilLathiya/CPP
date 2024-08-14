class Solution {
public:
    int solve(vector<vector<int>>& arr, int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0 || arr[m][n]==1)
            return 0;
        if(m==0 && n==0)
            return 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        int l = solve(arr, m-1, n, dp);
        int r = solve(arr, m, n-1, dp);
        return dp[m][n] = l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = -1;

        // return solve(arr, m-1,n-1, dp);

        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                int l=0,r=0;
                if(i>0 && arr[i-1][j]!=1){
                    l = dp[i-1][j];
                }
                if(j>0 && arr[i][j-1]!=1){
                    r = dp[i][j-1];
                }
                dp[i][j] = l+r;
            }
        }
        if(arr[m-1][n-1]==1)
            return 0;
        return dp[m-1][n-1];
    }
};