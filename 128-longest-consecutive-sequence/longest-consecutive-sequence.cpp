class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]] = 1;
        }

        int len = 1;
        int ans = 0;
        int prev = INT_MIN;
        for(auto i:mpp){
            if(i.first == prev+1){
                len++;
                ans = max(len,ans);
            }else{
                len = 1;
                ans = max(len,ans);
            }
            prev = i.first;
        }
        
        return ans;
    }
};