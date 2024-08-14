class Solution {
public:
    int solve(vector<vector<int>>& arr, int m, int n, vector<vector<int>> &dp){
        if(n<0 || m < 0 || n>m)
            return INT_MAX;
        
        if(m==0 && n==0){
            return arr[m][n];
        }
        if(dp[m][n]!=-1)
            return dp[m][n];
        long long int l = (long long int)arr[m][n] + solve(arr, m-1, n, dp);
        long long int r = (long long int)arr[m][n] + solve(arr, m-1, n-1, dp);
        return dp[m][n] = min(l,r);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[m-1].size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(m, vector<int> (n));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j] = -1;
                }
            }
            mini = min(mini, solve(arr, m-1, i, dp));
        }
        return mini;
    }
};