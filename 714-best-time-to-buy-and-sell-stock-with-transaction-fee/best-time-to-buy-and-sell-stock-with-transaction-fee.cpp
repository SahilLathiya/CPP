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
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // // canBuy   0-No,   1-Yes
        // return solve(arr, 0, n, 1, fee, dp);

        
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int profit = 0;
                if(j){
                    //buy
                    int l = -arr[i] + dp[i+1][0];
                    //not buy
                    int r = dp[i+1][1];
                    profit = max(l, r);
                }
                else{
                    //sell
                    int l = arr[i] + dp[i+1][1] - fee;

                    //not sell
                    int r = dp[i+1][0] ;
                    profit = max(l, r);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};