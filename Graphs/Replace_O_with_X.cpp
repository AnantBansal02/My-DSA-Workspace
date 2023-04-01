#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void dfs1(vector<vector<char>> &ans, int n, int m, vector<vector<char>> mat, int row, int col, int drow[], int dcol[]){
        ans[row][col] = 'O';
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and mat[nrow][ncol]=='O'){
                if(ans[nrow][ncol]!='O'){
                    dfs1(ans,n,m,mat,nrow,ncol,drow,dcol);
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans(n,vector<char>(m,'A'));
        int drow[] = {0,1,-1,0};
        int dcol[] = {-1,0,0,1};
        for(int i=0;i<m;i++){
            if(ans[0][i]=='A' and mat[0][i]=='O'){
                dfs1(ans,n,m,mat,0,i,drow,dcol);
            }
            if(ans[n-1][i] == 'A' and mat[n-1][i]=='O'){
                dfs1(ans,n,m,mat,n-1,i,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i][0]=='A' and mat[i][0]=='O'){
                dfs1(ans,n,m,mat,i,0,drow,dcol);
            }
            if(ans[i][m-1] == 'A' and mat[i][m-1]=='O'){
                dfs1(ans,n,m,mat,i,m-1,drow,dcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]!='O'){
                    ans[i][j] = 'X';
                }
            }
        }
        return ans;
    }
};