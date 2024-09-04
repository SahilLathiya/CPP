class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi = INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost = arr[i-1] * arr[ind] * arr[j+1];
            int l = solve(arr, i, ind-1, dp);
            int r = solve(arr, ind+1, j, dp);
            maxi = max(maxi, cost+l+r);
        }
        
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = solve(arr, 1, n, dp);
        // return ans;

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)
                    continue;

                int maxi = -1e9;
                for(int ind=i;ind<=j;ind++){
                    int cost = arr[i-1] * arr[ind] * arr[j+1];
                    int l = dp[i][ind-1];
                    int r = dp[ind+1][j];
                    maxi = max(maxi, cost+l+r);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};