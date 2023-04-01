#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/


class Solution {
public:
    int count(int n, vector<int> &nums,vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left = nums[n] + count(n-2,nums,dp);
        int right = count(n-1,nums,dp);
        dp[n] = max(left,right);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return count(n-1,nums,dp);
    }
};