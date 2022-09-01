#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);
    cout<<dq.front()<<endl;
    for(auto i:dq){
        cout<<i<<" ";
    }
    return 0;
}
