#include<iostream>
#include<algorithm>
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
int calHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight = calHeight(root->left); 
    int rHeight = calHeight(root->right); 
    return max(lHeight,rHeight) + 1;
}
int calDiameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lheight = calHeight(root->left);
    int rheight = calHeight(root->right);
    int currDiameter = lheight + rheight + 1;
    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);
    return max(currDiameter,max(lDiameter,rDiameter));
}
int calDia(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDia = calDia(root->left,&lh);
    int rdia = calDia(root->right,&rh);
    int currDia = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDia,max(lDia,rdia)); 
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calHeight(root)<<endl;
    int h = 0;
    cout<<calDia(root,&h);
}