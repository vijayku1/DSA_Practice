/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/ 

class Solution {
public:
   int dp[1001][1001];
int solve(vector<int>nums,int target,int sum,int n)
{
    if(n==0)
    {
        if(sum==target || sum==-target) return 1;
        else return 0;  
    }
    if(dp[n][abs(sum)]!=-1)  return dp[n][abs(sum)];
    return dp[n][abs(sum)]=solve(nums,target,sum+nums[n-1],n-1)+solve(nums,target,sum-nums[n-1],n-1);   
}
int findTargetSumWays(vector<int>& nums, int target) 
{
    memset(dp,-1,sizeof(dp));
    int ans=solve(nums,target,0,nums.size());
    return target==0 ? ans : ans/2;
    
}
};