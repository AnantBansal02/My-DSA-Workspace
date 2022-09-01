#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void AddAtTail(Node* &head,int data){
    Node* n = new Node(data);
    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while((temp->next)!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void AddAtHead(Node* &head,int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}
bool search(Node* head,int val){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void deletion(Node* &head,int val){
    Node* temp = head;
    if(temp->data == val){
        Node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    temp = temp->next;
    Node* beforeTemp = head;
    while(temp!=NULL){
        if(temp->data == val){
            Node* todelete = temp;
            beforeTemp->next = beforeTemp->next->next;
            delete temp;
            return;
        }
        temp = temp->next;
        beforeTemp = beforeTemp->next;
    }
}
int length(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* kappend(Node* &head,int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;
    int l = length(head);
    int count = 1;
    while(tail->next!=NULL){
        if(count==(l-k)){
            newTail = tail;
        }
        if(count==(l-k+1)){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    tail->next = head;
    newTail->next = NULL;
    return newHead;
}
int main(){
    Node* head = NULL;
    for(int i=1;i<=6;i++){
        AddAtTail(head,i);
    }
    display(head);
    Node* newHead = kappend(head,3);
    display(newHead);
    return 0;
}