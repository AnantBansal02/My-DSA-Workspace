#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Program to check if the given number is a power of 2
    // Notice this property in binary numbers which is 
    // if a number is n then n-1 is flipping all the bits to the right 
    // of rightmost one including one.
    // Also n and (n & n-1) has same bits except of the rightmost bit.
    int n;
    cin>>n;
    if((n & n-1) == 0 && n!=0){cout<<"Power of 2"<<endl;}
    else{cout<<"Not a power of 2"<<endl;}
    return 0;
}