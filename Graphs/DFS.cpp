#include<iostream>
#include<vector>
using namespace std;
void dfs(int x, int vis[], vector<int> &ans, vector<int> adj[]){
    vis[x] = 1;
    ans.push_back(x);
    for(auto i : adj[x]){
        if(vis[i]==0){
            dfs(i,vis,ans,adj);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // This line is not required in case of directed graph from u-->v
    }
    int vis[n] = {0};
    int x = 0;
    vector<int> ans;
    dfs(x,vis,ans,adj);
}