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
        // vector<vector<int>> dp(n, vector<int> (3, -1));
        // // canBuy   0-No, 1-coolDown, 2-yes
        // return solve(arr, 0, n, 2, dp);
        
        vector<int> temp(3, 0), prev(3, 0);
        prev[0] = 0;
        prev[1] = 0;
        prev[2] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=2;j>=0;j--){
                int profit = 0;
                if(j==2){
                    //buy
                    int l = -arr[i] + prev[0];
                    //not buy
                    int r = prev[2];
                    profit = max(l, r);
                }
                else if(j==1){     //cool down
                    profit = prev[2];
                }
                else{
                    //sell
                    int l = arr[i] + prev[1];

                    //not sell
                    int r = prev[0];
                    profit = max(l, r);
                }
                temp[j] = profit;
            }
            prev = temp;
        }
        return prev[2];
    }
};