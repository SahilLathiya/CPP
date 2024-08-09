class Solution {
public:
    void solve(vector<int>& arr, int ind, int n, vector<vector<int>> &ans){

        if(ind>=n){
            ans.push_back(arr);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(arr[ind],arr[i]);
            solve(arr, ind+1, n, ans);
            swap(arr[ind],arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        solve(arr, 0, n, ans);
        return ans;
    }
};
