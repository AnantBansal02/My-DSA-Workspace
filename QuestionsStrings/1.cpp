#include<bits/stdc++.h>
using namespace std;

int main()
{
    // uppercase OR lowercase
    // convert to upper case
    
    string s;
    s = "AfnwefnfNFjJbiBubK";
    for(int i=0;i<s.length();i++)
    {
        if( s[i]>='a' && s[i]<='z')
        {s[i] -= 32;} 
    }
    cout<<s<<endl;
    

    for(int i=0;i<s.length();i++)
    {
        if( s[i]>='A' && s[i]<='Z')
        {s[i] += 32;} 
    }
    cout<<s<<endl;
    return 0;
}