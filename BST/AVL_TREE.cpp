#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;   // if there is no node, height is 0
    }
    else {
        return node->height; // otherwise return its stored height
    }
}


int getBalance(Node* node) {
    if (node == NULL) {
        return 0;   // If no node, balance factor is 0
    }
    else {
        // Balance = height of left subtree - height of right subtree
        return getHeight(node->left) - getHeight(node->right);
    }
}


// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Get the minimum value node
Node* getMinValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
Node*getInOrderSuccessor(Node*root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Insert a node
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// Delete a node
Node*deleteNode(Node*root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(key < root->data)
    {
       root->left =  deleteNode(root->left,key);
    }else if (key > root->data)
    {
        root->right =  deleteNode(root->right,key);
    }else
    {
        //key == root
        if(root->left == NULL)
        {
            Node*temp = root->right;
            delete root;
            return temp;
            
        }else if (root->right == NULL)
        {
            Node*temp = root->left;
            delete root;
            return temp;//both cases 0 child and  1 child done
        } else
        {
            Node*IS = getInOrderSuccessor(root->right); 
            root->data = IS->data;
            root->right = deleteNode(root->right,IS->data); 
        }

    }

    // If the tree had only one node
    if (root == NULL)
        return root;
        
    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balance the tree

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Search
bool AVLsearch(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return AVLsearch(root->left, key);
    return AVLsearch(root->right, key);
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
} 
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Deleting 40..." << endl;
    root = deleteNode(root, 40);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Search 25: " << (AVLsearch(root, 25) ? "Found" : "Not Found") << endl;
}
