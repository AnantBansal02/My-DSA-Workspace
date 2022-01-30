#include<iostream>
#include <math.h>
using namespace std;

int main(){
int n,i;
cin>>n;
for(i=2;i<n;i++){
  if(n%i==0){
      cout<<n;cout<<" is not a prime number";
  exit(0);}

}cout<<n;cout<<" is a prime number";
    return 0;
}