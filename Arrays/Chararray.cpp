#include<bits/stdc++.h>
using namespace std;

int main()
{

    // PRINTING INPUT ARRAY********

    /* char arr[100] = "Anant Bansal";
    int i=0;
    while(arr[i] != '\0')
    {
        cout<<arr[i];
        i++;
    }

    // CHECK PALINDROME*********

    char a[100];
    cin>>a;
    int i = 0;
    while(a[i] != '\0')
    {
        i++;
    }
    bool check = 1;
    for(int j=0;j<i+1;j++)
    {
        if(a[j] != a[i-1-j]){check = 0;}
    }
    if(check == true){cout<<"Yes";}
    else{cout<<"No";}

    // LARGEST WORD IN A SENTENCE*******/

    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];

    cin.getline(arr, n);
    cin.ignore();

    int i=0;
    int curr=0, Maxlen=0;

    while(1)
    {
        if(arr[i] == ' ' || arr[i] == '\0')
        {
            if(curr>Maxlen)
            {
                Maxlen = curr;
            }
            curr = 0;
        }
        else
        {curr++;}
        if(arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout<<Maxlen<<endl;
    return 0;
}