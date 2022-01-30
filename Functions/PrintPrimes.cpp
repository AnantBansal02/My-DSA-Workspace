#include<iostream>
using namespace std;

bool prime(int num)
{
    for(int i=2;i<num;i++){if(num%i==0){return false;}}
    return true;
}
int main()
{
    int n,a=2;
    cin>>n;
    while(a<=n)
    {
        if(prime(a)){cout<<a<<endl;}
        a=a+1;
    }
    return 0;
}