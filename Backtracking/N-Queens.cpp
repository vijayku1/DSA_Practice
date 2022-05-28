/* 
   https://leetcode.com/problems/n-queens/submissions/

   The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate

a queen and an empty space, respectively.

*/

class Solution {
public:
    bool validcheck(int i,int j,vector<string> board,int n){
        int temp_x=i;
        int temp_y=j;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')return false;
            i--;
            j--;
        }
        i=temp_x;
        j=temp_y;
        while(j>=0){
            if(board[i][j]=='Q')return false;
            j--;
        }
        i=temp_x;
        j=temp_y;
        while(i<n && j>=0){
            if(board[i][j]=='Q')return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(vector<vector<string>> &res,vector<string> &board,int j,int n ){
        if(j==n){
            res.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(validcheck(i,j,board,n)){
                 board[i][j]='Q';
                 helper(res,board,j+1,n);
                 board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string st(n,'.');
        for(int i=0;i<n;i++){
            board[i]=st;
        }
        helper(res,board,0,n);
        return res;
    }
};