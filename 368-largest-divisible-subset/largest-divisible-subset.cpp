class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        // Code here
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i=0;i<n;i++)
            hash[i] = i;
        
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int prev = 0; prev<i;prev++){
                if(arr[i]%arr[prev]==0){
                    if(dp[i]<dp[prev]+1){
                        hash[i] = prev;
                        dp[i] = 1+dp[prev];
                    }
                }
                maxi = max(maxi, dp[i]);
            }
        }
        
        int start = -1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            // cout<<dp[i]<<' ';
            if(dp[i]==maxi){
                start = i;
                break;
            }
        }
        // cout<<endl<<maxi<<' '<<start<<endl;
        ans.push_back(arr[start]);
        int lastAdded = start;
        start = hash[start];
        while(start!=lastAdded){
            ans.push_back(arr[start]);
            lastAdded = start;
            start = hash[start];
        }
        // cout<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};