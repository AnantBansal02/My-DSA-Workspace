#include<bits/stdc++.h>
using namespace std;
#define int long long

// Accepted!!

class SGTree{
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx, int low, int high, int arr[]){
        if(low==high){
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*idx + 1, low, mid, arr);
        build(2*idx + 2, mid+1, high, arr);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx, int low, int high, int l, int r){
        // no overlap 
        // l r low high || low high l r
        if(r<low || high<l){
            return 0;
        }

        // complete overlap
        // l low high r
        if(low>= l and high<=r){
            return seg[idx];
        }
        
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l ,r);

        return left+right;
    }
    void update(int idx, int low, int high, int index, int val){
        if(low == high){
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if(index<=mid){
            update(2*idx+1, low, mid, index, val);
        }
        else{
            update(2*idx+2, mid+1, high, index, val);
        }
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
};
void solve(){
    int n;cin>>n;
    int arr[n];
    int mx = -1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx = max(mx,arr[i]);
    }
    mx++;
    int a[mx] = {0};
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    SGTree sg(mx);
    sg.build(0,0,mx-1,a);
    int ans = 0;
    for(auto i:arr){
        if(a[i]){
            sg.update(0,0,mx-1,i,0);
            ans += sg.query(0,0,mx-1,0,i);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}