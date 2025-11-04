#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

// Function to create a new node
node* createNode(int val) {
    node* newNode = new node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a tree is a valid BST
bool isBST(node* root, node* minNode, node* maxNode) {
    if (root == NULL)
        return true;

    if (minNode != NULL && root->val <= minNode->val)
        return false;

    if (maxNode != NULL && root->val >= maxNode->val)
        return false;

    return isBST(root->left, minNode, root) &&
           isBST(root->right, root, maxNode);
}

int main() {
    /*
           5
          / \
         3   7
        / \   \
       2   4   8
    */

    node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(8);

    if (isBST(root, NULL, NULL))
        cout << "The tree is a valid BST." << endl;
    else
        cout << "The tree is NOT a valid BST." << endl;

    return 0;
}
