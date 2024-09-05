class Solution {
public:
    int find_max(vector<int>& arr, int i, int j){
        int ans = -1;
        while(i<=j){
            ans = max(arr[i], ans);
            i++;
        }
        return ans;
    }
    int solve(vector<int>& arr, int i, int n, int k, vector<int> & dp){
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int maxi = -1e9;
        for(int j=i; j<n; j++){
            if(j-i+1<=k){
                int max_e = find_max(arr,i,j);
                maxi = max(maxi, max_e*(j-i+1) + solve(arr, j+1, n, k, dp));
            }
        }
        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, n, k, dp);
    }
};