#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> rank, parent,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if(ul_u == ul_v){
            return;
        }
        if(rank[ul_u] < rank[ul_v]){
            parent[ul_u] = ul_v;
        }
        else if(rank[ul_v] < rank[ul_u]){
            parent[ul_v] = ul_u;
        }
        else{
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if(ul_u == ul_v){
            return;
        }
        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};

int main(){
    DSU ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    ds.unionBySize(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<"\n";
    }
    else{
        cout<<"Not Same"<<"\n";
    }
    return 0;
}