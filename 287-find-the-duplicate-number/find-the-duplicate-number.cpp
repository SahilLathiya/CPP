class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ind=0, tmp, cnt=0;
        int n =nums.size();
        while(cnt<=n){
            tmp = ind;
            ind = nums[ind];
            if(nums[tmp]==-1)
                return tmp;
            nums[tmp] = -1;
            cnt++;
        }
        return -1;
    }
};