class Solution {
public:
    int breakPoint(vector<int>& arr){
        int n = arr.size();
        int l = 0, h = n-1;
        while(l<h){
            int mid = (h-l)/2 + l;
            if(arr[mid]>=arr[0]){
                l = mid + 1;
            }
            else{
                h = mid;
            }
        }
        return l;
    }
    int binarySearch(vector<int>& arr, int l, int h, int t){
        while(l<=h){
            int mid = (h-l)/2 + l;
            if(arr[mid]==t)
                return mid;
            else if(arr[mid]>t)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& arr, int t) {
        int b = breakPoint(arr);
        cout<<b;
        int x = binarySearch(arr, 0, b-1, t);
        if(x!=-1)
            return x;
        return binarySearch(arr, b, arr.size()-1, t);
    }
};