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
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // return solve(arr, n-1, amount, dp);
        
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i=0;i<n;i++)
            dp[i][0] = 1;

        for(int ind=0; ind<n; ind++){
            for(int j=0; j<=amount; j++){
                if(ind==0 && j==0)
                    continue;

                //take
                int l = 0;
                if(j>=arr[ind])
                    l = dp[ind][j-arr[ind]];

                //not take
                int r = 0;
                if(ind>0)
                    r = dp[ind-1][j];
                
                dp[ind][j] = l+r;
            }
        }
        return dp[n-1][amount];
    }
};