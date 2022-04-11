// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }
//     cout<<"Your Input Matrix :"<<endl;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// Searching::::

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int k;
    cout<<"Enter key to be searched : "<<endl;;
    cin>>k;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == k){cout<<i<<" "<<j<<endl;bool flag = true;}
        }
    }
    if(flag){cout<<"Element is Found!!!";}
    else{cout<<"Element is not Found!!!";}
    

    return 0;
}