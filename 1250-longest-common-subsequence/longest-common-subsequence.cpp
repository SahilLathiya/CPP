class Solution {
public:
    int solve(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        //match
        int l = 0;
        int r1 = 0, r2 = 0;
        if(s1[ind1]==s2[ind2])
            l = 1 + solve(s1, s2, ind1-1, ind2-1, dp);
        else{
            r1 = solve(s1, s2, ind1-1, ind2, dp);
            r2 = solve(s1, s2, ind1, ind2-1, dp);
        }
        return dp[ind1][ind2] = max(l, max(r1, r2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        // vector<vector<int>> dp(n1, vector<int> (n2, -1));

        // return solve(s1, s2, n1-1, n2-1, dp);


        vector<int> temp(n2, 0), prev(n2, 0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                //match
                int l = 0;
                int r1 = 0, r2 = 0;
                if(i>0 && j>0 && s1[i]==s2[j])
                    l = 1 + prev[j-1];
                else if(s1[i]==s2[j])
                    l = 1;
                else{
                    if(i>0)
                        r1 = prev[j];
                    if(j>0)
                        r2 = temp[j-1];
                }
                temp[j] = max(l, max(r1, r2));
            }
            prev = temp;
        }
        return prev[n2-1];
        
    }
};