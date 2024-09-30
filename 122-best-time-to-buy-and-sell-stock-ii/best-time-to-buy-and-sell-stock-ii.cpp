class Solution {
public:
    int solve(vector<int>& arr, int ind, int n, bool canBuy, vector<vector<int>> &dp){
        if(ind==n)
            return 0;
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];

        if(canBuy){
            // Buy
            int l = -arr[ind] + solve(arr, ind+1, n, false, dp);

            // Not Buy
            int r = solve(arr, ind+1, n, canBuy, dp);
            return dp[ind][canBuy] = max(l, r);
        }
        else {
            // Sale
            int l = arr[ind] + solve(arr, ind+1, n, true, dp);
            // Not Sale
            int r = solve(arr, ind+1, n, false, dp);
            return dp[ind][canBuy] = max(l, r);
        }
        return -1;
    }
    int maxProfit(vector<int>& arr) {
        // int ans = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(arr, 0, n, true, dp);
    }
};