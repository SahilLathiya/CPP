class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low_row = 0, high_row = matrix.size()-1;

        while(low_row <= high_row){
            int mid = low_row + (high_row - low_row)/2;
            if(matrix[mid][0]==target)
                return true;
            else if(matrix[mid][0] < target)
                low_row = mid + 1;
            else
                high_row = mid - 1;
        }
        cout<<low_row<<' '<<high_row;


        int low_col=0, high_col=matrix[0].size() - 1; 
        while(low_col <= high_col && high_row>=0){
            int mid = low_col + (high_col - low_col)/2;
            if(matrix[high_row][mid]==target)
                return true;
            else if(matrix[high_row][mid] < target)
                low_col = mid + 1;
            else
                high_col = mid - 1;
        }
        return false;
    }
};