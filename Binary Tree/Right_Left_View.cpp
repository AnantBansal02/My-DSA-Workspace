#include<iostream>
#include<queue>
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
void Right_View(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){

        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            if(i == n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    cout<<endl;
}
void Left_View(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){

        int n = q.size();
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            if(i == 0){
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    cout<<endl;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(6);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);

    Right_View(root);
    Left_View(root2);
}