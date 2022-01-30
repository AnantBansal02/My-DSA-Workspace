#include<iostream>
using namespace std;

int main()
{
    int i=1;
    // i++ likha hai toh 1 value preserve rahegi lekin agli bar use karne ke liye i=2 lenge ++i likha 
    // hai toh value preserve nahi karenge aur 2 se value 3 ho jayegi! lekin agli bar 2 hi use hogi!!!
    // so 1+3=4 !!!!
    i= i++ + ++i;
    cout<<i<<endl;
    return 0;
}