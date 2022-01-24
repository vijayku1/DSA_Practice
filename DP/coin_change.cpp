class Solution {
  public:
   
    
    long long int solve(int S[], int m, int n,vector<vector<long long int>>& dp){
        // base condition
        if(m==-1 && n>0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        //memoized step
        if(dp[m][n] != -1) return dp[m][n];
        // calculation step
        if(S[m]<=n){
            return dp[m][n]= solve(S,m,n-S[m],dp) + solve(S,m-1,n,dp);
        }
        return dp[m][n]=solve(S,m-1,n,dp);
        
    }
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        
        // solve
        return solve(S,m-1,n,dp);// m-1 indexing
        
    }
};