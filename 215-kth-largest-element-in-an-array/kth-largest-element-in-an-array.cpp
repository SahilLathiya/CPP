class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0;i<k;i++){
            pop_heap(nums.begin(), nums.end());
            ans = nums[nums.size()-1];
            nums.pop_back();
        }
        return ans;
    }
};