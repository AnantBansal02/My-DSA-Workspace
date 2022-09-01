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
Node* merge(Node* &head1,Node* &head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* Dummy = new Node(-1);
    Node* ptr3 = Dummy;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }       
    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return Dummy->next;
}
Node* mergeRecursion(Node* &head1,Node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursion(head1->next,head2);
    }
    else{
        result = head2;
        result->next = mergeRecursion(head1,head2->next);
    }
    return result;
}
int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    AddAtTail(head1,1);
    AddAtTail(head1,4);
    AddAtTail(head1,5);
    AddAtTail(head1,7);
    AddAtTail(head2,2);
    AddAtTail(head2,3);
    AddAtTail(head2,6);
    display(head1);
    display(head2);
    // Node *head3 = merge(head1,head2);
    Node *head3 = mergeRecursion(head1,head2);
    display(head3);
    return 0;
}