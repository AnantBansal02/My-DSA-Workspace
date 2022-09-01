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
int main(){
    return 0;
}