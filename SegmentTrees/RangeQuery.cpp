#include<bits/stdc++.h>
using namespace std;
class STLazy{
    vector<unsigned int> st,lazy;
    public:
    STLazy(unsigned int n){
        st.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    void update(unsigned int idx, unsigned int low, unsigned int high, unsigned int l, unsigned int r, unsigned int val){
        // update the previous while traversing
        if(lazy[idx] != 0){
            st[idx] = lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
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
        unsigned int mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        if(st[2*idx+1]==1 and st[2*idx+2]==1){
            st[idx] = 1;
        }
        else{
            st[idx] = 0;
        }
    }
    bool query(unsigned int idx, unsigned int low, unsigned int high, unsigned int l, unsigned int r){
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
            if(st[idx]==1) return true;
            else return false;
        }
        if(l>high || low>r){
            return true;
        }
        unsigned int mid = (low + high) >> 1;
        return (query(2*idx+1,low,mid,l,r) and query(2*idx+2, mid+1, high, l, r));
    }
};