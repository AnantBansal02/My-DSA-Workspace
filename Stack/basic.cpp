#include<iostream>
using namespace std;
#define n 100
class stack{
    int* arr;
    int idx;
    public:
    stack(){
        arr = new int[n];
        idx = -1;
    }
    void push(int value){
        if(idx==n-1){
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        idx++;
        arr[idx] = value;
    }
    int pop(){
        if(idx==-1){
            cout<<"No Element to Pop!"<<endl;
            return -1;
        }
        int ans = arr[idx];
        idx--;
        return ans;
    }
    int top(){
        if(idx==-1){
            cout<<"No Element to Display!"<<endl;
            return -1;
        }
        return arr[idx];
    }
    bool empty(){
        return idx==-1;
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
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    return 0;
}