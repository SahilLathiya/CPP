class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int prev = 0;
        int i = 0;
        while(true){
            prev = arr[i];
            if(prev==-1)
                return i;
            arr[i] = -1;
            i = prev;
        }
        return -1;
    }
};