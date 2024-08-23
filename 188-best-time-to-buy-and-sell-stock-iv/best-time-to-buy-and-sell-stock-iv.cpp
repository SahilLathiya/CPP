class Solution {
public:
    int solve(vector<int>& arr, int ind, int n, bool canBuy, int remTrans, vector<vector<vector<int>>> &dp){
        if(ind==n || remTrans==0)
            return 0;
        if(dp[ind][canBuy][remTrans]!=-1)
            return dp[ind][canBuy][remTrans];

        int profit = 0;
        if(canBuy){
            //buy
            int l = -arr[ind] + solve(arr, ind+1, n, 0, remTrans, dp);
            //not buy
            int r = solve(arr, ind+1, n, 1, remTrans, dp);
            profit = max(l, r);
        }
        else{
            //sell
            int l = arr[ind] + solve(arr, ind+1, n, 1, remTrans-1, dp);

            //not sell
            int r = solve(arr, ind+1, n, 0, remTrans, dp);
            profit = max(l, r);
        }
        return dp[ind][canBuy][remTrans] = profit;
    }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solve(arr, 0, n, 1, k, dp);
    }
};