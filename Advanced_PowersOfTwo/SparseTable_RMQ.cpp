// https://www.spoj.com/problems/RMQSQ/

#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<vector<int>> m;
int LOG;
int logarithm[N];

int solve(int l, int r){
    int size = r - l + 1;
    int k = logarithm[size];
    return min(m[l][k], m[r-(1<<k)+1][k]);
}
int main(){
    int n;cin>>n;
    int q;cin>>q;
    LOG = 0;
    while((1<<LOG) <= n){
        LOG++;
    }
    m = vector<vector<int>>(n, vector<int>(LOG,INT_MAX));
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[i][0] = arr[i];
    } 
    logarithm[1] = 0;
    for(int i=2;i<=n;i++){
        logarithm[i] = logarithm[i/2]+1;
    }
    for(int k=1;k<LOG;k++){
        for(int i=0;i+(1<<k)-1<n;i++){
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        // for cses
        l--;r--;
        cout<<solve(l,r)<<"\n";
    }
}