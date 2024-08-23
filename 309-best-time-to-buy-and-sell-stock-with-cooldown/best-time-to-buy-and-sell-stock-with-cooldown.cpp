class Solution {
public:
    int solve(vector<int>& arr, int ind, int n, int canBuy, vector<vector<int>> &dp){
        if(ind==n)
            return 0;
        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];
        int profit = 0;
        if(canBuy==2){
            //buy
            int l = -arr[ind] + solve(arr, ind+1, n, 0, dp);
            //not buy
            int r = solve(arr, ind+1, n, 2, dp);
            profit = max(l, r);
        }
        else if(canBuy==1){     //cool down
            profit = solve(arr, ind+1, n, 2, dp);
        }
        else{
            //sell
            int l = arr[ind] + solve(arr, ind+1, n, 1, dp);

            //not sell
            int r = solve(arr, ind+1, n, 0, dp);
            profit = max(l, r);
        }
        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        // canBuy   0-No, 1-coolDown, 2-yes
        return solve(arr, 0, n, 2, dp);
    }
};