class Solution {
public:
    void solve(vector<int>& arr, int ind, int n, vector<int>& temp, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(temp);
        }
        if(target<0)
            return;
        for(int i=ind;i<n;i++){
            if(i!=ind && arr[i-1]==arr[i])
                continue;
            temp.push_back(arr[i]);
            solve(arr, i+1, n, temp, ans, target-arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        solve(arr, 0, arr.size(), temp, ans, target);
        return ans;
    }
};