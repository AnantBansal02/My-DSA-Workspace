#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int n, int m,int olcol){
        int row = sr;
        int col = sc;
        image[sr][sc] = newColor;
        if(row+1>=0 and row+1<n){
                if(image[row+1][col]==olcol){
                    image[row+1][col]=newColor;
                    dfs(image,row+1,col,newColor,n,m,olcol);
                }
            }
            if(row-1>=0 and row-1<n){
                if(image[row-1][col]==olcol){
                    image[row-1][col]=newColor;
                    dfs(image,row-1,col,newColor,n,m,olcol);
                }
            }
            if(col+1>=0 and col+1<m){
                if(image[row][col+1]==olcol){
                    image[row][col+1]=newColor;
                    dfs(image,row,col+1,newColor,n,m,olcol);
                }
            }
            if(col-1>=0 and col-1<m){
                if(image[row][col-1]==olcol){
                    image[row][col-1]=newColor;
                    dfs(image,row,col-1,newColor,n,m,olcol);
                }
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == newColor){
            return image;
        }
        dfs(image,sr,sc,newColor,n,m,image[sr][sc]);
        return image;
    }
};