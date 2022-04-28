#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "346742996801";
    sort(s.begin(), s.end(), greater<int>());
    cout<<s<<endl;
    return 0;
}