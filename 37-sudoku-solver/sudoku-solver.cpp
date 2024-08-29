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
    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){

                    for(int k=1;k<=9;k++){
                        if(isValid(board, i, j, k)){
                            board[i][j] = '0'+k;
                            if(solve(board))
                                return true;
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;

                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        cout<<solve(board);
    }
};