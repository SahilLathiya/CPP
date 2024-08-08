class Solution {
public:
    void subset(vector<int> &arr, int ind, int n, vector<int> &temp, vector<vector<int>> &ans, int sum, int target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(ind>=n || sum>target)
            return;

        subset(arr, ind+1, n, temp, ans, sum, target);
        int cnt = 0;
        while(sum<=target){
            cnt++;
            sum+=arr[ind];
            temp.push_back(arr[ind]);
            subset(arr, ind+1, n, temp, ans, sum, target);
            // temp.pop_back();
        }
        while(cnt--){
            temp.pop_back();
        }
        

        // subset(arr, ind+1, n, temp, ans, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subset(arr, 0, arr.size(), temp, ans, 0, target);
        
        return ans;
    }
};