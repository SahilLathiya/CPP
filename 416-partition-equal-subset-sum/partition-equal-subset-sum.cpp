class Solution {
public:
    bool solve(vector<int> &arr, int ind, int k, vector<vector<int>> &dp){
        if(k==0)
            return true;
        if(ind<0 || k<0)
            return false;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
            
        //Not take
        bool l = solve(arr, ind-1, k, dp);
        
        //take
        bool r = solve(arr, ind-1, k-arr[ind], dp);
        return dp[ind][k] = (l || r);
    }
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.
        // vector<vector<int>> dp(n, vector<int> (k+1, -1));
        // return solve(arr, n-1, k, dp);

        // vector<vector<int>> dp(n, vector<int> (k+1, 0));


        // for(int i=0;i<n;i++)
        //     dp[i][0] = true;

        vector<bool> prev(k+1, 0), temp(k+1, 0);
        temp[0] = true;
        prev[0] = true;
        if(arr[0]<=k)
            prev[arr[0]] = true;

        for(int i=1;i<n;i++){
            for(int t=1;t<=k;t++){
                //Not take
                bool l = prev[t];
            
                //take
                bool r = false;
                if(t-arr[i]>=0)
                    r = prev[t-arr[i]];
                temp[t] = (l || r);
            }
            prev = temp;
        }

        return prev[k];
    }
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2)
            return false;

        return subsetSumToK(n, sum/2, arr);
    }
};