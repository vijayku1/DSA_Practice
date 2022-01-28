//https://leetcode.com/problems/maximal-square/
/* 
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
*/

class Solution {
public:
int helper(int i,int j,vector<vector<char>> &mat,vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size() || mat[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min({helper(i+1,j,mat,dp),helper(i+1,j+1,mat,dp),helper(i,j+1,mat,dp)});
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int mx=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    mx=max(mx,helper(i,j,matrix,dp));
                }
            }
        }
        return mx*mx;
    }
};