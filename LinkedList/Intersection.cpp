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
void intersect(Node* &head1,Node* &head2,int pos){
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(Node* &head1,Node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    
    int d=0;
    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d){
        if(ptr1==NULL){
            return -1;
        }
        ptr1 = ptr1->next;
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;
}
int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    AddAtTail(head1,1);
    AddAtTail(head1,2);
    AddAtTail(head1,3);
    AddAtTail(head1,4);
    AddAtTail(head1,5);
    AddAtTail(head1,6);
    AddAtTail(head2,9);
    AddAtTail(head2,10);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2)<<endl;
    return 0;
}