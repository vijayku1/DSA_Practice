//https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so
 that not more than two consecutive fences have the same colors. Since the answer can be large
  return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6
*/


class Solution{
    public:
    int mod=1e9+7;
    long long int  helper(int n,int k,vector<int> &dp){
        if(n==0 )return 0;
        if(n==1)return k;
        if(n==2)return k*(k-1)+k;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=((helper(n-1,k,dp)*(k-1))%mod+(helper(n-2,k,dp)*(k-1))%mod)%mod;
    }
    long long countWays(int n, int k){
        vector<int> dp(n+1,-1);
        return helper(n,k,dp);
    }
};