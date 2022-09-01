#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <string> q;
    q.push("Anant");
    q.push("Kumar");
    q.push("Bansal");
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    return 0;
}