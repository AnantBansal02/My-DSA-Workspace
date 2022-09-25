#include<iostream>
#include<vector>
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
bool getpath(Node*root,int key,vector<int> &v){
    if(root == NULL){
        return false;
    }
    v.push_back(root->data);
    if(root->data == key){
        return true;
    }
    if(getpath(root->left,key,v) || getpath(root->right,key,v)){
        return true;
    }
    v.pop_back();
    return false;
}
int LCA(Node* root,int n1,int n2){
    vector<int> path1;
    vector<int> path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc = 0; pc < path1.size() && path2.size(); pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}

Node* LCA2(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA2(root->left,n1,n2);
    Node* right = LCA2(root->right,n1,n2);

    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA2(root->left,n1,n2);
    }
    return LCA2(root->right,n1,n2);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    int n1 = 7;
    int n2 = 6;
    Node* lcaa = LCA2(root,n1,n2);
    if(lcaa == NULL){
        cout<<"LCA doesn't exist!"<<endl;
    }
    else
    cout<<"LCA : "<<lcaa->data<<endl;
    return 0;
}