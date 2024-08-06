class Solution {
public:
    int trap(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int l = 0, r = n-1;
        int lmx = INT_MIN;
        int rmx = INT_MIN;
        while(l<=r){
            lmx = max(lmx, arr[l]);
            rmx = max(rmx, arr[r]);
            if(arr[l]<=arr[r]){
                ans += lmx - arr[l];
                l++;
            }
            else{
                ans += rmx - arr[r];
                r--;
            }
        }
        return ans;
    }
};