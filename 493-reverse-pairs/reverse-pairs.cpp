class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) j++;
            count += j - (mid + 1);
        }
        
        vector<int> sorted(right - left + 1);
        int k = 0, p1 = left, p2 = mid + 1;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) sorted[k++] = nums[p2++];
            else if (p2 > right) sorted[k++] = nums[p1++];
            else sorted[k++] = (nums[p1] <= nums[p2]) ? nums[p1++] : nums[p2++];
        }
        
        for (int i = 0; i < sorted.size(); i++) {
            nums[left + i] = sorted[i];
        }
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
