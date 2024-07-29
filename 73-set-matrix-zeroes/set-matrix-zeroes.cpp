class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int row[m];
        int col[n];
        for (int i = 0; i < m; i++) {
            row[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            col[i] = 0;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    arr[i][j] = 0;
                }
            }
        }
    }
};