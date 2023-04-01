#include<bits./stdc++.h>
using namespace std;
class Solution {
public:
    void floodfill(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m){
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int ocol = image[sr][sc];
        image[sr][sc] = newColor;
        if(ocol == newColor){
            return;
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row+1>=0 and row+1<n){
                if(image[row+1][col]==ocol){
                    image[row+1][col]=newColor;
                    q.push(make_pair(row+1,col));
                }
            }
            if(row-1>=0 and row-1<n){
                if(image[row-1][col]==ocol){
                    image[row-1][col]=newColor;
                    q.push(make_pair(row-1,col));
                }
            }
            if(col+1>=0 and col+1<m){
                if(image[row][col+1]==ocol){
                    image[row][col+1]=newColor;
                    q.push(make_pair(row,col+1));
                }
            }
            if(col-1>=0 and col-1<m){
                if(image[row][col-1]==ocol){
                    image[row][col-1]=newColor;
                    q.push(make_pair(row,col-1));
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        floodfill(image,sr,sc,newColor,n,m);
        return image;
    }
};