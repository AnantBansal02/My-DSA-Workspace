#include<bits/stdc++.h>
using namespace std;
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
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }
    int query(int idx, int low, int high, int l, int r){
        // no overlap 
        // l r low high || low high l r
        if(r<low || high<l){
            return INT_MAX;
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

        return min(left,right);
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
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt" , "w", stdout);
    #endif
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SGTree sg(n);
    sg.build(0,0,n-1,arr);
    // for(int i=0;i<4*n;i++)
    //     cout<<seg[i]<<" ";
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<"\n";
        }
        else{
            int i,val;
            cin>>i>>val;
            sg.update(0,0,n-1,i,val);
            arr[i] = val;
        }
    }
    return 0;
}