#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(i,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};