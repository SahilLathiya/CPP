class Solution {
public:
    void subset(vector<int> &arr, int ind, int n, vector<int> &temp, vector<vector<int>> &ans){

        ans.push_back(temp);

        for(int i=ind;i<n;i++){
            if(i!=ind && arr[i-1]==arr[i])
                continue;
            temp.push_back(arr[i]);
            subset(arr, i+1, n, temp, ans);
            temp.pop_back();
        }

        //not take
        // subset(arr, ind+1, n, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subset(nums, 0, nums.size(), temp, ans);
        
        return ans;
    }
};