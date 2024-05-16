class Solution {
public:
    int countPrimes(int n) {

        if(n<=2)
            return 0;
        if(n==3)
            return 1;
        bool arr[n];
        for(int i=0;i<n;i++)
            arr[i] = true;
        arr[2] = false;
        arr[3] = false;
        int cnt = 2;
        for(int i = 4;i<n;i++){
            if(i%3==0 || i%2==0)
                arr[i] = false;
            else if(arr[i]){
                cnt++;
                // cout<<i<<' ';
                for(int j=i+i;j<n;j = j + i)
                    arr[j] = false;
            }       
        }
        return cnt;
    }
};