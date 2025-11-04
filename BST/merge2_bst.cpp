#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}
// Store inorder traversal in array
void inorder(Node* root, int arr[], int& index) {
    if (root == NULL) return;
    inorder(root->left, arr, index);
    arr[index++] = root->data;
    inorder(root->right, arr, index);
}

//now we have to merge two inorder arrays
// Merge two sorted arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int& mergedSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < size1)
        merged[k++] = arr1[i++];
    while (j < size2)
        merged[k++] = arr2[j++];
    mergedSize = k; //mergedsize is here bcs in end when we have to make sortedarr to bst function we pass merged size as end parameter to tell where the sorted array ends
  
}

// Build balanced BST from sorted array
Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node* root = createNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

//Merge array function is to coordinate everything like first store inorderder traversal of tree into array then do merge array then make sorted array to bst
// Merge two BSTs into one balanced BST
Node* mergeBSTs(Node* root1, Node* root2) {
    int arr1[100], arr2[100], merged[200];
    int index1 = 0, index2 = 0, mergedSize = 0;

    // Step 1: Get inorder traversals
    inorder(root1, arr1, index1);
    inorder(root2, arr2, index2);

    // Step 2: Merge the two sorted arrays
    mergeArrays(arr1, index1, arr2, index2, merged, mergedSize);

    // Step 3: Convert merged sorted array to a balanced BST
    return sortedArrayToBST(merged, 0, mergedSize - 1);
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    // BST 1
    root1 = insert(root1, 30);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);
    root1 = insert(root1, 10);

    // BST 2
    root2 = insert(root2, 25);
    root2 = insert(root2, 35);
    root2 = insert(root2, 50);

    // Merge both BSTs
    Node* mergedRoot = mergeBSTs(root1, root2);
    
    return 0;
}
