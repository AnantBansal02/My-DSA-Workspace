#include<iostream>
using namespace std;
#define int long long
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalan(i)*catalan(n-i-1);
    }
    return ans;
}
int numTrees(int n) {
        n++;
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                dp[i] += dp[i-j-1]*dp[j];
            }
        }
        return dp[n-1];
    }
signed main(){
    for(int i =0;i<=22;i++){
        cout<<numTrees(i)<<" ";
    }
    cout<<endl;
    for(int i =0;i<=22;i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}