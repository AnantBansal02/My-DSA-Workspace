#include<bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012


// int count(int n,vector<int> &heights, vector<int> &dp){
//     if(n==1){
//         return 0;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int right = INT_MAX;
//     int left = count(n-1,heights,dp) + abs(heights[n-1]-heights[n-2]);
//     if(n>2)
//         right = count(n-2,heights,dp) + abs(heights[n-1]-heights[n-3]);
//     dp[n] = min(left,right);
//     return dp[n];
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}