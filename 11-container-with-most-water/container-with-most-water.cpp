class Solution {
public:
    int maxArea(vector<int>& arr) {
        int l = 0, h = arr.size()-1;
        int ans = 0;
        while(l<h){
            ans = max(ans, (h-l)*min(arr[l], arr[h]));
            if(arr[l]<=arr[h])
                l++;
            else
                h--;
        }
        return ans;
    }
};