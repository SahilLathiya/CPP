class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int leftMax[n], rightMax[n];
        int lmx = INT_MIN, rmx = INT_MIN;
        int ans = 0;

        for(int i=0;i<n;i++){
            lmx = max(lmx,arr[i]);
            leftMax[i] = lmx;
            rmx = max(rmx, arr[n-1-i]);
            rightMax[n-1-i] = rmx;
        }
        for(int i=0;i<n;i++)
            ans += min(leftMax[i],rightMax[i]) - arr[i];
            
        return ans;
    }
};