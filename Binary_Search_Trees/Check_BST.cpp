#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool Check_BST(Node* root, Node* min = NULL, Node* max = NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    bool leftValid = Check_BST(root->left, min, root);
    bool rightValid = Check_BST(root->right, root, max);
    if(leftValid && rightValid){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* root1 = new Node(8);
    root1->left = new Node(5);
    root1->right = new Node(11);
    if(Check_BST(root, NULL, NULL)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Invalid BST"<<endl;
    }
    if(Check_BST(root1, NULL, NULL)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Invalid BST"<<endl;
    }
}