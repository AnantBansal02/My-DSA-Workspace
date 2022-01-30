#include<iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    float sum=0;
     cin>>n;
    int a=n;
    while(n>0)
    {
        int i=n%10; 
        sum+=pow(i,3);
        n/=10;
    }
    //  cout<<sum<<endl;
    //  cout<<a;
    if(a==sum){cout<<"Armstrong Number";}
    else{cout<<"Not an Armstrong Number";}
    return 0;
}