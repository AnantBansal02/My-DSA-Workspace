#include<iostream>
using namespace std;

int mazecount(int n,int i,int j){
    if(i == n-1 && j == n-1){
        return 1;
    }
    if(i>=n || j>= n){
        return 0;
    }
    return (mazecount(n,i+1,j) + mazecount(n,i,j+1));
}
int main(){
    cout<<mazecount(3,0,0);
    return 0;
}