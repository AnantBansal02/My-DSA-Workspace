#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node{
    int pref, suff, sum, ans;
    Node(){
        pref = 0;
        suff = 0;
        sum = 0;
        ans = 0;
    }
};

class SG{
    public:
    vector<Node> tree;
    SG(int n){
        tree.resize(4*n+1);
    }
    void build(int idx, int low, int high, vector<int> &arr){
        if(low == high){
            if(arr[low] <= 0){
                tree[idx].ans = 0;
                tree[idx].pref = 0;
                tree[idx].suff = 0;
                tree[idx].sum = arr[low];
            }
            else{
                tree[idx].ans = arr[low];
                tree[idx].pref = arr[low];
                tree[idx].suff = arr[low];
                tree[idx].sum = arr[low];
            }
            return;
        }
        int mid = (low + high) >> 1;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        tree[idx].sum = tree[2*idx+1].sum + tree[2*idx+2].sum;
        tree[idx].pref = max(tree[2*idx+1].pref, tree[2*idx+1].sum + tree[2*idx+2].pref);
        tree[idx].suff = max(tree[2*idx+2].suff, tree[2*idx+2].sum + tree[2*idx+1].suff);
        tree[idx].ans = max({tree[2*idx+1].ans, tree[2*idx+2].ans, tree[2*idx+1].suff + tree[2*idx+2].pref});
    }
    void update(int idx, int low, int high, int i, int val, vector<int> &arr){
        if(low == high){
            arr[low] = val;
            if(arr[low] <= 0){
                tree[idx].ans = 0;
                tree[idx].pref = 0;
                tree[idx].suff = 0;
                tree[idx].sum = arr[low];
            }
            else{
                tree[idx].ans = arr[low];
                tree[idx].pref = arr[low];
                tree[idx].suff = arr[low];
                tree[idx].sum = arr[low];
            }
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid){
            update(2*idx+1,low,mid,i,val,arr);
        }
        else{
            update(2*idx+2,mid+1,high,i,val,arr);
        }
        tree[idx].sum = tree[2*idx+1].sum + tree[2*idx+2].sum;
        tree[idx].pref = max(tree[2*idx+1].pref, tree[2*idx+1].sum + tree[2*idx+2].pref);
        tree[idx].suff = max(tree[2*idx+2].suff, tree[2*idx+2].sum + tree[2*idx+1].suff);
        tree[idx].ans = max({tree[2*idx+1].ans, tree[2*idx+2].ans, tree[2*idx+1].suff + tree[2*idx+2].pref});
    }
};

signed main() {
	int n,q;cin>>n>>q;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SG sg(n);
    sg.build(0,0,n-1,arr);
    cout<<sg.tree[0].ans<<"\n";
    while(q--){
        int i, value;
        cin>>i>>value;
        sg.update(0,0,n-1,i,value,arr);
        cout<<sg.tree[0].ans<<"\n";
    }
}