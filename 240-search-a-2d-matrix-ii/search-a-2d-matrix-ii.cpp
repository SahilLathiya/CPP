class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s_row = 0, e_col = matrix[0].size() -1 ;

        while(s_row <matrix.size() && e_col>=0){
            int ele = matrix[s_row][e_col];
            if (ele==target)
                return true;
            else if(ele<target)
                s_row++;
            else
                e_col--;
        }
        return false;
    }
};