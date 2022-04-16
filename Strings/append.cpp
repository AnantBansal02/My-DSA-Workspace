#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "Fam" , s2 = "ily";
    string s3 = s1 + s2;
    cout<<s3<<endl;
    s1.append(s2);
    cout<<s1;
    return 0;
}