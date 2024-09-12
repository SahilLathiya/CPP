class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int l = 0, h = arr.size()-1;
        while(l<h){
            int mid = (h-l)/2+l;
            if(mid%2){
                if(mid>0 && arr[mid-1]==arr[mid])
                    l = mid + 1;
                else if(mid<arr.size()-1 && arr[mid+1]==arr[mid])
                    h = mid - 1;
                else
                    return arr[mid];
            }
            else{
                if(mid>0 && arr[mid-1]==arr[mid])
                    h = mid - 2;
                else if(mid<arr.size()-1 && arr[mid+1]==arr[mid])
                    l = mid + 2;
                else
                    return arr[mid];
            }
        }
        return arr[l];
    }
};