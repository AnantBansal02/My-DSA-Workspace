// https://www.spoj.com/problems/LCASQ/
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<vector<int>> up;
vector<int> depth;
int LOG;

int dfs(int node){
    if(depth[node] != -1){
        return depth[node];
    }
    return depth[node] = 1 + dfs(parent[node]);
}
void pre(){
    int n = parent.size();
    while((1<<LOG)<=n){
        LOG++;
    }
    up = vector<vector<int>> (n,vector<int>(LOG));
    for(int i=0;i<n;i++){
        up[i][0] = parent[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int solve(int a, int b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    int k = depth[a] - depth[b];
    for(int j=LOG-1;j>=0;j--){
        if((1<<j) & k){
            a = up[a][j];
        }
    }
    if(a==b){
        return a;
    }
    for(int j=LOG-1;j>=0;j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main(){
    int n;cin>>n;
    parent.resize(n,0);
    depth.resize(n,-1);
    for(int i=0;i<n;i++){
        int m;cin>>m;
        while(m--){
            int node;cin>>node;
            parent[node] = i;
        }
    }
    depth[0] = 0;
    for(int i=0;i<n;i++){
        dfs(i);
    }
    pre();
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
}