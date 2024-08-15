#include<iostream>
using namespace std;

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

int maxPathSum(Node* root, int& ans){
    if(root == nullptr) return 0;

    int left = max(0,maxPathSum(root->left, ans));
    int right = max(0,maxPathSum(root->right, ans));

    ans = max(ans, root->val+left + right);

    return root->val + max(left,right);
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int answer = INT_MIN;
    maxPathSum(root, answer);

    cout << answer << endl;
    return 0;
}