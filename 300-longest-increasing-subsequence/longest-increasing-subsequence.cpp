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
        // cout<<maxi<<endl;
        // vector<vector<int>> dp(n, vector<int>(maxi+2, -1));
        // return solve(arr, n-1, maxi+1, dp);

        vector<vector<int>> dp(n+1, vector<int>(maxi+2, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0; j<=maxi+1;j++){
                int l = 0;
                //take
                if(arr[i]<j){
                    l = 1 + dp[i][arr[i]];
                }
                //not take
                int r = dp[i][j];
                dp[i+1][j] = max(l, r);
                // cout<<dp[i+1][j]<<' ';
            }
            // cout<<endl;
        }
        // for (auto i : dp[n])
        //     cout<<i<<' ';
        // cout<<dp.size()<<' ';
        // cout<<dp[0].size();
        return dp[n][maxi+1];
        // return 0;
    }
};