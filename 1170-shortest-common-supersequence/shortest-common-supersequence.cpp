class Solution {
public:
    int solve(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        //match
        int l = 0;
        if(s1[ind1]==s2[ind2])
            l = 1 + solve(s1, s2, ind1-1, ind2-1, dp);

        //not match
        int r1=0, r2=0;
        r1 = solve(s1, s2, ind1-1, ind2, dp);
        r2 = solve(s1, s2, ind1, ind2-1, dp);

        return dp[ind1][ind2]=max(l, max(r1, r2));
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // vector<vector<int>> dp(n1, vector<int> (n2, -1));
        // int lcs_len = solve(s1, s2, n1-1, n2-1, dp);
        // int scs_len = n1+n2-lcs_len;
        // cout<<scs_len<<endl;


        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        for(int i=1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                //match
                int l = 0;
                if(s1[i-1]==s2[j-1])
                    l = 1 + dp[i-1][j-1];

                //not match
                int r1=0, r2=0;
                r1 = dp[i-1][j];
                r2 = dp[i][j-1];

                dp[i][j]=max(l, max(r1, r2));
            }
        }

        // int lcs_len = dp[n1][n2];
        // int scs_len = n1+n2-lcs_len;
        // cout<<scs_len<<endl;
        // for(int i=0;i<=n1;i++){
        //     for(int j=0;j<=n2;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        string ans = "";

        int i = n1, j = n2;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){ //UP
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=s1[i-1];
            i--;
        }
        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};