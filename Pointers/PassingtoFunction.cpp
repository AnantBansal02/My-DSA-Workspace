#include<bits/stdc++.h>
using namespace std;

// Classical example of call by value 
// Copy variable is passed into the function
// changing the copy variable doesnt change the original
/*
void increment(int a)
{
    a++;
}

int main()
{
    int a = 2;
    increment(a);
    cout<<a<<endl;
    return 0;
}
*/

// Classiscal example of call by reference
// Pointer is passed to the function 
// Updating the pointer updates the original variable

void increment(int *a)
{
    *a += 1;
}

int main()
{
    int a = 2;
    int *p = &a;
    increment(p); // instead of p we can also write &a which will send address of a.
    cout<<a<<endl;
    return 0;
}