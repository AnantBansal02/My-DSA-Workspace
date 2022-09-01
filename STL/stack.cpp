#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> s;
    s.push("Anant");
    s.push("Kumar");
    s.push("Bansal");
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}