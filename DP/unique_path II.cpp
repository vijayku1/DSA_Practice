// https://leetcode.com/problems/unique-paths-ii/
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right


class Solution {
public:
    int dp[102][102];
    int countpaths(vector<vector<int>>& obstacleGrid,int i,int j)
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(i>=m || j>=n) return 0;
     
        if(obstacleGrid[i][j]==1) return 0;
       
        if(i==m-1 && j==n-1 ) return 1;
        if(dp[i][j]!=-1)  return dp[i][j];
       
        return dp[i][j]=countpaths(obstacleGrid,i+1,j)+countpaths(obstacleGrid,i,j+1);  
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       memset(dp,-1,sizeof(dp));
        return countpaths(obstacleGrid,0,0);
    }
};