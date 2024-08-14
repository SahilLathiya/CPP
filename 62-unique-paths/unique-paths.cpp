class Solution {
public:
    int solve(int m,int n, vector<vector<int>> &dp){
        if(m<0 || n<0)
            return 0;
        if(m==0 && n==0)
            return 1;

        if(dp[m][n]!=-1)
            return dp[m][n];

        int l = solve(m-1, n, dp);
        int r = solve(m, n-1, dp);
        return dp[m][n] = l+r;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n));
        // for(int i=0;i<m;i++)
        //     for(int j=0;j<n;j++)
        //         dp[i][j] = -1;

        // return solve(m-1, n-1, dp);

        vector<int> temp(n);
        vector<int> prev(n);
        temp[0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)
                    continue;
                int l = 0, r = 0;
                if(i>0) l = prev[j];
                if(j>0) r = temp[j-1];
                temp[j] = l+r;
            }
            prev = temp;
        }
        return prev[n-1];
    }
};