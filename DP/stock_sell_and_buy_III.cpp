/* 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

class Solution {
public:
    
    int helper(vector<int> &prices,int i,int transc,vector<vector<int>>& dp){
        if(i==prices.size())return 0; // if the day ends return 0
        if(transc==0){  //if we have no transaction left then will return the 0
            return 0;
        }
        if(dp[i][transc]!=-1)return dp[i][transc];
        
        int res1=helper(prices,i+1,transc,dp);// for no transactions
        int res2=0;
        
        if(transc%2==0){  //we have already buy and now we have to sell first
            res2=helper(prices,i+1,transc-1,dp)-prices[i];
        }
        else{  //else if are going to purchase the stock
            res2=helper(prices,i+1,transc-1,dp)+prices[i];
        }
        return dp[i][transc]=max(res1,res2); // return the maximum profit 
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(5,-1));
        return helper(prices,0,4,dp);
    }
};