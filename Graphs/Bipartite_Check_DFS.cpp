#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int prevNode,bool &check){
        if(prevNode!=-1){
            if(vis[prevNode]==0){
                if(vis[node]==-1){
                    vis[node]=1;
                    for(auto it:adj[node]){
                        dfs(it,vis,adj,node,check);
                    }
                }
                else if(vis[node]==0){
                    check = false;
                }
            }
            else if(vis[prevNode]==1){
                if(vis[node]==-1){
                    vis[node]=0;
                    for(auto it:adj[node]){
                        dfs(it,vis,adj,node,check);
                    }
                }
                else if(vis[node]==1){
                    check = false;
                }
            }
        }
        else{
            vis[node] = 0;
            for(auto it:adj[node]){
                dfs(it,vis,adj,node,check);
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            bool check = true;
	            dfs(i,vis,adj,-1,check);
	            if(!check){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};