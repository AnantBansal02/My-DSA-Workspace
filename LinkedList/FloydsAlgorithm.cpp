//Also called as Hare and Tortoise Algorithm
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
void makeCycle(Node* head,int pos){
    Node* temp=head;
    Node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}
void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            fast = head;
            break;
        }
    }
    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    cout<<detectCycle(head)<<endl;
    makeCycle(head,3);cout<<"Made Cycle!"<<endl;
    cout<<detectCycle(head)<<endl;
    removeCycle(head);cout<<"Removed Cycle!"<<endl;
    cout<<detectCycle(head)<<endl;
    display(head);
    return 0;
}