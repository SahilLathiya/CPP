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
        // vector<int> dp(n+1, -1);
        // return solve(arr, n-1, n, dp);
        // if(n==0)
        //     return 0;
            
        // dp[0] = arr[0];

        // for(int i=1;i<n;i++){
        //     if(i>1)
        //         dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
        //     else
        //         dp[i] = max(arr[i], dp[i-1]);
        // }
        // return dp[n-1];
        
        if(n==0)
            return 0;

        int prev1 = arr[0];
        int prev2 = 0;
        int prev = 0;
        for(int i=1;i<n;i++){
            prev = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = prev;
        }
        return prev1;
    }
};