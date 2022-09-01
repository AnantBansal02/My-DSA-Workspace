#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int val){
        q2.push(val);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int pop(){
        if(q1.empty()){
            cout<<"Stack is Empty!";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    int top(){
        if(q1.empty()){
            cout<<"Stack is Empty!";
            return -1;
        }
        return q1.front();
    }
    bool empty(){
        if(q1.empty()){
            return 1;
        }
        return 0;
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.empty()<<endl;
    cout<<st.pop()<<" ";
    cout<<st.pop()<<" ";
    cout<<st.pop()<<" ";
    cout<<st.pop()<<" ";
    cout<<st.pop()<<endl;;
    cout<<st.empty()<<endl;
    return 0;
}