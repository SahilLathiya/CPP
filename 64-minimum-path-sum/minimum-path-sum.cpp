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

        // return solve(arr, m-1, n-1, dp);
        dp[0][0] = arr[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                long long int l = INT_MAX, r = INT_MAX;
                if(i>0){
                    l = arr[i][j] + (long long int)dp[i-1][j];
                }
                if(j>0){
                    r = arr[i][j] + (long long int)dp[i][j-1];
                }
                dp[i][j] = min(l,r);
            }
        }
        return dp[m-1][n-1];
    }
};