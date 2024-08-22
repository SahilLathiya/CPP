class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i< 0 && j<0)
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0){
            for(int x=j;x>=0;x--)
                if(p[x]!='*'){
                    // cout<<p[j]<<endl;
                    return false;
                }
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        // match or '?'
        if(s[i]==p[j] || p[j]=='?')
            return solve(s, p, i-1, j-1, dp);
        
        // '*'
        if(p[j]=='*'){
            // condiser * as 0 len
            bool l = solve(s, p, i, j-1, dp);
            // consider * as 1 len
            bool r = solve(s, p, i-1, j, dp);
            return dp[i][j] = l | r;
        }

        // not match
        // return dp[i][j] = false;
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};