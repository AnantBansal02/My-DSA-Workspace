#include<bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, int arr[], int seg[]){
    if(low==high){
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*idx + 1, low, mid, arr, seg);
    build(2*idx + 2, mid+1, high, arr, seg);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}
int query(int idx, int low, int high, int l, int r, int seg[]){
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
    int left = query(2*idx+1, low, mid, l, r, seg);
    int right = query(2*idx+2, mid+1, high, l ,r, seg);

    return min(left,right);
}
void update(int idx, int low, int high, int index, int val, int seg[]){
    if(low == high){
        seg[idx] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if(index<=mid){
        update(2*idx+1, low, mid, index, val, seg);
    }
    else{
        update(2*idx+2, mid+1, high, index, val, seg);
    }
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}
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
    int seg[4*n];
    build(0,0,n-1,arr,seg);
    // for(int i=0;i<4*n;i++)
    //     cout<<seg[i]<<" ";
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r,seg)<<"\n";
        }
        else{
            int i,val;
            cin>>i>>val;
            update(0,0,n-1,i,val,seg);
            arr[i] = val;
        }
    }
    return 0;
}