class Solution {
public:
    bool solve(vector<int>& arr, int ind, int sum, vector<vector<int>> &dp){
        if(sum==0)
            return true;
        if(ind<0 || sum<0)
            return false;
            
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        // cout<<ind<<' '<<sum<<endl;
        //take
        bool l = false;
        l = solve(arr, ind-1, sum-arr[ind], dp);
        //not take
        bool r = solve(arr, ind-1, sum, dp);
        return dp[ind][sum] = l|r;
        // return l|r;
    }
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2)
            return false;
        vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));
        return solve(arr, n-1, sum/2, dp);
    }
};