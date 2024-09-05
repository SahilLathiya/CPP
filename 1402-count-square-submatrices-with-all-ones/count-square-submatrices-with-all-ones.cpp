class Solution {
public:

    int countSquares(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            dp[i][0] = arr[i][0];
        }
        for(int i=0;i<n;i++){
            dp[0][i] = arr[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][j]==1){
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
                
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];    
            }
        }
        return ans;
    }
};