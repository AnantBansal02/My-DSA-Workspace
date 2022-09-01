#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m;
    m[1] = "babbar";
    m[2] = "Love";
    m[13] = "Kumar";
    m[1] = "Anant"; // one key can point to only one value so it updates;
    cout<<"Before Erase"<<endl;
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl; // Observe printed keys are in order 

    cout<<"Finding 13 --> "<<m.count(13)<<endl;
    cout<<"Finding -13 --> "<<m.count(-13)<<endl;
    cout<<"After Erase"<<endl;
    m.erase(2);
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}