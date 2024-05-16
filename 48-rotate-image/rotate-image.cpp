class Solution {
public:

    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);

        int s_col=0, e_col=matrix[0].size()-1;
        while(s_col<e_col){
            for(int i=0;i<matrix.size();i++){
                swap(matrix[i][s_col],matrix[i][e_col]);
            }
            s_col++;
            e_col--;
        }
    }
};