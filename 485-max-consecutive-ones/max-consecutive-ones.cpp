class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size();
        if(n==0)
            return 0;
        
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                cnt++;
            }else{
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};