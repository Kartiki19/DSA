#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int value){
        val = value;
        left = right = nullptr;
    }
};

int diameter(Node* root, int& ans){
    if(root == nullptr) return 0;

    int left = diameter(root->left, ans);
    int right = diameter(root->right, ans);

    ans = max(ans, left + right);

    return 1 + max(left,right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    int answer = INT_MIN;
    diameter(root, answer);

    cout << answer << endl;
    return 0;
}