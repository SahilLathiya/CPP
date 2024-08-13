class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int ptr1 = m-1;
        int ptr2 = n-1;
        int ptr3 = m+n-1;
        while(ptr3>=0){
            if(ptr1>=0 && ptr2>=0 && arr1[ptr1]>=arr2[ptr2]){
                arr1[ptr3] = arr1[ptr1];
                ptr1--;
            }
            else if(ptr1>=0 && ptr2>=0 && arr1[ptr1]<arr2[ptr2]){
                arr1[ptr3] = arr2[ptr2];
                ptr2--;
            }
            else if(ptr1>=0){
                arr1[ptr3] = arr1[ptr1];
                ptr1--;
            }
            else{
                arr1[ptr3] = arr2[ptr2];
                ptr2--;
            }
            ptr3--;
        }
    }
};