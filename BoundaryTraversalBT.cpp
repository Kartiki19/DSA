#include<iostream>
#include<vector>
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

void displayV(const vector<int>& v){
    for(int i : v){
        cout << i <<  "\t";
    }
    cout << endl;
}

bool isLeaf(Node* node){
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

void getLeftBoundary(Node* root, vector<int>& output, bool isBoundary){
    if(root != nullptr){
        if(isBoundary || isLeaf(root)) output.push_back(root->val);
        getLeftBoundary(root->left, output, isBoundary);
        getLeftBoundary(root->right, output, isBoundary && root->left == nullptr);
    }
}

void getRightBoundary(Node* root, vector<int>& output, bool isBoundary){
    if(root != nullptr){
        getRightBoundary(root->left, output, isBoundary && root->right == nullptr);
        getRightBoundary(root->right, output, isBoundary);
        if(isLeaf(root) || isBoundary) output.push_back(root->val);
    }
}

void boundaryBT(Node* root, vector<int>& output){
    
    if(root == nullptr) return;
    
    output.push_back(root->val);
    getLeftBoundary(root->left, output, true);
    getRightBoundary(root->right, output, true);
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

    vector<int> output;
    boundaryBT(root, output);

    displayV(output);
    return 0;
}

