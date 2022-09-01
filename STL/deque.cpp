#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(1);
    d.push_back(1);
    d.push_front(5);
    d.push_front(4);
    cout<<"Before Erase"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<endl;
    }
    cout<<"Front= "<<d.front()<<" Back= "<<d.back()<<"\n";
    d.erase(d.begin(),d.begin()+1);
    cout<<"After Erase"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<endl;
    }
    return 0;
}