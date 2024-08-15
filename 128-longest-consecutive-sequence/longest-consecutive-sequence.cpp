class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        // cout<<map[2];
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int count=0;
                while(map.count(nums[i]+count) > 0){
                    count++;
                }
                if(count>maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};