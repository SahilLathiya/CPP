class Solution {
public:
    int solve(vector<int> &arr, int ind, int n, vector<int> &dp){
        if(ind==0)
            return arr[ind];
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //take current
        int l = arr[ind] + solve(arr, ind-2, n, dp);

        //skip current
        int r = solve(arr, ind-1, n, dp);

        return dp[ind] = max(l,r);
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, n-1, n, dp);
    }
};