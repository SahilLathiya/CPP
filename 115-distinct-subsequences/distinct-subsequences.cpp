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
        // vector<vector<int>> dp(n, vector<int> (m ,-1));
        // return solve(s, t, n-1, m-1, dp);

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    //take
                    int l = dp[i-1][j-1];

                    //not take
                    int r = dp[i-1][j];
                    dp[i][j] = (long long int)l+r;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }   
};