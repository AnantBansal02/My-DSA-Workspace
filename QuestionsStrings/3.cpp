#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "fhgsrhdsaiaitunb";
    int count[26];
    for(int i=0;i<26;i++)
    {
        count[i] = 0;
    }
    for(int i = 0;i<s.length();i++)
    {
        count[s[i]-'a']++;
    }
    char ans = 'a';
    int maxF = 0;
    for(int i=0;i<26;i++)
    {
        if(count[i]>=maxF) //understand this greater than or equal to !!
        {
            maxF = count[i];
            ans = i+'a';
        }
    }
    cout<<maxF<<" "<<ans<<endl;
    return 0;
}