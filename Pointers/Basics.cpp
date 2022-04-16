#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int *aptr = &a;
    cout<<*aptr<<endl; //accessing variable value
    cout<<&a<<endl;    //accessing pointer value
    cout<<aptr<<endl;  //accessing pointer value
    *aptr = 20;        //changing variable value by pointer
    cout<<a<<endl;
    return 0;
}