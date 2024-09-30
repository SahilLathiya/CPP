class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0;
        int h = arr.size()-1;
        int l_max = 0;
        int r_max = 0;
        int ans = 0;
        while(l<h){
            l_max = max(l_max, arr[l]);
            r_max = max(r_max, arr[h]);
            if(l_max<=r_max){
                ans += max(0, min(l_max,r_max) - arr[l]);
                l++;
            }
            else{
                ans += max(0, min(l_max,r_max) - arr[h]);
                h--;
            }
        }
        return ans;
    }
};