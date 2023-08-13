#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            auto it = pq.front();
            int stops = it.first;
            int currCost = it.second.first;
            int node = it.second.second;
            pq.pop();
            if(stops > k){
                continue;
            }
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int cost = iter.second;
                if((stops <= k and dis[adjNode] > currCost + cost) || (stops == k and adjNode == dst))
                {
                    dis[adjNode] = min(dis[adjNode], currCost + cost);
                    pq.push({stops+1,{currCost+cost,adjNode}});
                }
            }
        }
        if(dis[dst] == INT_MAX){
            return -1;
        }
        return dis[dst];
    }
};
int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    Solution sol;
    cout<<sol.findCheapestPrice(n,flights,src,dst,k)<<"\n";
}