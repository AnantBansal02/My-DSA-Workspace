#include<bits/stdc++.h>
using namespace std;
set<int> lazy;
int bitCount(int a){
    int count = 0;
    while(a>0){
        count += a&1;
        a = a >> 1;
    }   
    return count;
}
int dp[100001][102];
int ani(int i, vector<int> &A, int last){
    if(i>=A.size()){
        int x = lazy.size();
        lazy.insert(last);
        return lazy.size() - x;
    }
    if(dp[i][last]!=-1){
        return 0;
    }
    int a = 0;
    // taking the element
    if(last != 101 and A[i] > last and bitCount(A[i]) >= bitCount(last)){
        a += ani(i+1,A,A[i]^last);
    }
    if(last==101){
        a += ani(i+1,A,A[i]);
    }
    // not taking
    int b = ani(i+1,A,last);
    return dp[i][last] = (a+b);
}
int solve(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    return ani(0,A,101);
}

int main(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(9);
    cout<<solve(arr)<<"\n";
}