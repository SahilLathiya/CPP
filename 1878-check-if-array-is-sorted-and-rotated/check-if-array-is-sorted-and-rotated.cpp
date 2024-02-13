class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
                cnt++;
        }
        cout<<cnt;
        if(cnt>1)
            return false;
        else if(cnt==1 && nums[0]<nums[n-1])
            return false;
        return true;
    }
};