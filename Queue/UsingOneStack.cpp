#include<iostream>
#include<stack>
using namespace std;

class que{
    stack<int> s1;
    public:
    void push(int val){
        s1.push(val);
    }
    int pop(){
        if(s1.empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int ele = pop();
        s1.push(x);
        return ele;
    }
    bool empty(){
        if(s1.empty()){
            return 1;
        }
        return 0;
    }
};
int main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        cout<<q.pop()<<" ";
    }cout<<endl;
    // cout<<q.pop();
    return 0;
}