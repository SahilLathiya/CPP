class Solution {
public:
    int solve(vector<int> &arr, int ind, int n, bool canBuy, vector<vector<int>> &dp){
        if(ind==n)
            return 0;

        if(dp[ind][canBuy]!=-1)
            return dp[ind][canBuy];

        int profit = 0;
        if(canBuy){
            //take
            int l = -arr[ind] + solve(arr, ind+1, n, 0, dp);
            //not take
            int r = solve(arr, ind+1, n, 1, dp);
            profit = max(l, r);
        }
        else{
            // take
            int l = arr[ind] + solve(arr, ind+1, n, 1, dp);
            //not take
            int r = solve(arr, ind+1, n, 0, dp);
            profit = max(l, r);
        }
        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(arr, 0, n, 1, dp);

        vector<int> temp(2, 0), prev(2, 0);
        prev[0] = 0;
        prev[1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int profit = 0;
                if(j){
                    //take (buy)
                    int l = -arr[i] + prev[0];
                    //not take
                    int r = prev[1];
                    profit = max(l, r);
                }
                else{
                    // take (sell)
                    int l = arr[i] + prev[1];
                    //not take
                    int r = prev[0];
                    profit = max(l, r);
                }
                temp[j] = profit;
            }
            prev = temp;
        }
        return prev[1];
    }
};