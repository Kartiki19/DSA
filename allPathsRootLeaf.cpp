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

void displayV(const vector<vector<int>>& v){
    for(auto it : v){
        for(int i: it)
            cout << i <<  "\t";
        cout << endl;
    }
    cout << endl;
}

void printPath(const vector<int>& path){
    for(int i = path.size()-1; i >= 0; i--){
        cout << path[i] << "\t";
    }
    cout << endl;
}

void printRootToNodePath(const vector<int>& path){
    for(int i = 0; i < path.size(); ++i){
        cout << path[i] << "\t";
    }
    cout << endl;
}

void findLeafPaths(Node* root, vector<int>& path){
    if(root == nullptr) return;
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr)
        printRootToNodePath(path);
    else{
        findLeafPaths(root->left, path);
        findLeafPaths(root->right, path);
    }
    path.pop_back();
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
    findLeafPaths(root, output);
    return 0;
}
