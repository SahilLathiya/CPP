class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int prev = arr[0];
        int n = arr.size();
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i]==prev)
                continue;
            // swap(arr[cnt], arr[i]);
            arr[cnt] = arr[i];
            prev = arr[i];
            cnt++;
        }
        return cnt;
    }
};