class Solution {
public:
    int solve(vector<vector<int>>& arr, int row, int col, int n, vector<vector<int>> &dp){
        if(row<0 || col<0 || row>=n || col>=n)
            return INT_MAX;
        if(row==0)
            return arr[row][col];
        if(dp[row][col]!=INT_MIN)
            return dp[row][col];
        long long int x = INT_MAX;
        long long int y = INT_MAX;
        long long int z = INT_MAX;

        x = (long long int)arr[row][col] + solve(arr, row-1,col-1, n, dp);
        y = (long long int)arr[row][col] + solve(arr, row-1,col, n, dp);
        z = (long long int)arr[row][col] + solve(arr, row-1,col+1, n, dp);
        return dp[row][col] = min(x, min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = n;
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = INT_MIN;
            }
        }
        for(int i=0;i<m;i++)
            ans = min(ans, solve(arr, n-1, i, n, dp));
        return ans;
    }
};