class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        int n = nums.size();
        for(int i=0;i<n;i++){
            minH.push(nums[i]);
            k--;
            if(k<0){
                minH.pop();
                k++;
            }
        }
        return minH.top();
    }
};