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
    int maxProfit(int k1, vector<int>& arr) {
        int n = arr.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        // return solve(arr, 0, n, 1, 2, dp);
        
        vector<vector<int>> temp(2, vector<int> (k1+1, 0)), prev(2, vector<int> (k1+1, 0));
        for(int i=0;i<2;i++){
            for(int j=0;j<k1;j++)
                prev[i][j] = 0;
        } 
        temp[0][0] = 0;
        temp[1][0] = 0;
        

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                for(int k=k1;k>0;k--){
                    int profit = 0;
                    if(j){
                        //buy
                        int l = -arr[i] + prev[0][k];
                        //not buy
                        int r = prev[1][k];
                        profit = max(l, r);
                    }
                    else{
                        //sell
                        int l = arr[i] + prev[1][k-1];

                        //not sell
                        int r = prev[0][k];
                        profit = max(l, r);
                    }
                    temp[j][k] = profit;
                }
            }
            prev = temp;
        }
        return prev[1][k1];
    }
};