class Solution {
public:
    int solve(vector<int> &arr, int ind, int target, vector<vector<int>> &dp){
        // cout<<ind<<' ';
        if(ind==0){
            if(arr[0]==0 && target==0)
                return 2;
            if(target==arr[0] || target==-arr[0])
                return 1;
            return 0;
        }
        // cout<<20000-target<<' ';
        if(dp[ind][20000-target]!=-1)
            return dp[ind][20000-target];

        //take as it is
        int l = solve(arr, ind-1, target-arr[ind], dp);

        // take negative
        int r = solve(arr, ind-1, target+arr[ind], dp);
        return dp[ind][20000-target] = l+r;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int> (40000+1, -1));
        return solve(arr, n-1, target, dp);
        return 1;
    }
};