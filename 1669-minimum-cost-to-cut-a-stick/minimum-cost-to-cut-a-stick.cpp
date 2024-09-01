class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>> &dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int mini = INT_MAX;

        for(int k=i;k<=j;k++){
            int curr_cost = arr[j+1] - arr[i-1];
            // cout<<curr_cost<<endl;
            int l = solve(arr, i, k-1, dp);
            int r = solve(arr, k+1, j, dp);
            int total = curr_cost + l + r;
            mini = min(mini, total);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        arr.insert(arr.begin(), 0);
        arr.push_back(n);
        vector<vector<int>> dp(size+2, vector<int>(size+2, -1));
        int ans = solve(arr, 1, size, dp);

        return ans;
    }
};