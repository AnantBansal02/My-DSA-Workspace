#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void InsertAtTail(node* &head,int data){
    node* n = new node(data);
    if(head==NULL){
        head = n;
        return;
    }
    node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = n;
    n->prev = curr;
}
void InsertAtHead(node* &head,int data){
    node* n = new node(data);
    if(head==NULL){
        head = n;
        return;
    }
    head->prev = n;
    n->next = head;
    head = n;
}
void display(node* head){
    node* curr = head;
    while(curr->next!=NULL){
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr = curr->prev;
    }
    cout<<"NULL"<<endl;
}
void deleteatHead(node* &head){
    node* toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}
void deletion(node* &head,int pos){
    node* curr = head;
    if(head==NULL){
        cout<<"Nothing to Delete!"<<endl;
        return;
    }
    if (pos==1){
        deleteatHead(head);
        return;
    }
    int i=1;
    while(i!=pos && curr!=NULL){
        curr = curr->next;
        i++;
    }
    if(curr==NULL){
        cout<<"Position Out Of Bond "<<endl;
        return;
    }
    curr->prev->next = curr->next;
    if(curr->next!=NULL){
    curr->next->prev = curr->prev;
    }
    delete curr;
}
int main(){
    node* head = NULL;
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtHead(head,1);
    deletion(head,3);
    display(head);
    return 0;
}