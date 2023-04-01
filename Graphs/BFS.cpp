#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // This line is not required in case of directed graph from u-->v
    }
    int vis[n+1] = {0};
    queue<int> q;
    vector<int> ans;
    q.push(1);vis[1] = 1;
    while(!q.empty()){
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for(auto it : adj[x]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}