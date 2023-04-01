#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>> &vis){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = row + delrow;
                    if(nrow<0 || nrow>=grid.size()){
                        continue;
                    }
                    int ncol = col + delcol;
                    if(ncol<0 || ncol>=grid[0].size()){
                        continue;
                    }
                    if(grid[nrow][ncol]=='1' and vis[nrow][ncol]==0){
                        q.push(make_pair(nrow,ncol));
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==0){
                    bfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};