#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(3);
    s.insert(1);
    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.count(5); // Check 5 is present or not
    cout<<endl;
    cout<<s.count(-7)<<endl;
    set<int>::iterator itr = s.find(5); // ?????
    return 0;
}