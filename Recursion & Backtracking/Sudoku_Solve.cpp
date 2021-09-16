// Problem Link :- https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool isSafe(vector<vector<char>> &board, int r, int c, int num){
        //for row
        for(int i = 0; i < 9; i++){
            if(board[i][c]-'0' == num)
                return false;
        }
        //for col
        for(int i = 0; i < 9; i++){
            if(board[r][i]-'0' == num)
                return false;
        }

        int cr = (r/3)*3, cc = (c/3)*3;
        for(int i = cr; i < cr+3; i++){
            for(int j = cc; j < cc+3; j++){
                if(board[i][j]-'0' == num)
                    return false;
            }
        }
        return true;
    }
    
    bool sudoku(vector<vector<char>> &board, int row, int col){
        if(col == 9){
             return sudoku(board, row+1, 0);
        }
        
        if(row == 9)
            return true;
        
        if(board[row][col] == '.'){
            for(int i = 1; i <= 9; i++){
                if(isSafe(board, row, col, i)){
                    board[row][col] = '0'+i;
                    bool res = sudoku(board, row, col+1);
                    if(res)
                        return true;
                    board[row][col] = '.';
                }
            }
            return false;
        } else
            return sudoku(board, row, col+1);
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool res = sudoku(board, 0, 0);
    }
};