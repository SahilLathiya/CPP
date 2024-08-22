class Solution {
public:
    void solve(vector<int>& arr, int ind, vector<int>& temp, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind<0)
            return;

        //take
        if(target>=arr[ind]){
            temp.push_back(arr[ind]);
            solve(arr, ind, temp, ans, target-arr[ind]);
            temp.pop_back();
        }

        //not take
        solve(arr, ind-1, temp, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();
        solve(arr, n-1, temp, ans, target);
        return ans;
    }
};