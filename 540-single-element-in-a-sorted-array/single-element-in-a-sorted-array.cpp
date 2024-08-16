class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0, h = n - 1;
        while(l<h){
            int mid = (h-l)/2 + l;
            
            if(mid%2==0){
                if(mid+1<n && arr[mid]==arr[mid+1])
                    l = mid+1;
                else if(mid-1>=0 && arr[mid]==arr[mid-1])
                    h = mid;
                else
                    return arr[mid];
            }
            else{
                if(mid-1>=0 && arr[mid]==arr[mid-1])
                    l = mid+1;
                else if(mid+1<n && arr[mid]==arr[mid+1])
                    h = mid;
                else
                    return arr[mid];
            }
        }
        return arr[l];
    }
};