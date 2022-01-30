#include<iostream>
using namespace std;

int factorial(int num)
{
    int ans=1;
    for(int i=1;i<=num;i++)
    {
        ans=ans*i;
    }
    return ans;
}
int main()
{
    int n,r;
    cin>>n>>r;
    int a=(factorial(n))/(factorial(r)*factorial(n-r));
    cout<<a<<endl;
    return 0;
}