#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter initial Money you have"<<endl;
    cin>>n;
    int chocolates = n;
    int wrappers = 0;
    int ans = 0; 
    while((chocolates + wrappers)>= 3)
    {
        wrappers = wrappers%3;
        ans += chocolates ;
        wrappers = chocolates + wrappers;
        chocolates = wrappers/3;
    }
    cout<<ans<<endl;
    return 0;
}
