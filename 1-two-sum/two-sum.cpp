class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};