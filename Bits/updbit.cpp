#include<bits/stdc++.h>
using namespace std;

int updatebit(int n , int pos, int value)
{
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
}
int main()
{
    int n,pos,val;
    cin>>n>>pos>>val;
    cout<<updatebit(n,pos,val)<<endl;
    return 0;
}