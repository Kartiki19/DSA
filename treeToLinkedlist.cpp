#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;

    node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void binaryTreeToDoublyLinkedlist(node* root, node*& head){
    if(root == nullptr) return;

    static node* prev = nullptr;

    binaryTreeToDoublyLinkedlist(root->left, head);

    if(prev == nullptr) head = root;
    else{
        prev -> right = root;
        root -> left = prev;
    }
    prev = root;

    binaryTreeToDoublyLinkedlist(root->right, head);

}

void printLinkedList(node* head){
    node* curr = head;
    while(curr != nullptr) {
        cout << curr->val << ", ";
        curr = curr->right;
    }
    cout << endl;
}
int main(){

    /// Tree Creation;
    node* root = new node(10);
    root -> left = new node(12);
    root -> right = new node(15);
    root -> left -> left = new node(25);
    root -> left -> right = new node(30);
    root -> right -> left = new node(36);

    node* head = nullptr;

    binaryTreeToDoublyLinkedlist(root, head);
    printLinkedList(head);

    return 0;
}