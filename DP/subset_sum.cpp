//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
/*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
*/

class Solution{
public:
bool helper(int N,int arr[],int sum){
    if(sum==0)return true;
    if(N==0 && sum!=0)return false;
   // if(dp[N][sum]!=-1)return dp[N][sum];
    if(arr[N-1]<=sum){
       return helper(N-1,arr,sum-arr[N-1])||helper(N-1,arr,sum);
        
    }
    else{
        return helper(N-1,arr,sum); 
    }
   
}
    int equalPartition(int N, int arr[])
    {
        int sum=0;
       
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
         vector<vector<int>> dp(N+1,vector<int>(sum+1,false));
        return helper(N,arr,sum/2);
        
    }
};