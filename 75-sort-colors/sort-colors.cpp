class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;

        while(mid<high){
            while(mid<high && nums[low]==0){
                low++;
                mid++;
            }
            while(mid<high && nums[mid]==1){
                mid++;
            }
            while(high>=mid && nums[high]==2){
                high--;
            }
            if(nums[mid]==0)
                swap(nums[mid],nums[low]);
            else if(high>=mid)
                swap(nums[mid],nums[high]);
           
        }
    }
};