class Solution {
public:
    int findPivote(vector<int>& nums){
        int low = 0, high = nums.size()-1;
        int mid = low + (high - low)/2;
        while(low<high){
            if(nums[mid]>nums[high]){
                low = mid+1;
            }else{
                high = mid;
            }
            mid = low + (high - low)/2;
        }
        return low;
    }
    int binarySearch(vector<int>& nums, int low, int high, int target){
        int mid = low + (high - low)/2;
        while(low<=high){
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid - 1;
            mid = low + (high - low)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivote(nums);
        if(nums[pivot]<=target && target<=nums[nums.size()-1])
            return binarySearch(nums,pivot,nums.size()-1,target);
        else
            return binarySearch(nums,0,pivot-1,target);
    }
};