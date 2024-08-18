class Solution {
public:
    long long int solve(vector<int>& arr, int ind, int sum, vector<vector<int>> &dp){
        if(sum < 0 || ind < 0)
            return INT_MAX;
        if(sum==0)
            return 0;
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        long long int l = 1 + solve(arr, ind, sum-arr[ind], dp);
        long long int r = solve(arr, ind-1, sum, dp);
        return dp[ind][sum] = min(l,r);
    }
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solve(arr, n-1, amount, dp);
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;


        vector<int> temp(amount+1, INT_MAX), prev(amount+1, INT_MAX);
        // for(int i=0;i<n;i++)
        //     dp[i][0] = 0;
        temp[0] = 0;
        
        for(int ind=0;ind<n;ind++){
            for(int sum=1;sum<=amount;sum++){
                long long int l = INT_MAX;
                if(sum>=arr[ind])
                    l = 1 + (long long int)temp[sum-arr[ind]];
                long long int r = INT_MAX;
                if(ind>0)
                    r = prev[sum];
                temp[sum] = min(l,r);
            }
            prev = temp;
        }
        if(prev[amount]==INT_MAX)
            return -1;
        return prev[amount];
    }
};