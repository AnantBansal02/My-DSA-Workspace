#include<bits/stdc++.h>
using namespace std;

int getbit(int n , int pos)
{
    return ((n &(1<<pos))!=0);
    // what this function is doing is extracting the specific bit of a given int for us
}
int main()
{
    int n,pos;
    cin>>n>>pos;
    cout<<getbit(n,pos)<<endl;
    return 0;
}