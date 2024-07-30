class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int m = matrix.size();
        for(int i=0; i<m; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
    void swapCol(vector<vector<int>>& matrix){
        int m = matrix.size();
        for(int i=0;i<m/2;i++){
            for(int j=0;j<m;j++){
                swap(matrix[j][i], matrix[j][m-1-i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        swapCol(matrix);
    }
};