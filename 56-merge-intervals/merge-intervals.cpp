class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int i=0;
        while(i<n){
            vector<int> temp = arr[i];
            i++;
            while(i<n && arr[i][0] <= temp[1]){
                    temp[1] = max(temp[1], arr[i][1]);
                    i++;
                }
            ans.push_back(temp);
            }
        return ans;
        
    }
};