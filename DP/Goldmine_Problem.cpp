//https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1/
/*
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive
 integer which is the amount of gold in tons. Initially the miner can start from any row in 
 the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.

Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}.
*/
class Solution{
public:
int helper(int i,int j,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &M){
    if(i<0 || j<0 || j>=m || i>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int res1=M[i][j]+helper(i-1,j+1,n,m,dp,M);
    int res2=M[i][j]+helper(i,j+1,n,m,dp,M);
    int res3=M[i][j]+helper(i+1,j+1,n,m,dp,M);
    dp[i][j]=max({res1,res2,res3});
    return dp[i][j];
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,helper(i,0,n,m,dp,M));
        }
        return mx;
    }
};