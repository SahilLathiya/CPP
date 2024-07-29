class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, prof = 0;
        for(int i=1;i<prices.size();i++){
            prof += (prices[i] - prices[i-1]);
            ans = max(ans, prof);
            if(prof<0)
                prof = 0;
        }
        return ans;
    }
};