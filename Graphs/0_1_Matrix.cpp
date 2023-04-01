#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    void solve(vector<vector<int>> &ans, vector<vector<int>> grid,int n,int m){
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int x = q.front().second;
            q.pop();
            int nrow;
            int ncol;
            for(int i=0;i<4;i++){
                ncol = col + dcol[i];
                nrow = row + drow[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    if(ans[nrow][ncol]==0 and grid[nrow][ncol]==0){
                        ans[nrow][ncol] = x + 1;
                        q.push({{nrow,ncol},x+1});
                    }
                }
            }
        }
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    solve(ans,grid,n,m);
	    return ans;
	}
};