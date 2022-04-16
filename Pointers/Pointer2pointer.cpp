#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int *p;
    p = &a;
    cout<<*p<<endl;
    int **q = &p; // Notice how we used double star!
    // Initialising a p2p using ** is important cant use *p even if we only
    // intend to use *q value!!!
    cout<<*q<<endl; // Khali ek baar dereference so p value will be printed
    cout<<**q<<endl; // 2 baar dereference so a value will be printed
    return 0;
}