class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = -1;
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        for(int i = 1 ; i < n ; i++)
            if(prefix[i-1] > nums[i])
                ans = prefix[i];

        return ans;
    }
};