class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        int mid = low + (high - low)/2;
        while(low<high){
            if(arr[mid]>arr[high])
                low = mid + 1;
            else
                high = mid;
            mid = low + (high - low)/2;
        }
        return arr[low];
    }
};