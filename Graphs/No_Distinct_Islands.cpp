#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, 
  int baser, int basec, vector<pair<int,int>> &temp)
  {
      int delrow[] = {0,0,-1,1};
      int delcol[] = {-1,1,0,0};
      vis[row][col] = 1;
      temp.push_back({row-baser,col-basec});
      for(int i=0;i<4;i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1){
              dfs(nrow,ncol,vis,grid,n,m,baser,basec,temp);
          }
      }
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,vis,grid,n,m,i,j,temp);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};