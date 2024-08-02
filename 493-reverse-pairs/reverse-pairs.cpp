class Solution {
public:
    void merge(vector<int>& arr, int l, int m, int h, int* ans){
        int n1 = m-l+1;
        int n2 = h-m;
        int arr1[n1];
        int arr2[n2];
        int i=0,j=0,k=l;

        for(int i=0;i<n1;i++)
            arr1[i] = arr[l+i];
        for(int i=0;i<n2;i++)
            arr2[i] = arr[m+1+i];

        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                arr[k] = arr1[i];
                i++;
                k++;
            }
            else{
                arr[k] = arr2[j];
                // if(arr1[i] > 2*arr2[j])
                //     *ans += (n1-i);
                j++;
                k++;
            }
        }
        while(i<n1){
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    void countPairs(vector<int>& arr, int l, int m, int h, int* ans){
        int right = m+1;
        for(int i=l; i<=m; i++){
            while(right<=h && (long long int)arr[i]>(long long int)2*arr[right])
                right++;
            *ans += (right - (m+1));
        }
    }
    void mergeSort(vector<int>& arr, int l, int h, int* ans){
        if(l>=h)
            return;
        int m = (h-l)/2+l;
        mergeSort(arr,l,m,ans);
        mergeSort(arr,m+1,h,ans);
        countPairs(arr, l,m,h,ans);
        merge(arr,l,m,h,ans);
    }
    int reversePairs(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        mergeSort(arr, 0, n-1, &ans);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' ';
        return ans;
    }
};