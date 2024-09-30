class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            int lastDig = x%10;
            if(ans*(long long)10 + lastDig >INT_MAX || ans*(long long)10 + lastDig<INT_MIN)
                return 0;
            ans = ans*10 + lastDig;
            x/=10;
        }
        return ans;
    }
};