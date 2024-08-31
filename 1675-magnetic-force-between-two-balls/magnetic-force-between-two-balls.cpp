class Solution {
public:
    bool isPossible(vector<int>& arr, int m, int dist){
        int lastCowPos = arr[0];
        int n_cows = 1;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if((arr[i] - lastCowPos)>=dist){
                n_cows++;
                lastCowPos = arr[i];
            }
        }
        return (n_cows>=m);
    }
    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n-1] - arr[0];

        int low = 1;
        int high = ans;
        int mid;
        while(low<=high){
            mid = (high-low)/2 + low;
            if(isPossible(arr, m, mid)){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};