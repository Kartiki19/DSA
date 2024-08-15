#include<iostream>
#include<queue>
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

int maxDepth(Node* root){
    if(root == nullptr) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left, right);
}

int maxWidth(Node* root){
    if(root == nullptr) return 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int ans = INT_MIN;

    while(!q.empty()){
        int mmin = q.front().second;

        int len = q.size();
        int first = 0;
        int last = 0;

        for(int i = 0; i < len; ++i){
            Node* curr = q.front().first;
            int id = q.front().second - mmin;
            q.pop();
            if(i == 0) first = id;
            if(i == len-1) last = id;

            if(curr->left) q.push({curr->left, 2*id+1});
            if(curr->right) q.push({curr->right, 2*id+2});

            ans = max(ans, last - first + 1);
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(9);

    cout << "\nMaximum height / depth of the tree is: " << maxDepth(root) << endl;
    cout << "\nMaximum width of the tree is: " << maxWidth(root) << endl;
    return 0;
}

