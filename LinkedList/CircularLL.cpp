#include<iostream>
using namespace std;

class node{
public:
    node* next;
    int data;
    node(int val){
        data = val;
        next = NULL;
    }
};
void AddAtTail(node* &head,int data){
    node* n = new node(data);
    if(head == NULL){
        head = n;
        head->next=head;
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void AddAtHead(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        head->next = head;
        return;
    }
    n->next = head;
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    head = n;
}
void display(node* head){
    node* temp = head;
    while(temp->next!=head){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<temp->data<<endl;;
}
void deletion(node* &head,int pos){
    if(pos==1){
        node* todelete = head;
        node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        delete todelete;
        return;
    }
    node* curr = head;
    int count = 1;
    while(count!=pos-1){
        curr = curr->next;
        count++;
    }
    node* todelete;
    curr->next = curr->next->next;
    delete todelete;
}
int main(){
    node* head=NULL;
    AddAtTail(head,1);
    AddAtTail(head,2);
    AddAtTail(head,3);
    AddAtTail(head,4);
    AddAtTail(head,5);
    AddAtTail(head,6);
    display(head);
    deletion(head,3);
    display(head);
    return 0;
}