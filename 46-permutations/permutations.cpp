class Solution {
public:

    void solve(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index>=nums.size()){
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            if(index==nums.size()-1)
                ans.push_back(nums);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};