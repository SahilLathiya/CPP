class Solution {
public:
    void subset(vector<int> &arr, int ind, int n, vector<int> &temp, set<vector<int>> &ans){
        if(ind>=n){
            // sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        
        //take
        temp.push_back(arr[ind]);
        subset(arr, ind+1, n, temp, ans);
        temp.pop_back();
        //not take
        subset(arr, ind+1, n, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        subset(nums, 0, nums.size(), temp, ans);
        set<vector<int>> t;
        cout<<ans.size();
        for(auto a:ans){
            sort(a.begin(),a.end());
            t.insert(a);
        }
        cout<<t.size();
        vector<vector<int>> ans2;
        for(auto a:t){
            ans2.push_back(a);
        }
        return ans2;
    }
};