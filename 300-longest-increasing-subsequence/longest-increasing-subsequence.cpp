class Solution {
public:
    int solve(vector<int>& arr, int ind, int lastTaken, vector<vector<int>> &dp){
        if(ind<0)
            return 0;
        if(dp[ind][lastTaken]!=-1)
            return dp[ind][lastTaken];

        int l = 0;
        //take
        if(arr[ind]<lastTaken){
            l = 1 + solve(arr, ind-1, arr[ind], dp);
        }
        //not take

        int r = solve(arr, ind-1, lastTaken, dp);
        return dp[ind][lastTaken] = max(l, r);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
            mini = min(mini, arr[i]);
        
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            arr[i] -=mini;
            maxi = max(maxi, arr[i]);
        }
        vector<vector<int>> dp(n, vector<int>(maxi+2, -1));
        return solve(arr, n-1, maxi+1, dp);
    }
};