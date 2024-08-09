class Solution {
public:
    void solve(vector<int>& arr, int n, int mpp[], vector<int> &temp, vector<vector<int>> &ans){

        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(mpp[i])
                continue;
            mpp[i] = 1;
            temp.push_back(arr[i]);
            solve(arr, n, mpp, temp, ans);
            mpp[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        int mpp[n];
        for(int i=0;i<n;i++)
            mpp[i] = 0;
        vector<int> temp;
        solve(arr, n, mpp, temp, ans);
        return ans;
    }
};