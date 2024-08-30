class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1>n2)
            return findMedianSortedArrays(arr2, arr1);

        double ans = 0;
        int mid1=-1, mid2=-1;

        int n_ele_left = (n1+n2+1)/2;
        int l = 0, h = n1;
        while(l<=h){
            mid1 = (h-l)/2+l;
            mid2 = n_ele_left - mid1;
            
            int l1=-1e9, l2=-1e9 ,r1=1e9 ,r2=1e9;

            if(mid1>0)
                l1 = arr1[mid1-1];
            
            if(mid2>0)
                l2 = arr2[mid2-1];
        
            if(mid1<n1)
                r1 = arr1[mid1];

            if(mid2<n2)
                r2 = arr2[mid2];

            if(l1<=r2 && l2<=r1)
                if((n1+n2)%2==0)
                    return (max(l1,l2) + min(r1,r2))/2.0;
                else
                    return max(l1,l2);

            else if(l1>r2)
                h = mid1 - 1;

            else
                l = mid1 + 1;
        }
        return ans;
    }
};