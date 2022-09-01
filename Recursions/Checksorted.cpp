#include<bits/stdc++.h>
using namespace std;

bool check(int arr[],int n){
    if(n==1){
        return true;
    }
    int restarray = check(arr+1,n-1);
    return (arr[0]<arr[1] && restarray);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(check(arr,n)){
        cout<<"Sorted"<<endl;
    }
    else{cout<<"Not Sorted";}
    return 0;
}