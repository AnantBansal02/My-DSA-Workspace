#include<bits/stdc++.h>
using namespace std;

int linearsearch(int array[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(array[i]==key){return i;}
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i =0 ; i<n; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter key to be searched"<<endl;
    int key;
    cin>>key;
    cout<<linearsearch(array,n,key)+1<<endl;
    return 0;
}