//  https://leetcode.com/problems/interleaving-string/
/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b. 

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

*/
class Solution {
public:
    bool helper(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true;
        bool res=false;
        if(i!=s1.length() && s1[i]==s3[k]) res|=helper(s1,s2,s3,i+1,j,k+1,dp);  
        if(j!=s2.length() && s2[j]==s3[k]) res|=helper(s1,s2,s3,i,j+1,k+1,dp);
        return dp[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,s3,0,0,0,dp);
    }
};
