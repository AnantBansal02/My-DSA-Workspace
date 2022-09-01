#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=n;i>=2;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
        for(int j=1;j<=n-i+1;j++){
            cout<<" ";
        }
    }
    // cout<<"*"<<endl;
    // for(int i=1;i<=n-1;i++){
    //     cout<<" ";
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
        for(int j=1;j<=n-i-1;j++){
            cout<<" ";
        }
    }
    return 0;
}
