#include<iostream>
#include<deque>
#include<list>
using namespace std;
int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(1);
    l.push_back(1);
    l.push_front(2);
    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());
    cout<<"After Erase"<<endl;
    for(int i : l){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<l.size()<<" ";
    return 0;
}