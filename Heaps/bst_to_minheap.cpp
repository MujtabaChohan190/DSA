#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to recursively traverse the BST in-order.
// This stores all node data into an array in sorted (ascending) order.
void inorderTraversal(Node* root, int arr[], int &index) {
    if (!root) return;
    inorderTraversal(root->left, arr, index);
    arr[index++] = root->data;
    inorderTraversal(root->right, arr, index);
}

// It populates the tree's data fields using the sorted elements from the array.
// Since Preorder visits the parent first, this ensures the Min Heap property (Parent <= Children).
void preorderFill(Node* root, int arr[], int &index) {
    if (!root) return;
    root->data = arr[index++];
    preorderFill(root->left, arr, index);
    preorderFill(root->right, arr, index);
}

// Function to traverse the tree structure (which now holds Min Heap data)
// and map its elements into a standard array-based Min Heap representation.
// It uses the heap property: children of index i are at 2*i and 2*i + 1.

void fillHeapArray(Node* root, int heapArr[], int index) {
    if (!root) return;
    heapArr[index] = root->data;
    fillHeapArray(root->left, heapArr, 2 * index);
    fillHeapArray(root->right, heapArr, 2 * index + 1);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int n = 7;
    int* sortedArr = new int[n]; 
    int index = 0;
  //with this we inorder traverse the bst and get sorted array
    inorderTraversal(root, sortedArr, index);

    index = 0;
  //with this we populate the tree with preorder hence satisfying min heap proporty of parent <= child 
    preorderFill(root, sortedArr, index);

    int* heapArr = new int[n + 1]; 
    for (int i = 0; i <= n; i++) heapArr[i] = -1;
//with this , we traverse the tree structure and fill it into array ensruing min heap representation
    fillHeapArray(root, heapArr, 1);

    for (int i = 1; i <= n; i++)
        cout << heapArr[i] << " ";
    cout << endl;

    delete[] sortedArr;
    delete[] heapArr;

    return 0;
}
