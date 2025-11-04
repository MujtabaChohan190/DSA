#include <iostream>
#include <queue>
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

int idx = -1; // Global index

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

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level Order (Single Line)
void levelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); 
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

// Level Order (Each Level New Line)
void levelOrderByLevel(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
        } else {
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

int main() {

    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int n = sizeof(preorder)/sizeof(preorder[0]);

    idx = -1;
    Node* root = buildTree(preorder, n);

    cout << "Preorder Traversal:  ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal:   ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Level Order (Single Line): ";
    levelOrder(root);

    cout << "Level Order (By Level):" << endl;
    levelOrderByLevel(root);

    return 0;
}

