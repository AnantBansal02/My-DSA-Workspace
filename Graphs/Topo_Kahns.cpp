#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    // code here
    vector<int> adjRev[V];
    vector<int> ind(V,0);
    
    // Topo sort Kahns algo!!! :
    vector<int> ans;
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            // Reversing the graph
            adjRev[it].push_back(i);
            ind[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(!ind[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto it : adjRev[curr]){
            ind[it]--;
            if(!ind[it]){
                q.push(it);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}