class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int k){

        //check row contain number k
        for(int i=0;i<9;i++){
            if(board[row][i]=='0'+k)
                return false;
        }

        
        //check col contain number k
        for(int i=0;i<9;i++){
            if(board[i][col]=='0'+k)
                return false;
        }

        //check 3x3 box contain k
        int box_row = row/3;
        int box_col = col/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[box_row*3 + i][box_col*3 + j]=='0'+k)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row, int col){
        if(row==9)
            return true;
        if(col==9)
            return solve(board, row+1, 0);
        
        // If the cell is already filled, move to the next cell
        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }
        
        for(int k=1;k<=9;k++){
            if(isValid(board, row, col, k)){
                board[row][col] = '0'+k;
                if(solve(board, row, col+1))
                    return true;
                else{
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        cout<<solve(board, 0, 0);
    }
};