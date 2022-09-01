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
Node* insertBST(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
    return root;
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root = NULL;
    root = insertBST(root,5);
    int arr[] = {1,3,4,2,7};
    for(int i=0;i<5;i++){
        insertBST(root,arr[i]);
    }
    inorder(root);
    return 0;
} 