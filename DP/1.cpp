#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int count(int n, vector<int> &dp){
        if(n==0){
            return 1;
        }
        else if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = (count(n-1,dp) + count(n-2,dp));
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
    }
};