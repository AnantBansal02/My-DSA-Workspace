#include<bits/stdc++.h>
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
Node* Build_From_Preorder(int arr[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key>min and key<max){
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root->left = Build_From_Preorder(arr, preorderIdx, arr[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n){
            root->right = Build_From_Preorder(arr, preorderIdx, arr[*preorderIdx], key, max, n);
        }
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
    int arr[] = {10,2,1,13,11};
    int n = 5;
    int preorderIdx = 0;
    Node* root = Build_From_Preorder(arr, &preorderIdx, arr[0], INT_MIN, INT_MAX, n);
    inorder(root);
}