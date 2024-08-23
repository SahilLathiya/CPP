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
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        // return solve(arr, 0, n, 1, 2, dp);
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++)
                dp[n][i][j] = 0;
        } 
        for(int i=0;i<n+1;i++){
            dp[i][0][0] = 0;
            dp[i][1][0] = 0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=2;k>0;k--){
                    int profit = 0;
                    if(j){
                        //buy
                        int l = -arr[i] + dp[i+1][0][k];
                        //not buy
                        int r = dp[i+1][1][k];
                        profit = max(l, r);
                    }
                    else{
                        //sell
                        int l = arr[i] + dp[i+1][1][k-1];

                        //not sell
                        int r = dp[i+1][0][k];
                        profit = max(l, r);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};