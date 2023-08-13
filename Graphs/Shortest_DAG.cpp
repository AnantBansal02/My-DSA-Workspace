#include<bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int n = N;
        int m = M;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> ans(n,INT_MAX);
        queue<pair<int,int> > q;
        ans[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            for(auto it : adj[node]){
                if(dis + it.second < ans[it.first]){
                    ans[it.first] = dis + it.second;
                    q.push({ans[it.first],it.first});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1,2});
    edges.push_back({0,2,1});
    Solution sol;
    vector<int> ans = sol.shortestPath(4,2,edges);
    for(auto it : ans){
        cout<<it<<" ";
    }
}