#include<bits/stdc++.h>
using namespace std;

int firstocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}
int lastocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i-1,key);
}

int main(){
    int arr[] = {4,2,1,2,5,2,7};
    cout<<firstocc(arr,7,0,2);cout<<" ";
    cout<<lastocc(arr,7,6,2);
    return 0;
}