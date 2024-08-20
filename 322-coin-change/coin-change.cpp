class Solution {
public:
    int solve(vector<int>& arr, int ind, int amount, vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(ind<0 || amount<0)
            return 1e9;
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        //take
        int l = 1e9;
        if(arr[ind]<=amount)
            l = 1 + solve(arr, ind, amount-arr[ind], dp);
            
        //not take
        int r = solve(arr, ind-1, amount, dp);

        return dp[ind][amount]=min(l,r);
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = solve(arr, n-1, amount, dp);
        if(ans==1e9)
            return -1;
        return ans;
    }
};