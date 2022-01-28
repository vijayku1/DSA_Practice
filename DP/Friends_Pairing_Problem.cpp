//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
*/

class Solution
{
public:
int mod=1e9+7;
long long  helper(int n,vector<long long int> &dp){
    if(n==0 || n==1||n==2)return n;
    if(dp[n]!=-1)return dp[n];
    return  dp[n]=((helper(n-1,dp)%mod)+((n-1)*helper(n-2,dp))%mod)%mod;
}
    int countFriendsPairings(int n) 
    { 
        vector<long long int> dp(n+1,-1);
        return helper(n,dp);
    }
};