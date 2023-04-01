#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    void dfs1(vector<vector<int>> &vis, int n, int m, vector<vector<int>> &grid, 
              int row, int col, int drow[], int dcol[])
        {
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1){
                if(vis[nrow][ncol] == 0){
                    dfs1(vis,n,m,grid,nrow,ncol,drow,dcol);
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int drow[] = {0,1,-1,0};
        int dcol[] = {-1,0,0,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1 and vis[i][j]==0){
                        dfs1(vis,n,m,grid,i,j,drow,dcol);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};