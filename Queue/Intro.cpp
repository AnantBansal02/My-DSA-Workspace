#include<iostream>
using namespace std;
#define n 100
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int val){
        if(back == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back] = val;
        if(front == -1){
            front++;
        }
    }
    void pop(){
        if(front == -1 || front>back){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front == -1 || front>back){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.empty()<<endl;
    for(int i=0;i<4;i++){
        cout<<q.peek()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<q.empty()<<endl;
    return 0;
}
