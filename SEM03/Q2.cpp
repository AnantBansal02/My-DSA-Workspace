#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    cout<<"Enter Number to check if prime or not : ";
    int n;cin>>n;
    if(n<2){
        cout<<"Not Valid as Number is less than 2"<<endl;
        return 0;
    }
    int x = sqrt(n);
    bool check = true;
    for(int i=2;i<x+1;i++){
        if(n%i==0){
            check = false;
            break;
        }
    }
    if(check){
        cout<<"Given Number is Prime"<<endl;
    }
    else{
        cout<<"Given Number is not Prime"<<endl;
    }
    return 0;
}