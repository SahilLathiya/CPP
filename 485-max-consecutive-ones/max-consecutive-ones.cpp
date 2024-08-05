class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]){
                int last = i;
                while(i<n && arr[i])
                    i++;
                ans = max(ans, i-last);
            }
        }
        return ans;
    }
};