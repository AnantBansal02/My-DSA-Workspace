//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if(ul_u == ul_v){
            return;
        }
        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        int n = details.size();
        DSU ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string it = details[i][j];
                if(mp.find(it) == mp.end()){
                    mp[it] = i;
                }
                else{
                    ds.unionBySize(i,mp[it]);
                }
            }
        }
        vector<string> adj[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            adj[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(adj[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(details[i][0]);
            sort(adj[i].begin(), adj[i].end());
            for(auto it : adj[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends