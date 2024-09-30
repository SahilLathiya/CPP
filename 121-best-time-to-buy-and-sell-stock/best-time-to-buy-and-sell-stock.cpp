class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int ans = 0;
        int temp = 0;
        for(int i=1;i<arr.size();i++){
            temp += arr[i] - arr[i-1];
            if(temp<0)
                temp = 0;
            ans = max(ans, temp);
        }
        return ans;
    }
};