class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
                cnt++;
        }
        if(cnt==0)
            return true;
        if(cnt==1){
            if(nums[0]>=nums[nums.size()-1])
                return true;
        }
        return false;
    }
};