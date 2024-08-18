class Solution {
public:
    int solve(vector<int>& arr, int ind, int sum, vector<vector<int>> &dp){
        if(ind==0){
            if(sum==0 && arr[0]==0)
                return 2;
            if(sum==0 || sum==arr[0])
                return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        //take
        int l = 0;
        if(sum>=arr[ind])
        l = solve(arr, ind-1, sum-arr[ind], dp);
        
        //not take
        int r = solve(arr, ind-1, sum, dp);
        
        return dp[ind][sum] = (l+r)%(int(1e9)+7);
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        long long int t_sum =0;
        for(int i=0;i<n;i++)
            t_sum+=arr[i];
        if(t_sum<d || (t_sum-d)%2)
            return 0;
        int s2 = (t_sum-d)/2;
        // vector<vector<int>> dp(n, vector<int> (s2+1, -1));
        // return solve(arr, n-1, s2, dp);
        
        vector<vector<int>> dp(n, vector<int> (s2+1, 0));
        if(arr[0]==0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        
        if(arr[0]!=0 && arr[0]<=s2)
            dp[0][arr[0]] = 1;
        
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=s2;sum++){
                
                int l = 0;
                if(sum>=arr[ind])
                    l = dp[ind-1][sum - arr[ind]];
                
                //not take
                int r = dp[ind-1][sum];
                dp[ind][sum] = (l+r)%(int(1e9)+7);
            }
        }
        return dp[n-1][s2];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};