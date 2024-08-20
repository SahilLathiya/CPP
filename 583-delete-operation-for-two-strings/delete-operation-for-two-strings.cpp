class Solution {
public:
    int lcs(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        //match
        int l = 0;
        if(s1[ind1]==s2[ind2])
            l = 1 + lcs(s1, s2, ind1-1, ind2-1, dp);
        
        int r1 = 0, r2 = 0;
        // not match
        r1 = lcs(s1,s2,ind1-1,ind2, dp);
        r2 = lcs(s1,s2,ind1,ind2-1, dp);
        return dp[ind1][ind2] = max(l, max(r1, r2));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return n1 + n2 - 2*lcs(word1, word2, n1-1, n2-1, dp);
    }
};