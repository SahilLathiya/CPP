class Solution {
public:
    int solve(vector<int> &arr, int ind, int lastEle, vector<vector<int>> &dp){
        if(ind<0)
            return 0;
        if(dp[ind][lastEle]!=-1)
            return dp[ind][lastEle];

        //take
        int l = 0;
        if(arr[ind]<lastEle)
            l = 1 + solve(arr, ind-1, arr[ind], dp);
        //not take
        int r = solve(arr, ind-1, lastEle, dp);

        return dp[ind][lastEle] = max(l, r);
    }
    int lengthOfLIS(vector<int>& arr) {
        int mini = INT_MAX;
        int n = arr.size();
        for(int i=0;i<n;i++)
            mini = min(mini, arr[i]);
        
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            arr[i] -= mini;
            // cout<<arr[i]<<' ';
            maxi = max(maxi, arr[i]);
        }
        // cout<<endl<<maxi;

        vector<vector<int>> dp(n, vector<int>(maxi+2, -1));
        return solve(arr, n-1, maxi+1, dp);
    }
};