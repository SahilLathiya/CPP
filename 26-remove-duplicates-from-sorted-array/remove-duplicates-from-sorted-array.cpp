class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n==0)
            return 0;

        int cnt = 1;
        int i = 1;
        while(i<n){
            if(arr[i-1]==arr[i]){
                i++;
            }
            else{
                arr[cnt] = arr[i];
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};