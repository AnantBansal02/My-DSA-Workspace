#include<bits/stdc++.h>
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
Node* buildTree(int pre[],int in[],int start,int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = search(in,start,end,curr);
    node->left = buildTree(pre,in,start,pos-1);
    node->right = buildTree(pre,in,pos+1,end);
    return node;
}
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    int pre[] = {1,2,4,3,5};
    int in[] = {4,2,1,5,3};
    Node* n = buildTree(pre,in,0,4);
    postorder(n);
    return 0;

}