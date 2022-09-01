#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int in[],int start,int end,int key){
    int i=start;
    while(i<=end){
        if(in[i]==key){
            return i;
        }
        i++;
    }
    return -1;
}
Node* buildTree(int post[],int in[],int start,int end){
    static int idx = 4;
    if(start>end){
        return NULL;
    }
    int curr = post[idx];
    idx--;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = search(in,start,end,curr);
    node->right = buildTree(post,in,pos+1,end);
    node->left = buildTree(post,in,start,pos-1);
    return node;
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
    int post[] = {4,2,5,3,1};
    int in[] = {4,2,1,5,3};
    Node *n = buildTree(post,in,0,4);
    inorder(n);
    return 0;
}