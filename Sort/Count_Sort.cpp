#include<iostream>
#include<vector>
using namespace std;
void CountSort(int arr[],int n){
    int x = 0;
    for(int i=0;i<n;i++){
        x = max(x,arr[i]);
    }
    int v[10] = {0};
    for(int i=0;i<n;i++){
        v[arr[i]]++;
    }
    for(int i=0;i<10;i++){
        v[i+1] += v[i]; 
    }
    int *arr2 = new int [n];
    for(int i=n-1;i>=0;i--){
        int index = --(v[arr[i]]);
        arr2[index] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = arr2[i];
    }
}
int main(){
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    CountSort(arr,n);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}