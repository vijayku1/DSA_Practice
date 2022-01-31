//https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

/*Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:

Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.
*/

int helper(string &A,string &B,string &C,int n1,int n2,int n3,vector<vector<vector<int>>> &dp){
   if(n1==0 || n2==0 || n3==0)return 0;
   if(dp[n1][n2][n3]!=-1)return dp[n1][n2][n3];
   if(A[n1-1]==B[n2-1] && B[n2-1]==C[n3-1]){
       return dp[n1][n2][n3]=1+helper(A,B,C,n1-1,n2-1,n3-1,dp);
   }
   else{
       return dp[n1][n2][n3]=max({helper(A,B,C,n1-1,n2,n3,dp),helper(A,B,C,n1,n2-1,n3,dp),helper(A,B,C,n1,n2,n3-1,dp)});
   }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
  vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
  return helper(A,B,C,n1,n2,n3,dp);
}