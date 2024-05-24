class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int sum = 0;
        for(int i=1;i<prices.size();i++){
            sum -= prices[i-1];
            sum += prices[i];
            if(sum<0)
                sum = 0;
            ans = max(ans,sum);
        }
        return ans;
    }
};