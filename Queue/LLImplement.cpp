#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class queue{
    public:
    node* front;
    node* back;
    queue(){
        front = NULL;
        back = NULL;
    }
    void push(int val){
        node* n = new node(val);
        if(front==NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        node* toDelete = front;
        front = front->next;
        delete toDelete;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
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