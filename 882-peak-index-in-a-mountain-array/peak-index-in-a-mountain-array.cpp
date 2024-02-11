class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int low = 0, high = arr.size()-1;
        int mid = low + (high - low)/2;

        while(low<=high){
            if((mid==arr.size()-1 || arr[mid]>arr[mid+1]) && (mid==0 || arr[mid]>arr[mid-1]))
                return mid;
            else if(arr[mid]<arr[mid+1])
                low = mid+1;
            else
                high = mid-1;

            mid = low + (high - low)/2;
        }
        return -1;
    }
};