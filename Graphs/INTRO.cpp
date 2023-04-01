#include<iostream>
#include<vector>
using namespace std;

int main(){
    // Storing graph using Adjacency Matrix
    /*
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    */
    // Storing graph using Adjacency List
    // More Efficient!
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // This line is not required in case of directed graph from u-->v
    }
}