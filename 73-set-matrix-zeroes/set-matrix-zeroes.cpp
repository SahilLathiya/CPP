class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> loc;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    loc.push_back({i,j});
                }
            }
        }
        for(int k=0;k<loc.size();k++){
            int x = loc[k][0];
            int y = loc[k][1];
            for(int i=0;i<matrix[0].size();i++)
                matrix[x][i] = 0;

            for(int j=0;j<matrix.size();j++)
                matrix[j][y] = 0;
        }
    }
};