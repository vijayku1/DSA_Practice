/* https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


*/
class Solution {
public:
    bool valid_check(int row,int col,int val,vector<vector<char>> &board){
        
        for(int i=0;i<9;i++){
             if(board[i][col]==val)
                return false;
            if(board[row][i]==val)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
                return false;
        }
        return true;
    }
    bool helper(vector<vector<char>> &board){
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    
                   for(char val='1';val<='9';val++){
                        if(valid_check(i,j,val,board)){
                            board[i][j]=val;
                            if(helper(board))return true;
                            else board[i][j]='.';
                        }
                   }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};