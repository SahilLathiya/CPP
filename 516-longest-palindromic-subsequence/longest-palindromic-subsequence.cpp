class Solution {
public:
    int solve(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2< 0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        //match
        int l = 0;
        if(s1[ind1]==s2[ind2])
            l = 1 + solve(s1, s2, ind1-1, ind2-1, dp);

        //not match
        int r1 = 0, r2 = 0;
        r1 = solve(s1, s2, ind1-1, ind2, dp);
        r2 = solve(s1, s2, ind1, ind2-1, dp);
        return dp[ind1][ind2]=max(l, max(r1, r2));
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(s1, s, n-1, n-1, dp);

        vector<int> temp(n+1, 0), prev(n+1, 0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //match
                int l = 0;
                if(s1[i-1]==s[j-1])
                    l = 1 + prev[j-1];

                //not match
                int r1 = 0, r2 = 0;
                r1 = prev[j];
                r2 = temp[j-1];
                temp[j]=max(l, max(r1, r2));
            }
            prev = temp;
        }
        return prev[n];
    }
};