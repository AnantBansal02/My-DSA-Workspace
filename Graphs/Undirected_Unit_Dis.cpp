#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis(N,INT_MAX);
        dis[src] = 0;
        queue<pair<int,int>> q;
        q.push({0,src});
        while(!q.empty()){
            auto it = q.front();
            int node = it.second;
            int currDis = it.first;
            q.pop();
            for(auto adjNode : adj[node]){
                if(currDis + 1 < dis[adjNode]){
                    dis[adjNode] = currDis + 1;
                    q.push({dis[adjNode], adjNode});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i] == INT_MAX){
                dis[i] = -1;
            }
        }
        return dis;
    }
};
int main(){
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4 ,5},{5, 6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    Solution sol;
    vector<int> ans = sol.shortestPath(edges,9,10,0);
    for(auto it : ans){
        cout<<it<<" ";
    }
}