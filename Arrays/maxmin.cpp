#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i = 0; i<n ; i++)
    {
        cin>>array[i];
    }
    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for( int i = 0 ; i<n ; i++)
    {
        // if(array[i]>max){max = array[i];}
        // if(array[i]<min){min = array[i];}
        maxNo = max( maxNo , array[i]);
        minNo = min( minNo , array[i]);
        
    }
    cout<<"Max Number in the array = "<<maxNo<<endl;
    cout<<"Min Number in the array = "<<minNo<<endl;
    return 0;
}