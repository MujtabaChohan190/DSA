#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int idx = -1;

// Build Tree from Preorder Array with -1 as NULL
Node* buildTree(int preorder[], int n) {
    idx++;
    if (idx >= n || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, n);
    root->right = buildTree(preorder, n);

    return root;
}

// Check if Two Trees are Identical
bool isIdentical(Node* root1, Node* root2) {

    // If both are empty
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // If one is empty but not the other
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check root & both subtrees
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Simple Preorder Display (Optional)
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Tree 1
    int preorder1[] = {1, 2, -1, -1, 3, -1, -1};
    int n1 = sizeof(preorder1)/sizeof(preorder1[0]);

    // Tree 2
    int preorder2[] = {1, 2, -1, -1, 3, -1, -1};
    int n2 = sizeof(preorder2)/sizeof(preorder2[0]);

    // Build trees
    idx = -1;
    Node* root1 = buildTree(preorder1, n1);

    idx = -1;
    Node* root2 = buildTree(preorder2, n2);

    // Display (optional)
    cout << "Tree 1 Preorder: ";
    preOrder(root1);
    cout << endl;

    cout << "Tree 2 Preorder: ";
    preOrder(root2);
    cout << endl;

    // Check identical
    if (isIdentical(root1, root2)) {
        cout << "✅ Trees are Identical" << endl;
    } else {
        cout << "❌ Trees are NOT Identical" << endl;
    }

    return 0;
}
