#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

// Inorder Traversal (Print in sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find Inorder Successor (minimum value node in right subtree)
Node* getInorderSuccessor(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from BST
Node* delNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = delNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = delNode(root->right, key);
    }
    else {
        // Node found

        // Case 1: No left child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: No right child
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* IS = getInorderSuccessor(root->right); 
            root->data = IS->data; // Replace
            root->right = delNode(root->right, IS->data); // Remove duplicate
        }
    }

    return root;
}

int main() {

    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, n);

    cout << "before : ";
    inorder(root);
    cout << endl;

    root = delNode(root, 6);

    cout << "after : ";
    inorder(root);
    cout << endl;

    return 0;
}
