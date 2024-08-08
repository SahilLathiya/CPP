class Solution {
public:
    void solve(vector<int>& arr, int ind, int n, vector<int> &temp, vector<vector<int>> &ans, int sum, int target){        
        // cout<<sum<<' ';
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target)
            return;

        for(int i=ind;i<n;i++){
            sum+=arr[i];
            temp.push_back(arr[i]);
            solve(arr, i+1, n, temp, ans, sum, target);
            temp.pop_back();
            sum-=arr[i];
            while(i<n-1 && arr[i]==arr[i+1])
                i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr, 0, arr.size(), temp, ans, 0, target);
        return ans;
    }
};