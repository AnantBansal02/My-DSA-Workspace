#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, vector<int> &ans){
        vis[node] = 1;
        path[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, path, ans)){
                    ans[node] = 0;
                    return true;
                }
            }
            else if(path[it]){
                ans[node] = 0;
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> ans(V,1);
        vector<int> path(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path,ans);
            }
        }
        vector<int> tor;
        for(int i=0;i<V;i++){
            if(ans[i]){
                tor.push_back(i);
            }
        }
        return tor;
    }
};
int main(){
	return 0;
}