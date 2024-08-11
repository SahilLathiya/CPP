class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        //1-step
        int l = solve(n-1, dp);
        //2-step
        int r = solve(n-2, dp);
        return dp[n] = l+r;
    }
    int climbStairs(int n) {
        if(n<=2)
            return n;
        vector<int> dp(n+1, -1);
        // return solve(n, dp);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};