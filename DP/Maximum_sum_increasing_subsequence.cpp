//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/

	int maxSumIS(int arr[], int n)  
	{  
	   
	   int dp[n+1];
	   int res=arr[0];
	   dp[0]=arr[0];
	   if(n==1)return res;
	   for(int i=1;i<n;i++){
	       int mx=0;
	       for(int j=0;j<i;j++){
	           if(arr[j]<arr[i]){
	                 mx=max(dp[j],mx);
	           }
	       }
	        
	       dp[i]=mx+arr[i];
	       res=max(dp[i],res);
	   }
	   return res;
	}  