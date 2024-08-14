class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        unordered_map<int, int> mpp;
        vector<int> ans(2);
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(mpp.find(t-arr[i])!=mpp.end()){
                ans[0] = mpp[t-arr[i]];
                ans[1] = i;
                return ans;
            }
            else
                mpp[arr[i]] = i;
        }
        return ans;
    }
};