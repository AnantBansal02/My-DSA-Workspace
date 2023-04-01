#include<iostream>
#include<vector>
using namespace std;


int find(int n, vector<int> &arr){
    if(n<=1){
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    return arr[n] = find(n-1,arr) + find(n-2,arr);
}
int main(){
    vector<int> arr(100,-1);
    for(int i=0;i<20;i++)
        cout<<find(i,arr)<<endl;
}