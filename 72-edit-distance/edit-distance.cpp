class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = solve(s1, s2, i-1, j-1, dp);
        }
        else{
            //Insert
            int x = 1 + solve(s1, s2, i, j-1, dp);
            //Delete
            int y = 1 + solve(s1, s2, i-1, j, dp);
            //Replace
            int z = 1 + solve(s1, s2, i-1, j-1, dp);
            return dp[i][j] = min(x, min(y, z));
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(s1,s2, n-1, m-1, dp);
    }
};