#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int sum=0;
    for(i=1;i<=n;i++){
        sum=sum+i;
    }cout<<"Sum upto ";cout<<n;cout<<" is ";cout<<sum;
    return 0;
}