#include<iostream>
#include<queue>
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

Node* Build_From_Array(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = start + (end - start)/2;
    Node* root = new Node(arr[mid]);
    root->left = Build_From_Array(arr, start, mid-1);
    root->right = Build_From_Array(arr, mid+1, end);
    return root;
}
void Preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Print_Level_Order(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        if(n != NULL){
            cout<<n->data<<" ";
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    Node* root = Build_From_Array(arr,0,8);
    Print_Level_Order(root);
    cout<<endl;
    Preorder(root);
}