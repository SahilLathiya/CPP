class Solution {
public:
    void solve(vector<int>& arr, int ind, int n, vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i!=ind && arr[i-1]==arr[i])
                continue;

            temp.push_back(arr[i]);
            solve(arr, i+1, n, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        solve(arr, 0, n, temp, ans);

        return ans;
    }
};