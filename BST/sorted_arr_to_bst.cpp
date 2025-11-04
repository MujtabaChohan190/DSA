#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build BST from sorted array
Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;  // middle element becomes root
    Node* root = createNode(arr[mid]);

    // Recursively build left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Inorder traversal to verify BST
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = sortedArrayToBST(arr, 0, n - 1);

    cout << "Inorder of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
