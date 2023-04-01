#include<iostream>
#include<vector>
using namespace std;
void dfs(int x,int vis[],vector<int> adj[]){
    vis[x] = 1;
    for(auto i : adj[x]){
        if(vis[i]==0){
            dfs(i,vis,adj);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n+1] = {0};
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,vis,adj);
            ans++;
        }
    }
    cout<<ans<<endl;
}