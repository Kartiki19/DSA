#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        val = val;
        left = right = nullptr;
    }
};

int dfs(Node* root){
    if(root == nullptr) return 0;

    int left = dfs(root -> left);
    int right = dfs(root -> right);

    if(left == -1) return -1;
    if(right == -1) return -1;
    if(abs(left-right) > 1) return -1;

    return 1 + max(left, right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->left->left->left = new Node(25);
    root->left->left->left->right = new Node(30);
    root->right = new Node(2);
    root->right->right = new Node(9);

    cout << (dfs(root) != -1);
    return 0;
}

