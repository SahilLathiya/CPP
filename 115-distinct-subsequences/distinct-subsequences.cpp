class Solution {
public:
    int solve(string &s, string &t, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind2<0)
            return 1;

        if(ind1<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s[ind1]==t[ind2]){
            //take
            int l = solve(s, t, ind1-1, ind2-1, dp);

            //not take
            int r = solve(s, t, ind1-1, ind2, dp);
            return dp[ind1][ind2] = l+r;
        }

        return dp[ind1][ind2] = solve(s, t, ind1-1, ind2, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m ,-1));
        return solve(s, t, n-1, m-1, dp);
    }   
};