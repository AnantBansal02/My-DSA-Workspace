#include<bits/stdc++.h>
using namespace std;

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
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    void update(int idx, int low, int high, int l, int r, int val){
        // update the previous while traversing
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
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
            st[idx] += (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    int query(int idx, int low, int high, int l, int r){
        // if updates remaining!!! lazy!!
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(low>=l and r>=high){
            return st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        int mid = (low + high) >> 1;
        return (query(2*idx+1,low,mid,l,r) + query(2*idx+2, mid+1, high, l, r));
    }
};
int main(){
    int n;cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    STLazy ani(n);
    ani.build(0,0,n-1,arr);
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r;cin>>l>>r;
            cout<<ani.query(0,0,n-1,l,r)<<"\n";
        }
        else{
            int l,r,val;cin>>l>>r>>val;
            ani.update(0,0,n-1,l,r,val);
        }
    }
    return 0;
}