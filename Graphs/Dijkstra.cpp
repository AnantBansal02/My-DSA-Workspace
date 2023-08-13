#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        st.insert({0,S});
        vector<int> ans(V,1e9);
        ans[S] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                if(wt + dis < ans[adjNode]){
                    if(ans[adjNode]!=1e9){
                        st.erase({ans[adjNode],adjNode});
                    }
                    ans[adjNode] = wt + dis;
                    st.insert({ans[adjNode],adjNode});
                }
            }
        }
        return ans;
    }
};
