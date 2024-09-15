class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        // Write your code here
        int ans = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int n = a.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(prefix.find(sum-k)!=prefix.end()){
                ans+=prefix[sum-k];
            }

            prefix[sum] += 1;
        }

        return ans;
    }
};