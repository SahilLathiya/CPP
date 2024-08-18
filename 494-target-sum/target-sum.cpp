class Solution {
public:
    int solve(vector<int> &arr, int ind, int target){
        if(ind==0){
            if(arr[0]==0 && target==0)
                return 2;
            if(target==arr[0] || target==-arr[0])
                return 1;
            return 0;
        }
        //take as it is
        int l = solve(arr, ind-1, target-arr[ind]);

        // take negative
        int r = solve(arr, ind-1, target+arr[ind]);
        return l+r;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        
        return solve(arr, arr.size()-1, target);
    }
};