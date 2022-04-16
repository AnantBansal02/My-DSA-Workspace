#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10,20,30};
    // cout<<arr<<endl;
    int *ptr=arr;  // Notice how we didnt use &arr as arrays already behaves as pointers!!!!
    for(int i=0;i<3;i++)
    {
        cout<<*ptr<<endl;
        ptr++;
    }
    // As we know now array behaves as pointers :
    for(int i=0;i<3;i++)
    {
        cout<<*(arr+i)<<endl; // So we will be doing this instead.
        // +i kyun +4i kyun nhi because arr is indexing pointer jumps to next index not next memory location
        //arr++; // This is illegal as arr is a constant pointer!
    }

}