class Solution {
public:
    long long int solve(vector<int>& arr, int ind, int sum, vector<vector<int>> &dp){
        if(sum < 0 || ind < 0)
            return INT_MAX;
        if(sum==0)
            return 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        long long int l = 1 + solve(arr, ind, sum-arr[ind], dp);
        long long int r = solve(arr, ind-1, sum, dp);
        return dp[ind][sum] = min(l,r);
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(arr, n-1, amount, dp);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};