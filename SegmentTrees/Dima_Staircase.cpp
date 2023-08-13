#include<bits/stdc++.h>
using namespace std;
#define int long long

class STLazy{
    vector<int> st,lazy;
    public:
    STLazy(int n){
        st.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    public:
    void build(int idx, int low, int high, int arr[]){
        if(low==high){
            st[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }
    public:
    void update(int idx, int low, int high, int l, int r, int val){
        if(lazy[idx]!=0){
            st[idx] = lazy[idx];
            if(low!=high){
                lazy[2*idx+1] = lazy[idx];
                lazy[2*idx+2] = lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // low high l r || l r low high
        if(l>high || low>r){
            return;
        }
        // complete overlap
        // l low high r
        if(low>=l and r>=high){
            st[idx] = val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        st[idx] = max(st[2*idx+1], st[2*idx+2]);
    }
    public:
    int query(int idx, int low, int high, int l, int r){
        if(lazy[idx]!=0){
            st[idx] = lazy[idx];
            if(low!=high){
                lazy[2*idx+1] = lazy[idx];
                lazy[2*idx+2] = lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        if(l>high || low>r){
            return INT_MIN;
        }
        // complete overlap
        // l low high r
        if(low>=l and r>=high){
            return st[idx];
        }
        int mid = (low + high) >> 1;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return max(left,right);
    }
};
signed main(){
    int n;cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    STLazy ani(n);
    ani.build(0,0,n-1,arr);
    int q;cin>>q;
    while(q--){
        int w,h;cin>>w>>h;
        w--;
        int ans = ani.query(0,0,n-1,0,w);
        cout<<ans<<"\n";
        ani.update(0,0,n-1,0,w,ans+h);
    }
    return 0;
}