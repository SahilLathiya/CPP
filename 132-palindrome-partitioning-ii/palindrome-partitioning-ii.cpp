class Solution {
public:
    bool isPalindrom(string & s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string & s, int i, int n, vector<int> & dp){
        if(i==n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int mini = 1e9;
        for(int j=i;j<n;j++){
            int sub_ans = 0;
            if(isPalindrom(s,i,j)){
                sub_ans = 1 + solve(s, j+1, n, dp);
                mini = min(mini, sub_ans);
                // cout<<"HI";
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        // vector<int> dp(n, -1);
        // return solve(s, 0, n, dp)-1;

        vector<int> dp(n+1, 0);
        for(int i=n-1;i>=0;i--){
            int mini = 1e9;
            for(int j=i;j<n;j++){
                int sub_ans = 0;
                if(isPalindrom(s,i,j)){
                    sub_ans = 1 + dp[j+1];
                    mini = min(mini, sub_ans);
                    // cout<<"HI";
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
};