#include <iostream>
#include <vector>
#include <queue> // Required for levelOrder
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

// 🌿 Level Order Traversal (all nodes in one line)
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

// 🌳 Level Order Traversal (each level printed on a new line)
void levelOrderByLevel(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Level delimiter

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            cout << endl; // End of level
            if (!q.empty()) {
                q.push(NULL); // Add new delimiter
            }
        } else {
            cout << curr->data << " ";

            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }
    }
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    // Reset idx for buildTree
    idx = -1; 
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

    cout << "Level Order Traversal (Single Line): ";
    levelOrder(root);

    cout << "Level Order Traversal (By Level):" << endl;
    levelOrderByLevel(root);

    return 0;
}

