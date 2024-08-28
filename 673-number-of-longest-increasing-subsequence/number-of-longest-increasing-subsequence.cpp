class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int len_lis = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(arr[i]>arr[j] && dp[j]+1==dp[i])
                    cnt[i] += cnt[j];

            }
            len_lis = max(len_lis, dp[i]);
        }

        int ans = 0;
        for(int i=0;i<n;i++)
            if(dp[i]==len_lis)
                ans += cnt[i];
        return ans;
    }
};