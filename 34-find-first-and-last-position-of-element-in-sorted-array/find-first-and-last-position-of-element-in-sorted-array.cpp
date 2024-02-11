class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int t) {
        vector<int> ans;
        int low = 0, high = arr.size()-1;
        int mid = low + (high-low)/2;
        
        //First Ele
        int first_ind = INT_MAX;
        while(low<=high){
            if(arr[mid]<t){
                low = mid+1;
            }
            else if( arr[mid]>t){
                high = mid - 1;
            }
            else{
                high = mid-1;
                first_ind = min(first_ind,mid);
            }
            mid = low + (high-low)/2;
        }

        low = 0, high = arr.size()-1;
        mid = low + (high-low)/2;
        //Last Ele
        int last_ind = INT_MIN;
        while(low<=high){
            if(arr[mid]<t){
                low = mid+1;
            }
            else if( arr[mid]>t){
                high = mid - 1;
            }
            else{
                low = mid+1;
                last_ind = max(last_ind,mid);
            }
            mid = low + (high-low)/2;
        }

        if(last_ind==INT_MIN){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(first_ind);
            ans.push_back(last_ind);
        }

        return ans;
    }
};