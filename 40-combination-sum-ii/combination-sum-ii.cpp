class Solution {
    private:
    void backtrack(std::vector<int>& candidates, int target, int start, 
                   std::vector<int>& combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        if (target < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            combination.pop_back(); // Backtrack
        }
    }

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
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

};