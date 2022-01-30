#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int key)
{
    int s=0;
    int e=n;
    while(s<=n)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key){return mid;}
        else if(arr[mid]>key){e = mid -1;}
        else if(arr[mid]<key){s = mid +1;}
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Input the key to be searched"<<endl;
    int key;
    cin>>key;
    cout<<binarysearch(arr,n,key)+1<<endl;
    return 0;
}