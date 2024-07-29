class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int col0 = arr[0][0];   
        int m = arr.size(), n=arr[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                    if(j==0)
                        col0 = 0;
                    else
                        arr[0][j] = 0;

                    arr[i][0] = 0;
                }
            }
        }

        for(int i = arr.size()-1;i>=0;i--){
            for(int j = arr[0].size()-1;j>=0;j--){
                if(j>0 && (arr[i][0]==0 || arr[0][j]==0))
                    arr[i][j] = 0;
                if(j==0 &&(arr[i][0]==0 || col0==0))
                    arr[i][j] = 0;
            }
        }

    }
};