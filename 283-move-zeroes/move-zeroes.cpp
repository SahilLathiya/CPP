class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int ind = 0, n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[ind]);
                ind++;
            }
            // cout<<"IND: "<<ind<<' ';
            // for(auto a:arr)
            //     cout<<a<<' ';
            // cout<<endl;
        }
    }
};