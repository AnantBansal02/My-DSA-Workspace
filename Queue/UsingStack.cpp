#include<iostream>
#include<stack>
using namespace std;

class que{
    stack<int> s1;
    stack<int> s2;
    public:
    que(){

    }
    void push(int val){
        s1.push(val);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    int peek(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        return ans;
    }
    bool empty(){
        if(s1.empty() && s2.empty()){
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