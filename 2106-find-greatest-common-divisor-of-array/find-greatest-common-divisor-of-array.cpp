class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];

        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                max = nums[i];
            if(nums[i]<min)
                min = nums[i];
        }

        while(max!=0 && min!=0){
            if(max>min)
                max = max - min;
            else
                min = min - max;
        }
        if(max)
            return max;
        return min;
    }
};