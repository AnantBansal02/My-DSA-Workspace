#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "nincompoop";
    s.erase(3,3); // 3rd index se lekar 3 elements erase!
    // s.erase(2,4); 2nd element se lekar 4 elements erase! 
    cout<<s<<endl;
    return 0;
}