class Solution {
public:
    void solve(vector<int>& arr, int ind, int n, vector<int> &temp, vector<vector<int>> &ans){
        if(ind>=n){
            ans.push_back(temp);
            return;
        }
        
        // Take
        temp.push_back(arr[ind]);
        solve(arr, ind+1, n, temp, ans);
        temp.pop_back();

        //Not take
        solve(arr, ind+1, n, temp, ans);

    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr, 0, arr.size(), temp, ans);
        return ans;
    }
};