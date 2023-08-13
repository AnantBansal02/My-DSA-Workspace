#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<int> Tadj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it : Tadj[node]){
            if(!vis[it]){
                dfs(it,Tadj,vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& Adj)
    {
        //code here
        vector<int> adj[V];
        vector<int> Tadj[V];
        for(int i=0;i<V;i++){
            for(auto it : Adj[i]){
                adj[i].push_back(it);
                Tadj[it].push_back(i);
            }
        }
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        vis = vector<int>(V,0);
        int ans = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ans++;
                dfs(node,Tadj,vis);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}