class Solution {
public:
    int solve(vector<vector<int>>& arr, int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0)
            return INT_MAX;
        if(m==0 && n==0){
            return arr[m][n];
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        long long int l = (long long int)arr[m][n] + solve(arr, m-1, n, dp);
        long long int r = (long long int)arr[m][n] + solve(arr, m, n-1, dp);
        return dp[m][n] = min(l,r);
    }
    int minPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = -1;

        return solve(arr, m-1, n-1, dp);
    }
};