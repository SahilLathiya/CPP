class Solution {
public:
    int solve(vector<int>& arr, int ind, int n, int canBuy, int fee, vector<vector<int>> &dp){
        if(ind==n)
            return 0;
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];

        int profit = 0;
        if(canBuy){
            //buy
            int l = -arr[ind] + solve(arr, ind+1, n, 0, fee, dp);
            //not buy
            int r = solve(arr, ind+1, n, 1, fee, dp);
            profit = max(l, r);
        }
        else{
            //sell
            int l = arr[ind] + solve(arr, ind+1, n, 1, fee, dp) - fee;

            //not sell
            int r = solve(arr, ind+1, n, 0, fee, dp) ;
            profit = max(l, r);
        }
        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        // canBuy   0-No,   1-Yes
        return solve(arr, 0, n, 1, fee, dp);
    }
};