class Solution {
public:
    int breakPoint(vector<int>& arr){
        int l = 0, h = arr.size()-1;
        while(l<h){
            int mid = (h-l)/2 + l;
            if(arr[mid]>=arr[0])
                l = mid + 1;
            else 
                h = mid;
        }
        return l;
    }

    int bs(vector<int>& arr, int target, int l, int h){
        while(l<=h){
            int mid = (h-l)/2 + l;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]<target)
                l = mid+1;
            else
                h = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int b = breakPoint(arr);

        int x = bs(arr, target, 0, b-1);
        if(x!=-1)
            return x;
        return bs(arr, target, b, arr.size()-1);
    }
};