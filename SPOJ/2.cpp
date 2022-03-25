#include<bits/stdc++.h>
using namespace std;

bool checkprime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int lowLIMIT[n];
    int upLIMIT[n];
    for(int i=0;i<n;i++){
        cin>>lowLIMIT[i];
        cin>>upLIMIT[i];
    }

    for(int i=0;i<n;i++){
        for(int j=lowLIMIT[i];j<=upLIMIT[i];j++){
            if(checkprime(j)){
                cout<<j<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}
