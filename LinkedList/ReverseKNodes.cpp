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
Node* reverseK(Node* &head,int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        temp = curr;
        curr = curr->next;
        temp->next = prev;
        prev = temp;
        count++;
    }
    if(curr!=NULL){
    head->next = reverseK(curr,k);
    }
    return prev;
}
int main(){
    Node* head = NULL;
    AddAtHead(head,1);
    AddAtTail(head,2);
    AddAtTail(head,3);
    AddAtTail(head,4);
    AddAtTail(head,5);
    AddAtTail(head,6);
    display(head);
    Node* Nhead = reverseK(head,2);
    display(Nhead);
    return 0;
}