//https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
*/

class Solution
{
    public:
    int helper(int n, int &x, int &y, int &z,vector<int> &dp ){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int a,b,c;
        a=b=c=INT_MIN;
       if(n-x>=0) a=helper(n-x,x,y,z,dp);
       if(n-y>=0) b=helper(n-y,x,y,z,dp);
       if(n-z>=0) c=helper(n-z,x,y,z,dp);
        int res=1+max({a,b,c});
        return dp[n]=res;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        return helper(n,x,y,z,dp)<0?0:helper(n,x,y,z);
    }
};