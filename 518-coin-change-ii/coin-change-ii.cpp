class Solution {
public:
    int solve(vector<int>& arr, int ind, int amount, vector<vector<int>> &dp){
        if(amount<0 || ind<0)
            return 0;
        if(amount==0)
            return 1;

        if(dp[ind][amount]!=-1)
            return dp[ind][amount];

        //take
        int l = solve(arr, ind, amount-arr[ind], dp);

        //not take
        int r = solve(arr, ind-1, amount, dp);

        return dp[ind][amount] = l+r;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(coins, n-1, amount, dp);
    }
};