#include<iostream>
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinmaze(int** arr, int x,int y,int n,int **SolArr){
    if(x==n-1 && y==n-1){
        SolArr[x][y]=1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        SolArr[x][y]=1;
        if(ratinmaze(arr,x+1,y,n,SolArr)){
            return true;
        }
        if(ratinmaze(arr,x,y+1,n,SolArr)){
            return true;
        }
        SolArr[x][y]=0;
        return false;
    }
    return false;

}
int main(){

    int n;
    cin>>n;
    int** arr = new int*[n]; // Dynamic memory allocation
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int** Solarr = new int*[n]; // Dynamic memory allocation
    for(int i=0;i<n;i++){
        Solarr[i] = new int[n];
        for(int j=0;j<n;j++){
            Solarr[i][j]=0;
        }
    }
    if(ratinmaze(arr,0,0,n,Solarr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<Solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}