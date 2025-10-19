#include <iostream>
#include <vector>
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

static int idx = -1;

Node* buildTree(vector<int> preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Reset idx for buildTree since main might be called multiple times in some environments
    idx = -1;  //nor part if single traversal
    Node* root = buildTree(preorder);

    cout << "Preorder Traversal:  ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal:   ";
    inorder(root);
    cout << endl;
    
    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
