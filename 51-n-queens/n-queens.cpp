class Solution {
public:
    bool isValid(vector<string> &board, int row, int col, int n){

        //left-up
        int i = row, j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }

        //left-straight
        i = row;
        j = col;
        while(j>=0){
            if(board[i][j]=='Q')
                return false;
            j--;
        }

        //left-down
        i = row;
        j = col;
        while(i<n && j>=0){
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isValid(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, col+1, n, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
            board[i] = s;
        
        solve(board, 0, n, ans);
        return ans;
    }
};