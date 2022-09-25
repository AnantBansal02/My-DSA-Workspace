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
int util(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }
    int left = util(root->left , ans);
    int right = util(root->right , ans);

    int nodemax = max(max(root->data, root->data + left + right),max(root->data + left, root->data + right));
    ans = max(ans,nodemax);
    return max(root->data,max(root->data+left,root->data+right));
}
int maxsumpath(Node*root){
    int ans = INT_MIN;
    util(root,ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout<<maxsumpath(root)<<endl;
}