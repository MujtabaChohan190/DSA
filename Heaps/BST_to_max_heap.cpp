#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// ---------------- REVERSE ARRAY (using swap) ----------------
void reverseArray(int arr[], int n) {
    int i = 0;
    int j = n - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}


// ---------------- BST INSERTION ----------------
Node* insertBST(Node* root, int val) {
    if (root == nullptr)
        return createNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// ---------------- INORDER TRAVERSAL (GIVES ASCENDING SORTED ARRAY) ----------------
void inorderTraversal(Node* root, int arr[], int &index) {
    if (!root) return;
    inorderTraversal(root->left, arr, index);
    arr[index++] = root->data;
    inorderTraversal(root->right, arr, index);
}

// ---------------- PREORDER FILL (FILL TREE WITH ARRAY VALUES) ----------------
void preorderFill(Node* root, int arr[], int &index) {
    if (!root) return;
    root->data = arr[index++];
    preorderFill(root->left, arr, index);
    preorderFill(root->right, arr, index);
}

// ---------------- CONVERT TREE SHAPE INTO HEAP ARRAY ----------------
void fillHeapArray(Node* root, int heapArr[], int index) {
    if (!root) return;
    heapArr[index] = root->data;
    fillHeapArray(root->left, heapArr, 2 * index);
    fillHeapArray(root->right, heapArr, 2 * index + 1);
}

int main() {

    Node* root = nullptr;

    // ------- BUILD BST USING insertBST -------
    int values[] = {4, 2, 6, 1, 3, 5, 7};
    int n = 7;

    for (int i = 0; i < n; i++) {
        root = insertBST(root, values[i]);
    }

    // ----------- BST READY -------------

    int* sortedArr = new int[n];
    int index = 0;

    // Step 1: inorder → sorted ascending array
    inorderTraversal(root, sortedArr, index);

    // Step 2: Reverse → descending for MAX HEAP
    reverseArray(sortedArr, n);

    // Step 3: Preorder fill to assign max heap values
    index = 0;
    preorderFill(root, sortedArr, index);

    // Step 4: Convert tree to heap array representation
    int* heapArr = new int[n + 1];
    for (int i = 0; i <= n; i++) heapArr[i] = -1;

    fillHeapArray(root, heapArr, 1);

    cout << "\nMax Heap Array:\n";
    for (int i = 1; i <= n; i++)
        cout << heapArr[i] << " ";
    cout << endl;

    delete[] sortedArr;
    delete[] heapArr;

    return 0;
}
