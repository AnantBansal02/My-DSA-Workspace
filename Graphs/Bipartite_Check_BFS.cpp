#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(int node, vector<int> &vis, vector<int> adj[]){
        queue<int> q;
        vis[node] = 0;
        q.push(node);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:adj[x]){
                if(vis[x]==0){
                    if(vis[it]==-1){
                       vis[it] = 1;
                       q.push(it);
                    }
                    else if(vis[it]==0){
                        return false;
                    }
                }
                else if(vis[x]==1){
                    if(vis[it]==-1){
                        vis[it] = 0;
                        q.push(it);
                    }
                    else if(vis[it]==1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(!bfs(i,vis,adj)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};