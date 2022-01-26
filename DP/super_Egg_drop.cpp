
// https://leetcode.com/problems/super-egg-drop/

/*You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
*/

//Memoization approach:- It will gives the TLE

class Solution {
public:
    int helper(int k, int n, vector<vector<int>>& dp){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];
        
        int mn = INT_MAX;
        
        for(int i=1; i<=n; i++){
            int temp = 1 + max(helper(k-1, i-1, dp), helper(k, n-i, dp)); //FOR WORST CASE
            
            mn = min(mn, temp); //minimum number of attempts
        }
        return dp[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
         return helper(k,n,dp);
    }
//BINAR SEARCH APPROACH:- Efficient solution

class Solution {
public:
    int helper(int k, int n, vector<vector<int>>& dp){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];
        
        int mn = INT_MAX;
        int start=1,end=n;
        while(start<=end){
            int mid=start+(end-start)/2;
            int temp1=helper(k-1,mid-1,dp);
            int temp2=helper(k,n-mid,dp);
            
            if(temp1<=temp2){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
            int temp = 1 + max(temp1,temp2);
            
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
         return helper(k,n,dp);
    }
  
};