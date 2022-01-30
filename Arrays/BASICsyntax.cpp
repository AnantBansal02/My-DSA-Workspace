#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int array[4]={10,20,30,40};
    // cout<<array[3]<<endl;
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n ; i++)
    {
        cin>>array[i];
    }
    // cout<<"Which value of array do you want??";
    // int a;
    // cin>>a;
    // cout<<array[a-1];
    for (int i = 0; i < n ; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}