#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    getline(cin, a); // Input bhi ho chuki h string!!
    cout<<a<<endl;
    string b(5, 'n');
    cout<<b;
    
    return 0;
}