class Solution {
public:
    int rob1(vector<int>& arr, int n) {
        if(n==0)
            return arr[0];

        int prev1 = arr[0];
        int prev2 = 0;
        int prev = 0;
        for(int i=1;i<n;i++){
            prev = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = prev;
        }
        return prev1;
    }
    int rob(vector<int>& arr) {
        int n = arr.size();

        // 0...n-2
        int a = rob1(arr, n-1);

        // 1...n-1
        arr.erase(arr.begin());

        int b = rob1(arr, n-1);
        return max(a,b);
    }
};