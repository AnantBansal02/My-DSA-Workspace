#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int val){
        q1.push(val);
    }
    int pop(){
        if(q1.empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int top(){
        if(q1.empty()){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    bool empty(){
        return q1.empty();
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