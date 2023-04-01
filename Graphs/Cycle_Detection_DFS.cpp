#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(int node, vector<int> &vis, vector<int> adj[], int prevNode, bool &check,vector<int> &mainvis){
        if(vis[node]==1){
            check = false;
            return;
        }
        mainvis[node]=1;
        vis[node] = 1;
        for(auto it : adj[node]){
            if(it!=prevNode){
                dfs(it,vis,adj,node,check,mainvis);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> mainvis(V,0);
        for(int i=0;i<V;i++){
            vector<int> vis(V,0);
            bool check = true;
            if(mainvis[i]==0){
                dfs(i,vis,adj,-1,check,mainvis);
            }
            if(!check){
                return true;
            }
        }
        return false;
    }
};